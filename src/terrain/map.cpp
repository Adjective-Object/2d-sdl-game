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

template <Pair& (*getEcbSide)(Ecb*),
          void (*setEcbSide)(Ecb*, Pair pos),
          double (*x)(Pair& pos),
          double (*y)(Pair& pos),
          void (*setNonblockingAxis)(Pair& pos, double value)>
void Map::performWallCollision(Player& player,
                               Ecb*& currentEcb,
                               Ecb*& projectedEcb) {
    CollisionDatum collision;

    if (getClosestCollision(getEcbSide(currentEcb), getEcbSide(projectedEcb),
                            collision, NULL)) {
        std::cout << "collision with wall!" << std::endl;
        if (collision.type == WALL_COLLISION) {
            std::cout << "colliding with wall "
                      << collision.segment.getPlatform() << " at "
                      << collision.position << std::endl;

            Pair wallSlidePosition = collision.position;

            if (!player.isGrounded()) {
                double directionY =
                    y(projectedEcb->origin) - y(currentEcb->origin);
                setNonblockingAxis(
                    wallSlidePosition,
                    (directionY > 0)
                        ? std::min(std::max(y(*collision.segment.secondPoint()),
                                            y(*collision.segment.firstPoint())),
                                   y(getEcbSide(projectedEcb)))
                        : std::max(std::min(y(*collision.segment.secondPoint()),
                                            y(*collision.segment.firstPoint())),
                                   y(getEcbSide(projectedEcb))));
            }

            std::cout << "position after sliding " << wallSlidePosition
                      << std::endl;

            // slide the ecb along the wall
            Ecb tmpEcb = *projectedEcb;
            setEcbSide(&tmpEcb, wallSlidePosition);

            std::cout << "ecbs " << currentEcb->origin << ".."
                      << projectedEcb->origin << std::endl;

            if (!player.isGrounded() &&
                std::abs(y(getEcbSide(projectedEcb)) - y(wallSlidePosition)) >
                    COLLISION_EPSILON) {
                // move the goal back by taking the X difference between the
                // position without collision at the new Y and the position
                // after wall sliding

                // get the relative positions of the destination with and
                // without collision
                Pair relPosNoColl =
                    getEcbSide(projectedEcb) - getEcbSide(currentEcb);
                Pair relPosColl = wallSlidePosition - getEcbSide(currentEcb);
                relPosNoColl *= y(relPosColl) / y(relPosNoColl);

                double noCollisionDistance = x(relPosColl) - x(relPosNoColl);

                Pair rollbackPosition =
                    getEcbSide(projectedEcb) + Pair(noCollisionDistance, 0);

                // update the player position and projected ECB
                player.moveTo(tmpEcb);
                setEcbSide(projectedEcb, rollbackPosition);

            } else {
                // walls only effect the X axis, so if the Y axis is
                // similar enough, the player will get stuck on the wall.
                // Do nothing then.
                setEcbSide(projectedEcb, wallSlidePosition);
            }
        }
    }
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
        performWallCollision<getEcbSideRight, setEcbSideRight, getX, getY,
                             setY>(player, currentEcb, projectedEcb);

        // perform right wall collision
        performWallCollision<getEcbSideLeft, setEcbSideLeft, getX, getY, setY>(
            player, currentEcb, projectedEcb);

        // // perform ceiling collision
        performWallCollision<getEcbTop, setEcbTop, getY, getX, setX>(
            player, currentEcb, projectedEcb);

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
