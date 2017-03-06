#include "./map.hpp"
#include "util.hpp"
#include "constants.hpp"
#include <iostream>
#include "engine/game.hpp"

// helpers for abusing template functions violently

using namespace Terrain;

inline Pair const& getEcbSideRight(Ecb const& e) {
    return e.right;
}

inline void setEcbSideRight(Ecb& e, Pair pos) {
    return e.setRight(pos);
}

inline Pair const& getEcbSideLeft(Ecb const& e) {
    return e.left;
}

inline void setEcbSideLeft(Ecb& e, Pair pos) {
    return e.setLeft(pos);
}

inline Pair const& getEcbBottom(Ecb const& e) {
    return e.bottom;
}

inline Pair const& getEcbTop(Ecb const& e) {
    return e.top;
}

inline void setEcbTop(Ecb& e, Pair const pos) {
    return e.setTop(pos);
}

inline double getX(Pair const& pos) {
    return pos.x;
}

inline double getY(Pair const& pos) {
    return pos.y;
}

inline void setX(Pair& pos, double val) {
    pos.x = val;
}

inline void setY(Pair& pos, double val) {
    pos.y = val;
}

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges){};

bool Map::getClosestCollision(Pair const& start,
                              Pair const& end,
                              CollisionDatum& out,
                              Platform* ignoredCollision) {
    double closestDist = DOUBLE_INFINITY;
    PlatformSegment segment;
    Pair collisionPoint;
    bool anyCollision = false;

    for (Platform& p : platforms) {
        if (&p == ignoredCollision)
            continue;

        TerrainCollisionType t =
            p.checkCollision(start, end, collisionPoint, segment);

        double distance = (collisionPoint - start).euclid();
        if (t != NO_COLLISION && distance < closestDist) {
            closestDist = distance;
            out.type = t;
            out.segment = segment;
            out.position = collisionPoint;
            anyCollision = true;
        }
    }

    return anyCollision;
}

bool Map::getClosestEdgeCollision(Pair const& a1,
                                  Pair const& a2,
                                  Pair const& b1,
                                  Pair const& b2,
                                  EdgeCollision& collision) {
    for (Platform& platform : platforms) {
        if (platform.checkEdgeCollision(a1, a2, b1, b2, collision)) {
            return true;
        }
    }

    return false;
}

void basicProjection(Player& player,
                     Pair& requestedDistance,
                     Pair& projectedPosition) {
    if (player.isGrounded()) {
        // move player along platform
        projectedPosition = player.position;
        player.getCurrentPlatform()->groundedMovement(projectedPosition,
                                                      requestedDistance);

        if (requestedDistance.euclidSquared() > 0) {
            player.fallOffPlatform();
        }

        // add remaining distnace (for falling)
        projectedPosition += requestedDistance;
    }

    // if the player is not grounded, just move them according to requested
    // movement
    else {
        projectedPosition = player.position + requestedDistance;
    }
}

/** Adjusts the projected ecb's position
 *
 * Takes the difference between the nestStepEcb and the position that the ecb
 * would be in at equivalend y() had no collision occured, and applies that
 * difference to projectedEcb.
 *
 */
template <double (*x)(Pair const& pos), double (*y)(Pair const& pos)>
void rollback(Player const& player,
              Ecb const& currentEcb,
              Ecb const& nextStepEcb,
              Ecb& projectedEcb) {
    // move the goal back by taking the X difference between the
    // position without collision at the new Y and the position
    // after wall sliding

    // get the relative positions of the destination with and
    // without collision
    Pair relPosNoColl = projectedEcb.origin - currentEcb.origin;
    Pair relPosColl = nextStepEcb.origin - currentEcb.origin;

    if (y(relPosNoColl) == 0 || player.isGrounded()) {
        std::cout << "rollback grounded " << nextStepEcb << std::endl;
        projectedEcb.setOrigin(nextStepEcb.origin);
    } else {
        relPosNoColl *= y(relPosColl) / y(relPosNoColl);

        std::cout << relPosNoColl << " " << relPosColl << std::endl;

        double noCollisionDistance = x(relPosColl) - x(relPosNoColl);

        std::cout << "noCollisionDistance " << noCollisionDistance << std::endl;

        Pair rollbackPosition =
            projectedEcb.origin + Pair(noCollisionDistance, 0);

        std::cout << "rollback position: " << rollbackPosition << std::endl;

        // update the player position and projected ECB
        projectedEcb.setOrigin(rollbackPosition);
    }
}

