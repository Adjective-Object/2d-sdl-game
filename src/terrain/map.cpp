#include "./map.hpp"
#include "util.hpp"
#include "engine/util.hpp"
#include "constants.hpp"
#include <iostream>
#include "engine/game.hpp"
#include "widthbuf.hpp"

// helpers for abusing template functions violently

using namespace Terrain;

widthstream out(255, std::cout);

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

inline void setX(Pair& pos, const double val) {
    pos.x = val;
}

inline void setY(Pair& pos, const double val) {
    pos.y = val;
}

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges){};

bool Map::getClosestCollision(
    Pair const& start,
    Pair const& end,
    CollisionDatum& outputCollision,
    PlatformSegment& ignoredCollision,
    TerrainCollisionType expectedCollisionType) const {
    double closestDist = DOUBLE_INFINITY;
    PlatformSegment segment;
    Pair collisionPoint;
    bool anyCollision = false;

    for (Platform const& p : platforms) {
        TerrainCollisionType t = p.checkCollision(
            start, end, collisionPoint, segment, expectedCollisionType);

        if (t != expectedCollisionType) {
            continue;
        }

        if (segment == ignoredCollision) {
            out << "ignoring collision with platform because it was previously "
                   "collided with"
                << std::endl;
            out << ignoredCollision << std::endl;
            out << segment << std::endl;
            continue;
        }

        double distance = (collisionPoint - start).euclid();
        if (distance < closestDist) {
            closestDist = distance;
            outputCollision.type = t;
            outputCollision.segment = segment;
            outputCollision.position = collisionPoint;
            anyCollision = true;
        }
    }

    return anyCollision;
}

