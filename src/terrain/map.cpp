#include "./map.hpp"
#include "util.hpp"
#include "constants.hpp"
#include <iostream>
#include "engine/game.hpp"

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
                                  Pair& collisionPoint,
                                  Pair& collidedPoint1,
                                  Pair& collidedPoint2) {
    for (Platform& platform : platforms) {
        if (platform.checkEdgeCollision(a1, a2, b1, b2, collisionPoint,
                                        collidedPoint1, collidedPoint2)) {
            return true;
        }
    }

    return false;
}

bool Map::getClosestEcbCollision(Ecb const& start,
                                 Ecb const& end,
                                 CollisionDatum& closestCollision) {
    double closestDist = DOUBLE_INFINITY;
    CollisionDatum collision;
    bool anyCollision = false;

    getClosestCollision(start.left, end.left, collision);
    if ((collision.position - start.left).euclid() < closestDist) {
        closestCollision = collision;
        closestCollision.position.x -= start.widthLeft;
        anyCollision = true;
    }

    getClosestCollision(start.right, end.right, collision);
    if ((collision.position - start.right).euclid() < closestDist) {
        closestCollision = collision;
        closestCollision.position.x += start.widthRight;
        anyCollision = true;
    }

    getClosestCollision(start.top, end.top, collision);
    if ((collision.position - start.top).euclid() < closestDist) {
        closestCollision = collision;
        closestCollision.position.y -= start.heightTop;
        anyCollision = true;
    }

    getClosestCollision(start.bottom, end.bottom, collision);
    if ((collision.position - start.bottom).euclid() < closestDist) {
        closestCollision = collision;
        closestCollision.position.y += start.heightBottom;
        anyCollision = true;
    }

    return anyCollision;
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

void rollback(Player& player,
              Ecb& tmpEcb,
              Ecb*& currentEcb,
              Ecb*& projectedEcb) {
    double collisionVerticalDifference =
        std::abs(projectedEcb->origin.y) - tmpEcb.origin.y;

    if (!player.isGrounded() &&
        collisionVerticalDifference > COLLISION_EPSILON) {
        // move the goal back by taking the X difference between the
        // position without collision at the new Y and the position
        // after wall sliding

        // get the relative positions of the destination with and
        // without collision
        Pair relPosNoColl = projectedEcb->origin - currentEcb->origin;
        Pair relPosColl = tmpEcb.origin - currentEcb->origin;
        relPosNoColl *= relPosColl.y / relPosNoColl.y;

        double noCollisionDistance = relPosColl.x - relPosNoColl.x;

        Pair rollbackPosition =
            projectedEcb->origin + Pair(noCollisionDistance, 0);

        // update the player position and projected ECB
        player.moveTo(tmpEcb);
        projectedEcb->setOrigin(rollbackPosition);
    } else {
        player.moveTo(tmpEcb);
    }
}

template <TerrainCollisionType expectedType,
          Pair& (*getEcbSide)(Ecb*),
          void (*setEcbSide)(Ecb*, Pair pos),
          double (*x)(Pair& pos),
          double (*y)(Pair& pos),
          void (*setNonblockingAxis)(Pair& pos, double value)>
bool Map::performWallCollision(Player& player,
                               Ecb*& currentEcb,
                               Ecb*& projectedEcb) {
    CollisionDatum collision;

    if (!getClosestCollision(getEcbSide(currentEcb), getEcbSide(projectedEcb),
                             collision, NULL)) {
        return false;
    }

    if (collision.type != expectedType) {
        return false;
    }

    std::cout << "colliding with wall " << collision.segment.getPlatform()
              << " at " << collision.position << std::endl;

    Pair wallSlidePosition = collision.position;

    // perform sliding if the player is not grounded
    if (!player.isGrounded()) {
        double directionY = y(projectedEcb->origin) - y(currentEcb->origin);
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
    Ecb tmpEcb = *projectedEcb;
    setEcbSide(&tmpEcb, wallSlidePosition);

    std::cout << "ecbs " << currentEcb->origin << ".." << projectedEcb->origin
              << std::endl;

    rollback(player, tmpEcb, currentEcb, projectedEcb);

    return true;
}
template <Pair& (*getForwardEdge)(Ecb*),
          Pair& (*getBackEdge)(Ecb*),
          void (*setForwardEdge)(Ecb*, Pair pos)>
bool Map::performWallEdgeCollision(Player& player,
                                   Ecb*& currentEcb,
                                   Ecb*& projectedEcb) {
    Pair collisionPoint;
    Pair collisionLine1, collisionLine2;

    Pair currentForward = getForwardEdge(currentEcb);
    Pair currentBack = getBackEdge(currentEcb);

    Pair projectedForward = getForwardEdge(projectedEcb);
    Pair projectedBack = getBackEdge(projectedEcb);

    Pair line = currentForward - currentBack;
    Pair move = projectedForward - currentForward;

    // std::cout << "current ecb: " << *currentEcb << std::endl;
    // std::cout << "projected ecb: " << *projectedEcb << std::endl;

    // std::cout << "currentForward: " << currentForward << std::endl;
    // std::cout << "currentBack: " << currentBack << std::endl;
    // std::cout << "projectedForward: " << projectedForward << std::endl;
    // std::cout << "projectedBack: " << projectedBack << std::endl;

    // std::cout << "line: " << line << std::endl;
    // std::cout << "move: " << move << std::endl;

    if (sign(line.x) == -sign(move.x))
        return false;
    if (move == Pair(0, 0))
        return false;

    if (!getClosestEdgeCollision(currentBack, currentForward, projectedBack,
                                 projectedForward, collisionPoint,
                                 collisionLine1, collisionLine2)) {
        return false;
    }

    std::cout << "collide with corner " << collisionPoint << std::endl;

    // slide the ecb along the wall
    Ecb tmpEcb = *projectedEcb;
    setForwardEdge(&tmpEcb, collisionLine2);

    // perform vertical sliding if the player is not grounded
    if (!player.isGrounded()) {
        // we want to slide this edge of the ecb along the point. It can slide
        // either the full length of the ecb, or slide along the ecb until a
        // dimension of the projected point is the same as the dimension of
        // the slid point
        double maxXSlide = std::min(projectedForward.x - projectedBack.x,
                                    projectedForward.x - currentForward.x);

        double maxYSlide =
            sign(move.y) *
            std::min(std::abs(projectedForward.y - projectedBack.y),
                     std::abs(projectedBack.y - currentBack.y));

        double heightBack = projectedEcb->origin.y - projectedBack.y;
        double widthForward = projectedForward.x - projectedEcb->origin.x;

        double slope = heightBack / widthForward;
        Pair slide = Pair(maxXSlide, 0);

        if (std::abs(slope - 0) > COLLISION_EPSILON) {
            double maxSlideDistanceX =
                sign(move.x) * std::min(std::abs(maxXSlide * slope),
                                        std::abs(maxYSlide / slope));

            slide = Pair(maxSlideDistanceX, maxSlideDistanceX * slope);
        }

        std::cout << "heightBack " << heightBack << std::endl;
        std::cout << "widthForward " << widthForward << std::endl;
        std::cout << "max x slide " << maxXSlide << std::endl;
        std::cout << "max y slide " << maxYSlide << std::endl;
        std::cout << "slope " << slope << std::endl;
        std::cout << "slide for " << slide << std::endl;

        tmpEcb.setOrigin(tmpEcb.origin + slide);
    }

    rollback(player, tmpEcb, currentEcb, projectedEcb);

    return true;
}

inline Pair& getEcbSideRight(Ecb* e) {
    return e->right;
}

inline void setEcbSideRight(Ecb* e, Pair pos) {
    return e->setRight(pos);
}

inline Pair& getEcbSideLeft(Ecb* e) {
    return e->left;
}

inline void setEcbSideLeft(Ecb* e, Pair pos) {
    return e->setLeft(pos);
}

inline Pair& getEcbBottom(Ecb* e) {
    return e->bottom;
}

inline Pair& getEcbTop(Ecb* e) {
    return e->top;
}

inline void setEcbTop(Ecb* e, Pair pos) {
    return e->setTop(pos);
}

inline double getX(Pair& pos) {
    return pos.x;
}

inline double getY(Pair& pos) {
    return pos.y;
}

inline void setX(Pair& pos, double val) {
    pos.x = val;
}

inline void setY(Pair& pos, double val) {
    pos.y = val;
}

void Map::movePlayer(Player& player, Pair& requestedDistance) {
    // TODO think about ledge grabbing
    grabLedges(player);

    // if the player is grounded, move them along the platform
    Pair projectedPosition;
    basicProjection(player, requestedDistance, projectedPosition);

    Ecb* currentEcb = &(player.currentCollision->playerModified);
    Ecb* projectedEcb = &(player.currentCollision->postCollision);
    projectedEcb->setOrigin(projectedPosition + PLAYER_ECB_OFFSET);

    do {
        Platform* currentPlatform = NULL;
        if (player.isGrounded()) {
            currentPlatform = player.getCurrentPlatform();
        }

        CollisionDatum collision;
        if (getClosestCollision(currentEcb->bottom, projectedEcb->bottom,
                                collision, currentPlatform)) {
            // if there is a collision with the floor, land
            if (collision.type == FLOOR_COLLISION) {
                if (player.canLand(collision.segment.getPlatform())) {
                    std::cout << "triggering landing "
                              << collision.segment.getPlatform() << std::endl;

                    // player landing alters ECB as well
                    player.land(collision.segment.getPlatform());
                    projectedEcb->setBottom(collision.position);
                }
            }
        }

        // perform right wall collision
        performWallCollision<WALL_COLLISION, getEcbSideRight, setEcbSideRight,
                             getX, getY, setY>(player, currentEcb,
                                               projectedEcb);

        // perform left wall collision
        performWallCollision<WALL_COLLISION, getEcbSideLeft, setEcbSideLeft,
                             getX, getY, setY>(player, currentEcb,
                                               projectedEcb);

        // // perform ceiling collision
        performWallCollision<CEIL_COLLISION, getEcbTop, setEcbTop, getY, getX,
                             setX>(player, currentEcb, projectedEcb);

        performWallEdgeCollision<getEcbSideRight, getEcbTop, setEcbSideRight>(
            player, currentEcb, projectedEcb);

        performWallEdgeCollision<getEcbSideRight, getEcbBottom,
                                 setEcbSideRight>(player, currentEcb,
                                                  projectedEcb);

        // reset player position to the projected Ecb
        player.moveTo(*projectedEcb);

    } while (currentEcb->origin != projectedEcb->origin);
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