/** Perform a collision with the wall
 *
 */
template <Pair const& (*getEcbSide)(Ecb const&),
          void (*setEcbSide)(Ecb&, Pair const pos),
          double (*x)(Pair const& pos),
          double (*y)(Pair const& pos),
          void (*setNonblockingAxis)(Pair& pos, double value)>
bool Map::performWallCollision(Player const& player,
                               const Pair expectedDirection,
                               Ecb const& currentEcb,
                               Ecb& nextStepEcb,
                               Ecb& projectedEcb,
                               double& distance) {
    CollisionDatum collision;

    // ignore collision if the collision is coming from the wrong direction
    if (Dot((projectedEcb.origin - currentEcb.origin), expectedDirection) < 0) {
        return false;
    }

    Ecb _currentEcb = currentEcb;
    if (!getClosestCollision(getEcbSide(_currentEcb), getEcbSide(projectedEcb),
                             collision, NULL)) {
        return false;
    }

    distance = (getEcbSide(currentEcb) - collision.position).euclid();

    std::cout << "colliding with wall " << collision.segment.getPlatform()
              << " at " << collision.position << std::endl;

    Pair wallSlidePosition = collision.position;

    // perform sliding if the player is not grounded
    if (!player.isGrounded()) {
        double directionY = y(projectedEcb.origin) - y(_currentEcb.origin);
        double slidePosition =
            (directionY > 0)
                ? std::min(std::max(y(*collision.segment.secondPoint()),
                                    y(*collision.segment.firstPoint())),
                           y(getEcbSide(projectedEcb)))
                : std::max(std::min(y(*collision.segment.secondPoint()),
                                    y(*collision.segment.firstPoint())),
                           y(getEcbSide(projectedEcb)));

        setNonblockingAxis(wallSlidePosition, slidePosition);
    }

    std::cout << "position after sliding " << wallSlidePosition << std::endl;

    // slide the ecb along the wall
    setEcbSide(nextStepEcb, wallSlidePosition);

    std::cout << "ecbs " << currentEcb.origin << ".." << projectedEcb.origin
              << std::endl;

    if (std::abs(y(currentEcb.origin) - y(nextStepEcb.origin)) <
            COLLISION_EPSILON &&
        std::abs(y(currentEcb.origin) - y(projectedEcb.origin)) >
            COLLISION_EPSILON &&
        !player.isGrounded()) {
        std::cout << "ignoring wall collision: player is not grounded and the "
                     "y difference is zero";
        return false;
    }

    rollback<x, y>(player, currentEcb, nextStepEcb, projectedEcb);
    return true;
}

class Line {
   public:
    Pair start;
    Pair end;
    Line(){};
    Line(Pair start, Pair end) : start(start), end(end){};
};

template <Pair const& (*getForwardEdge)(Ecb const&),
          Pair const& (*getBackEdge)(Ecb const&),
          void (*setForwardEdge)(Ecb&, Pair const pos)>