bool Map::getClosestEdgeCollision(Pair const& a1,
                                  Pair const& a2,
                                  Pair const& b1,
                                  Pair const& b2,
                                  EdgeCollision& collision) const {
    for (Platform const& platform : platforms) {
        if (!platform.isPassable() &&
            platform.checkEdgeCollision(a1, a2, b1, b2, collision)) {
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
template <double (*x)(Pair const& pos),
          double (*y)(Pair const& pos),
          void (*xSet)(Pair& pos, const double val)>
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
        out << "rollback grounded " << nextStepEcb << std::endl;
        projectedEcb.setOrigin(nextStepEcb.origin);
    } else {
        relPosNoColl *= y(relPosColl) / y(relPosNoColl);

        out << relPosNoColl << " " << relPosColl << std::endl;

        double noCollisionDistance = x(relPosColl) - x(relPosNoColl);
        if (currentEcb.origin == nextStepEcb.origin) {
            // we collide with the wall at the next step. only slide.
            noCollisionDistance = x(currentEcb.origin) - x(projectedEcb.origin);
        }

        out << "noCollisionDistance " << noCollisionDistance << std::endl;

        Pair rollbackAmount = Pair(0, 0);
        xSet(rollbackAmount, noCollisionDistance);
        Pair rollbackPosition = projectedEcb.origin + rollbackAmount;

        out << "rollback position: " << rollbackPosition << std::endl;

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
          void (*setBlockingAxis)(Pair& pos, double val),
          void (*setNonblockingAxis)(Pair& pos, double value),
          TerrainCollisionType expectedCollisionType>
bool performWallCollision(Map const& m,
                          Player const& player,
                          const Pair expectedDirection,
                          Ecb& currentEcb,
                          Ecb& nextStepEcb,
                          Ecb& projectedEcb,
                          double& distance,
                          PlatformSegment& lastWallCollision) {
    CollisionDatum collision;

    // ignore collision if the collision is coming from the wrong direction
    if (Dot((projectedEcb.origin - currentEcb.origin), expectedDirection) < 0) {
        return false;
    }

    Ecb _currentEcb = currentEcb;
    if (!m.getClosestCollision(getEcbSide(_currentEcb),
                               getEcbSide(projectedEcb), collision,
                               lastWallCollision, expectedCollisionType)) {
        return false;
    }

    lastWallCollision = collision.segment;

    distance = (getEcbSide(currentEcb) - collision.position).euclid();

    out << "colliding with wall " << collision.segment.getPlatform() << " at "
        << collision.position << std::endl;

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

    out << "position after sliding " << wallSlidePosition << std::endl;

    // slide the ecb along the wall and update the next position w/o movement
    setEcbSide(currentEcb, collision.position);
    setEcbSide(nextStepEcb, wallSlidePosition);

    out << "ecbs " << currentEcb.origin << ".." << projectedEcb.origin
        << std::endl;

    rollback<x, y, setBlockingAxis>(player, currentEcb, nextStepEcb,
                                    projectedEcb);
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
bool performWallEdgeCollision(Map const& m,
                              Player const& player,
                              Ecb& currentEcb,
                              Ecb& nextStepEcb,
                              Ecb& projectedEcb,
                              double& distance) {
    Pair currentForward = getForwardEdge(currentEcb);
    Pair currentBack = getBackEdge(currentEcb);

    Pair projectedForward = getForwardEdge(projectedEcb);
    Pair projectedBack = getBackEdge(projectedEcb);

    Pair move = projectedForward - currentForward;

    // out << "current ecb: " << *currentEcb << std::endl;
    // out << "projected ecb: " << *projectedEcb << std::endl;

    // out << "currentForward: " << currentForward << std::endl;
    // out << "currentBack: " << currentBack << std::endl;
    // out << "projectedForward: " << projectedForward << std::endl;
    // out << "projectedBack: " << projectedBack << std::endl;

    // out << "line: " << line << std::endl;
    // out << "move: " << move << std::endl;

    if (move == Pair(0, 0))
        return false;

    Line currentEdge, projectedEdge;
    EdgeCollision collision;
    if ((currentForward.y > currentBack.y) ==
        (currentForward.x > currentBack.x)) {
        currentEdge = Line(currentBack, currentForward);
        projectedEdge = Line(projectedBack, projectedForward);

        if (!m.getClosestEdgeCollision(currentEdge.start, currentEdge.end,
                                       projectedEdge.start, projectedEdge.end,
                                       collision)) {
            return false;
        }

        setForwardEdge(nextStepEcb, collision.collisionLine2);

    } else {
        currentEdge = Line(currentForward, currentBack);
        projectedEdge = Line(projectedForward, projectedBack);

        if (!m.getClosestEdgeCollision(currentEdge.start, currentEdge.end,
                                       projectedEdge.start, projectedEdge.end,
                                       collision)) {
            return false;
        }

        setForwardEdge(nextStepEcb, collision.collisionLine1);
    }

    // update the position w/o collision to the initial collision position
    currentEcb = nextStepEcb;

    Pair collisionPoint = collision.cornerPosition;
    Pair collisionLine1 = collision.collisionLine1;
    Pair collisionLine2 = collision.collisionLine2;

    distance = (collisionLine1 - currentEdge.start).euclid();

    out << "collide with corner " << collisionPoint << std::endl;
    out << "collision line  " << collisionLine1 << ".." << collisionLine2
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

        out << collisionLine1 << std::endl;
        out << collisionPoint << std::endl;
        out << collisionLine2 << std::endl;

        Pair slide = (dot < 0) ? collisionPoint - collisionLine2
                               : collisionPoint - collisionLine1;

        // if the direction of sliding is into the platform, don't slide
        double averagePlatformY =
            (collision.s1.firstPoint()->y + collision.s1.secondPoint()->y +
             collision.s2.firstPoint()->y + collision.s2.secondPoint()->y) /
                4 -
            collision.cornerPosition.y;

        out << "platform y is on average" << averagePlatformY << std::endl;

        if ((collisionPoint == collisionLine1 ||
             collisionPoint == collisionLine2) &&
            sign(averagePlatformY) == sign(slide.y)) {
            out << "ignoring because we collided on a corner and the "
                   "slide is in the same direction as platform"
                << std::endl;
            return false;
        }

        if (std::abs(slide.y - 0) < COLLISION_EPSILON) {
            return false;
        }

        // scale the slide back if the destination Y is less than the
        // destination slide

        out << "unscaled slide: " << slide << std::endl;

        double ySlide = projectedEcb.origin.y - currentEcb.origin.y;
        out << "initial vertical slide: " << ySlide << std::endl;
        ySlide = sign(ySlide) * std::min(std::abs(ySlide), std::abs(slide.y));
        out << "minimal vertical slide: " << ySlide << std::endl;

        slide *= ySlide / slide.y;

        out << "current start " << currentEdge.start << std::endl;
        out << "current end   " << currentEdge.end << std::endl;
        out << "slide: " << slide << std::endl;

        nextStepEcb.setOrigin(nextStepEcb.origin + slide);
        // deal with clipping due to floating point errors
        if (getForwardEdge(nextStepEcb).x - collisionPoint.x <
            COLLISION_EPSILON) {
            Pair newOrigin = getForwardEdge(nextStepEcb);
            newOrigin.x = collisionPoint.x;
            setForwardEdge(nextStepEcb, newOrigin);
        }
    }

    out << "projected  " << projectedEcb << std::endl;
    out << "collided  " << nextStepEcb << std::endl;
    rollback<getX, getY, setX>(player, currentEcb, nextStepEcb, projectedEcb);

    out << "rolled back projected " << projectedEcb << std::endl;

    return true;
}

bool performFloorCollision(Map const& m,
                           Player& player,
                           Ecb& currentEcb,
                           Ecb& nextStepEcb,
                           Ecb& projectedEcb,
                           const Platform*& currentPlatform,
                           double& distance) {
    CollisionDatum collision;
    PlatformSegment currentPlatformAsSegment = PlatformSegment();

    if (!m.getClosestCollision(currentEcb.bottom, projectedEcb.bottom,
                               collision, currentPlatformAsSegment,
                               FLOOR_COLLISION)) {
        return false;
    }
    if (collision.type != FLOOR_COLLISION)
        return false;
    if (!player.canLand(collision.segment.getPlatform()))
        return false;

    distance = (currentEcb.bottom - collision.position).euclid();

    // player landing alters ECB as well
    currentPlatform = collision.segment.getPlatform();
    nextStepEcb = player.getLandedEcb(currentPlatform);
    nextStepEcb.setBottom(collision.position);
    currentEcb = nextStepEcb;
    projectedEcb = nextStepEcb;
    out << nextStepEcb << std::endl;

    return true;
}

#define WALL_COLL_ARGS Map const& m , \
                          Player const& player , \
                          const Pair expectedDirection , \
                          Ecb& currentEcb , \
                          Ecb& nextStepEcb , \
                          Ecb& projectedEcb , \
                          double& distance , \
                          PlatformSegment& lastWallCollision

constexpr bool (*rightWallCollision)(WALL_COLL_ARGS) =
performWallCollision<getEcbSideRight, setEcbSideRight, getX, getY, setX, setY,
    WALL_COLLISION>;
constexpr bool (*leftWallCollision)(WALL_COLL_ARGS) =
performWallCollision<getEcbSideLeft, setEcbSideLeft, getX, getY, setX, setY,
    WALL_COLLISION>;
constexpr bool (*ceilingCollision)(WALL_COLL_ARGS) =
    performWallCollision<getEcbTop, setEcbTop, getY, getX, setY, setX,
                                 CEIL_COLLISION>;

#define EDGE_COLL_ARGS Map const& m, \
                              Player const& player, \
                              Ecb& currentEcb, \
                              Ecb& nextStepEcb, \
                              Ecb& projectedEcb, \
                              double& distance

constexpr bool (*topRightEdgeCollision)(EDGE_COLL_ARGS) =
performWallEdgeCollision<getEcbSideRight, getEcbTop, setEcbSideRight>;
constexpr bool (*bottomRightEdgeCollision)(EDGE_COLL_ARGS) =
performWallEdgeCollision<getEcbSideRight, getEcbBottom, setEcbSideRight>;
constexpr bool (*bottomLeftEdgeCollision)(EDGE_COLL_ARGS) =
performWallEdgeCollision<getEcbSideLeft, getEcbBottom, setEcbSideLeft>;
constexpr bool (*topLeftEdgeCollision)(EDGE_COLL_ARGS) =
performWallEdgeCollision<getEcbSideLeft, getEcbTop, setEcbSideLeft>;

void Map::moveRecursive(Player& player,
                        Ecb& currentEcb,
                        Ecb& projectedEcb) const {
    // ecb after resolving the next step of motion
    Ecb nextStepEcb = projectedEcb;

    out.indent(4);

    out << std::endl;
    out << "===========================" << std::endl;
    out << "moveRecursive" << std::endl;
    out << "    " << currentEcb << std::endl;
    out << "    " << projectedEcb << std::endl;

#define debugEcb()                                             \
    {                                                          \
        out << "currentEcb   : " << currentEcb << std::endl;   \
        out << "nextStepEcb  : " << nextStepEcb << std::endl;  \
        out << "projectedEcb : " << projectedEcb << std::endl; \
    };

#define debugTmpEcb()                                                \
    {                                                                \
        out << "currentEcb      : " << currentEcb << std::endl;      \
        out << "tmpNextStepEcb  : " << tmpNextStepEcb << std::endl;  \
        out << "tmpProjectedEcb : " << tmpProjectedEcb << std::endl; \
    };

#define overrideEcbs(name, type, side)                                      \
    {                                                                       \
        out << "---- " << name << std::endl;                                \
        if (thisProjectedDistance < currentClosestDistance) {               \
            out << "updated current predictions" << std::endl;              \
            out << thisProjectedDistance << " < " << currentClosestDistance \
                << std::endl;                                               \
            closestCollisionPointEcb = tmpCollisionPointEcb;                \
            closestNextStepEcb = tmpNextStepEcb;                            \
            closestProjectedEcb = tmpProjectedEcb;                          \
            closestLastWallCollision = tmpLastWallCollision;                \
            currentClosestDistance = thisProjectedDistance;                 \
            e = type;                                                       \
            debugTmpEcb();                                                  \
        } else {                                                            \
            out << "ignoring, current is closer" << std::endl;              \
            out << thisProjectedDistance << " > " << currentClosestDistance \
                << std::endl;                                               \
        }                                                                   \
        out << "----" << std::endl;                                         \
    }

    PlatformSegment lastWallCollision = PlatformSegment(NULL, -1);

    int iterationCount = 0;
    do {
        // panic state
        iterationCount++;
        if (iterationCount > 10) {
            out << "panicing and exiting on iteration " << iterationCount
                << std::endl;
            // exit(1);
            // out << indent_manip::pop;
            out.indent(-4);
            return;
        }

        out << std::endl;
        out << "---------------------------" << std::endl;
        debugEcb();
        out << "---------------------------" << std::endl;

        double currentClosestDistance = DOUBLE_INFINITY;
        double thisProjectedDistance = DOUBLE_INFINITY;
        Ecb closestCollisionPointEcb = nextStepEcb;
        Ecb closestNextStepEcb = nextStepEcb;
        Ecb closestProjectedEcb = projectedEcb;

        Ecb tmpCollisionPointEcb = currentEcb;
        Ecb tmpNextStepEcb = nextStepEcb;
        Ecb tmpProjectedEcb = projectedEcb;
        PlatformSegment closestLastWallCollision = lastWallCollision;
        PlatformSegment tmpLastWallCollision = lastWallCollision;

        ENVIRONMENT_COLLISION_TYPE e = NO_ENVIRONMENT_COLLISION;

        // we make movements in short segments.
        // each of these collisions will optionally update nextStepEcb if they
        // are closer than the original ecb

        const Platform* currentPlatform = NULL;
        Player const& player_const = player;

        // perform right wall collision
        if (rightWallCollision(
                *this, player_const, Pair(1, 0), tmpCollisionPointEcb,
                tmpNextStepEcb, tmpProjectedEcb, thisProjectedDistance,
                tmpLastWallCollision)) {
            overrideEcbs("Right Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // perform left wall collision
        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        tmpLastWallCollision = lastWallCollision;
        if (leftWallCollision(
                *this, player_const, Pair(-1, 0), tmpCollisionPointEcb,
                tmpNextStepEcb, tmpProjectedEcb, thisProjectedDistance,
                tmpLastWallCollision)) {
            overrideEcbs("Left Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // // perform ceiling collision
        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        tmpLastWallCollision = lastWallCollision;
        if (ceilingCollision(
                *this, player_const, Pair(0, -1), tmpCollisionPointEcb,
                tmpNextStepEcb, tmpProjectedEcb, thisProjectedDistance,
                tmpLastWallCollision)) {
            overrideEcbs("Ceiling collision", ENVIRONMENT_CEIL_COLLISION,
                         origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (topRightEdgeCollision(
                *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                tmpProjectedEcb, thisProjectedDistance)) {
            overrideEcbs("Top Right Edge collision", ENVIRONMENT_EDGE_COLLISION,
                         origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (bottomRightEdgeCollision(
                *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                tmpProjectedEcb, thisProjectedDistance)) {
            overrideEcbs("Bottom Right Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (bottomLeftEdgeCollision(
                *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                tmpProjectedEcb, thisProjectedDistance)) {
            overrideEcbs("Bottom Left Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (topRightEdgeCollision(
                *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                tmpProjectedEcb, thisProjectedDistance)) {
            overrideEcbs("Bottom Left Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        if (!player.isGrounded()) {
            // perform this collision last so that we can call player::land()
            // without it being overridden
            tmpCollisionPointEcb = currentEcb;
            tmpNextStepEcb = nextStepEcb;
            tmpProjectedEcb = projectedEcb;
            if (performFloorCollision(*this, player, tmpCollisionPointEcb,
                                      tmpNextStepEcb, tmpProjectedEcb,
                                      currentPlatform, thisProjectedDistance)) {
                overrideEcbs("Floor Collision", ENVIRONMENT_FLOOR_COLLISION,
                             bottom);
            }
        }

        // this only works because landing terminates collision
        if (e == ENVIRONMENT_FLOOR_COLLISION) {
            player.land(currentPlatform);
        }

        // recursively update this step of motion if we were interrupted
        if (currentClosestDistance != DOUBLE_INFINITY &&
            closestNextStepEcb.origin != projectedEcb.origin) {
            out << "######## movement was interrupted, recursing!" << std::endl;
            // start the recursive walk at the position of the collision
            currentEcb = closestCollisionPointEcb;
            Ecb predictedNextStepEcb = closestNextStepEcb;
            moveRecursive(player, currentEcb, closestNextStepEcb);
            if (predictedNextStepEcb.origin != closestNextStepEcb.origin) {
                // the other motion interrupted this motion, so
                // our projected ECB is no longer valid. The recursive call
                // will have resolved motion ,so we break;
                out << "recursive walk changed projected ECB" << std::endl;
                out << "breaking loop" << std::endl;
                // currentEcb = closestNextStepEcb;
                break;
            }
        } else {
            // otherwise, just jump the player to the next step of their motion
            // this will be the projected ecb
            currentEcb = closestNextStepEcb;
        }
        lastWallCollision = closestLastWallCollision;
        nextStepEcb = closestProjectedEcb;
        projectedEcb = closestProjectedEcb;

    } while (currentEcb.origin != projectedEcb.origin);

    out << "resolving: " << currentEcb << std::endl;
    out << "===========================" << std::endl;
    out.indent(-4);
    // out << indent_manip::pop;
}

void Map::movePlayer(Player& player, Pair& requestedDistance) const {
    // TODO think about ledge grabbing
    // grabLedges(player);

    out << "===========================" << std::endl;
    out << "===========================" << std::endl;
    out << "===========================" << std::endl;
    out << "requested distance: " << requestedDistance << std::endl;
    out << "grounded? " << player.isGrounded() << std::endl;

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

    out << "remaining distance after motion: " << requestedDistance
        << std::endl;
    out << "projected pos:      " << projectedPosition << std::endl;

    moveRecursive(player, currentEcb, projectedEcb);

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