bool Map::performWallEdgeCollision(Player const& player,
                                   Ecb const& currentEcb,
                                   Ecb& nextStepEcb,
                                   Ecb& projectedEcb,
                                   double& distance) {
    Pair currentForward = getForwardEdge(currentEcb);
    Pair currentBack = getBackEdge(currentEcb);

    Pair projectedForward = getForwardEdge(projectedEcb);
    Pair projectedBack = getBackEdge(projectedEcb);

    Pair move = projectedForward - currentForward;

    // std::cout << "current ecb: " << *currentEcb << std::endl;
    // std::cout << "projected ecb: " << *projectedEcb << std::endl;

    // std::cout << "currentForward: " << currentForward << std::endl;
    // std::cout << "currentBack: " << currentBack << std::endl;
    // std::cout << "projectedForward: " << projectedForward << std::endl;
    // std::cout << "projectedBack: " << projectedBack << std::endl;

    // std::cout << "line: " << line << std::endl;
    // std::cout << "move: " << move << std::endl;

    if (move == Pair(0, 0))
        return false;

    Line currentEdge, projectedEdge;
    EdgeCollision collision;
    if ((currentForward.y > currentBack.y)) {
        currentEdge = Line(currentBack, currentForward);
        projectedEdge = Line(projectedBack, projectedForward);

        if (!getClosestEdgeCollision(currentEdge.start, currentEdge.end,
                                     projectedEdge.start, projectedEdge.end,
                                     collision)) {
            return false;
        }

        setForwardEdge(nextStepEcb, collision.collisionLine2);

    } else {
        currentEdge = Line(currentForward, currentBack);
        projectedEdge = Line(projectedForward, projectedBack);

        if (!getClosestEdgeCollision(currentEdge.start, currentEdge.end,
                                     projectedEdge.start, projectedEdge.end,
                                     collision)) {
            return false;
        }

        setForwardEdge(nextStepEcb, collision.collisionLine1);
    }

    Pair collisionPoint = collision.cornerPosition;
    Pair collisionLine1 = collision.collisionLine1;
    Pair collisionLine2 = collision.collisionLine2;

    distance = (collisionLine1 - currentEdge.start).euclid();

    std::cout << "collide with corner " << collisionPoint << std::endl;
    std::cout << "collision line  " << collisionLine1 << ".." << collisionLine2
              << std::endl;

    // perform vertical sliding if the player is not grounded
    if (!player.isGrounded()) {
        // we want to slide this edge of the ecb along the point. It can slide
        //
        // - the remaining length of the ecb side
        // - until the Y of the projected point is the same as the Y of  slid
        //   point
        //

        // direction of slide is determined by:
        // if the angle between the direction of the side and the
        // angle of motion is > 90 degrees, we slide backwards. Otherwise.
        // we slide forwards
        double dot = Dot(move, currentEdge.end - currentEdge.start);

        std::cout << collisionLine1 << std::endl;
        std::cout << collisionPoint << std::endl;
        std::cout << collisionLine2 << std::endl;

        Pair slide = (dot < 0) ? collisionPoint - collisionLine2
                               : collisionPoint - collisionLine1;

        // if the direction of sliding is into the platform, don't slide
        double averagePlatformY =
            (collision.s1.firstPoint()->y + collision.s1.secondPoint()->y +
             collision.s2.firstPoint()->y + collision.s2.secondPoint()->y) /
                4 -
            collision.cornerPosition.y;

        std::cout << "platform y is on average" << averagePlatformY
                  << std::endl;

        if ((collisionPoint == collisionLine1 ||
             collisionPoint == collisionLine2) &&
            sign(averagePlatformY) == sign(slide.y)) {
            std::cout << "ignoring because we collided on a corner and the "
                         "slide is in the same direction as platform"
                      << std::endl;
            return false;
        }

        if (std::abs(slide.y - 0) < COLLISION_EPSILON) {
            return false;
        }

        // scale the slide back if the destination Y is less than the
        // destination slide

        std::cout << "unscaled slide: " << slide << std::endl;

        double ySlide = projectedEcb.origin.y - currentEcb.origin.y;
        std::cout << "initial vertical slide: " << ySlide << std::endl;
        ySlide = sign(ySlide) * std::min(std::abs(ySlide), std::abs(slide.y));
        std::cout << "minimal vertical slide: " << ySlide << std::endl;

        slide *= ySlide / slide.y;

        std::cout << "current start " << currentEdge.start << std::endl;
        std::cout << "current end   " << currentEdge.end << std::endl;
        std::cout << "slide: " << slide << std::endl;

        nextStepEcb.setOrigin(nextStepEcb.origin + slide);
    }

    std::cout << "projected Ecb " << projectedEcb << std::endl;
    std::cout << "collided Ecb " << nextStepEcb << std::endl;
    rollback<getX, getY>(player, currentEcb, nextStepEcb, projectedEcb);

    std::cout << "rolled back projected Ecb " << projectedEcb << std::endl;

    return true;
}

bool Map::performFloorCollision(Player& player,
                                Ecb const& currentEcb,
                                Ecb& nextStepEcb,
                                Ecb& projectedEcb,
                                Platform*& currentPlatform,
                                double& distance) {
    CollisionDatum collision;
    if (!getClosestCollision(currentEcb.bottom, projectedEcb.bottom, collision,
                             currentPlatform)) {
        return false;
    }
    if (collision.type != FLOOR_COLLISION)
        return false;
    if (!player.canLand(collision.segment.getPlatform()))
        return false;

    distance = (currentEcb.bottom - collision.position).euclid();

    // player landing alters ECB as well
    currentPlatform = collision.segment.getPlatform();
    player.land(currentPlatform);
    nextStepEcb = player.currentCollision->postCollision;
    nextStepEcb.setBottom(collision.position);
    projectedEcb = nextStepEcb;
    std::cout << nextStepEcb << std::endl;

    return true;
}

void Map::movePlayer(Player& player, Pair& requestedDistance) {
    // TODO think about ledge grabbing
    grabLedges(player);

    std::cout << "===========================" << std::endl;
    std::cout << "requested distance: " << requestedDistance << std::endl;
    std::cout << "grounded? " << player.isGrounded() << std::endl;

    if (requestedDistance.x == 0 && requestedDistance.y == 0)
        return;

    // if the player is grounded, move them along the platform
    Pair projectedPosition = player.position;
    basicProjection(player, requestedDistance, projectedPosition);

    // motion state has 3 components.
    // current position
    Ecb currentEcb = player.currentCollision->playerModified;
    // eventual ecb after resolving all motion
    Ecb projectedEcb = player.currentCollision->postCollision;
    projectedEcb.setOrigin(projectedPosition + PLAYER_ECB_OFFSET);
    player.currentCollision->root.setOrigin(projectedPosition +
                                            PLAYER_ECB_OFFSET);
    player.currentCollision->playerModified.setOrigin(projectedPosition +
                                                      PLAYER_ECB_OFFSET);
    // ecb after resolving the next step of motion
    Ecb nextStepEcb = projectedEcb;

    std::cout << "remaining distance after motion: " << requestedDistance
              << std::endl;
    std::cout << "projected pos:      " << projectedPosition << std::endl;

#define debugEcb()                                                   \
    {                                                                \
        std::cout << "currentEcb   : " << currentEcb << std::endl;   \
        std::cout << "nextStepEcb  : " << nextStepEcb << std::endl;  \
        std::cout << "projectedEcb : " << projectedEcb << std::endl; \
    };

#define debugTmpEcb()                                                      \
    {                                                                      \
        std::cout << "currentEcb      : " << currentEcb << std::endl;      \
        std::cout << "tmpNextStepEcb  : " << tmpNextStepEcb << std::endl;  \
        std::cout << "tmpProjectedEcb : " << tmpProjectedEcb << std::endl; \
    };

#define overrideEcbs(name, type, side)                               \
    {                                                                \
        std::cout << "---- " << name << std::endl;                   \
        if (thisProjectedDistance < currentClosestDistance) {        \
            std::cout << "updated current predictions" << std::endl; \
            std::cout << thisProjectedDistance << " < "              \
                      << currentClosestDistance << std::endl;        \
            closestNextStepEcb = tmpNextStepEcb;                     \
            closestProjectedEcb = tmpProjectedEcb;                   \
            currentClosestDistance = thisProjectedDistance;          \
            e = type;                                                \
            debugTmpEcb();                                           \
        } else {                                                     \
            std::cout << "ignoring, current is closer" << std::endl; \
            std::cout << thisProjectedDistance << " > "              \
                      << currentClosestDistance << std::endl;        \
        }                                                            \
    }

    int iterationCount = 0;
    do {
        // panic state
        iterationCount++;
        if (iterationCount > 10) {
            std::cout << "panicing and exiting" << std::endl;
            // exit(1);
            return;
        }

        std::cout << "---------------------------" << std::endl;
        debugEcb();

        double currentClosestDistance = DOUBLE_INFINITY;
        double thisProjectedDistance = DOUBLE_INFINITY;
        Ecb closestNextStepEcb = nextStepEcb;
        Ecb closestProjectedEcb = projectedEcb;

        Ecb tmpNextStepEcb = nextStepEcb;
        Ecb tmpProjectedEcb = projectedEcb;

        ENVIRONMENT_COLLISION_TYPE e = NO_ENVIRONMENT_COLLISION;

        // we make movements in short segments.
        // each of these collisions will optionally update nextStepEcb if they
        // are closer than the original ecb

        Platform* currentPlatform = NULL;
        if (player.isGrounded()) {
            currentPlatform = player.getCurrentPlatform();
        }

        // perform right wall collision
        if (performWallCollision<getEcbSideRight, setEcbSideRight, getX, getY,
                                 setY>(player, Pair(1, 0), currentEcb,
                                       tmpNextStepEcb, tmpProjectedEcb,
                                       thisProjectedDistance)) {
            overrideEcbs("Right Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // perform left wall collision
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (performWallCollision<getEcbSideLeft, setEcbSideLeft, getX, getY,
                                 setY>(player, Pair(-1, 0), currentEcb,
                                       tmpNextStepEcb, tmpProjectedEcb,
                                       thisProjectedDistance)) {
            overrideEcbs("Left Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // // perform ceiling collision
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (performWallCollision<getEcbTop, setEcbTop, getY, getX, setX>(
                player, Pair(0, -1), currentEcb, tmpNextStepEcb,
                tmpProjectedEcb, thisProjectedDistance)) {
            overrideEcbs("Ceiling collision", ENVIRONMENT_CEIL_COLLISION,
                         origin);
        }

        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (performWallEdgeCollision<getEcbSideRight, getEcbTop,
                                     setEcbSideRight>(
                player, currentEcb, tmpNextStepEcb, tmpProjectedEcb,
                thisProjectedDistance)) {
            overrideEcbs("Top Right Edge collision", ENVIRONMENT_EDGE_COLLISION,
                         origin);
        }

        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (performWallEdgeCollision<getEcbSideRight, getEcbBottom,
                                     setEcbSideRight>(
                player, currentEcb, tmpNextStepEcb, tmpProjectedEcb,
                thisProjectedDistance)) {
            overrideEcbs("Bottom Right Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        // tmpNextStepEcb = nextStepEcb;
        // tmpProjectedEcb = projectedEcb;
        // if (performWallEdgeCollision<getEcbSideLeft, getEcbBottom,
        //                              setEcbSideLeft>(
        //         player, currentEcb, tmpNextStepEcb, tmpProjectedEcb)) {
        //     overrideEcbs("Bottom Left Edge collision",
        //     ENVIRONMENT_EDGE_COLLISION, origin);
        // }

        // perform this collision last so that we can call player::land()
        // without it being overridden
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (performFloorCollision(player, currentEcb, tmpNextStepEcb,
                                  tmpProjectedEcb, currentPlatform,
                                  thisProjectedDistance)) {
            overrideEcbs("Floor Collision", ENVIRONMENT_FLOOR_COLLISION,
                         bottom);
        }

        // update this step of motion
        currentEcb = closestNextStepEcb;
        nextStepEcb = closestProjectedEcb;
        projectedEcb = closestProjectedEcb;

    } while (currentEcb.origin != projectedEcb.origin);

    std::cout << "resolving: " << currentEcb << std::endl;

    // reset player position to the projected Ecb
    player.moveTo(currentEcb);
}

void Map::grabLedges(Player& player) {
    if (player.canGrabLedge()) {
        for (Ledge& l : ledges) {
            Pair ledgebox_position = player.position + Pair(0, -LEDGEBOX_BASE);
            Pair diff = l.position - ledgebox_position;
            if (sign(diff.x) == sign(player.face) && player.face != l.facing &&
                std::abs(diff.x) < LEDGEBOX_WIDTH &&
                diff.y > -LEDGEBOX_HEIGHT && diff.y < 0) {
                player.grabLedge(&l);
                return;
            }
        }
    }
}

void Map::render(SDL_Renderer* r) {
    for (Platform& p : platforms) {
        p.render(r);
    }

    for (Ledge& l : ledges) {
        l.render(r);
    }
}

Platform* Map::getPlatform(size_t index) {
    return &(platforms[index]);
}

// Pair slide(
//     Pair const& l1,
//     Pair const& l2,
//     Pair const& coll,
//     Pair const& dest) {

//     Pair slope = l2 - l1;
//     Pair perp = Pair(-slope.y, slope.x);
//     Pair projected = dest + perp;

//     Pair intersectionPoint;
//     checkLineIntersection(l1, l2, dest, projected, intersectionPoint);

//     if (onLine(l1, l2, intersectionPoint)) {
//         return intersectionPoint - coll;
//     } else if (r > 1){
//         return l2 - coll;
//     } else {
//         return l1 - coll;
//     }

// }
