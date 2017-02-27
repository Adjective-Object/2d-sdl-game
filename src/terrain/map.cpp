#include "./map.hpp"
#include "util.hpp"
#include "constants.hpp"
#include <iostream>
#include "engine/game.hpp"

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges){};

bool Map::getClosestCollision(Pair const& start,
                              Pair const& end,
                              CollisionDatum& out) {
    double closestDist = DOUBLE_INFINITY;
    PlatformSegment segment;
    Pair collisionPoint;
    bool anyCollision = false;

    for (Platform& p : platforms) {
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

void Map::movePlayer(Player& player, Pair& requestedDistance) {
    // grab ledges
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

    PlatformSegment segment;
    bool continueWalking = player.isGrounded();
    if (continueWalking) {
        player.getCurrentPlatform()->findSegment(player.position, segment);
    }

    Ecb* currentEcb = &(player.previousCollision->postCollision);
    Ecb* predictedEcb = &(player.currentCollision->postCollision);

    Pair remainingDistance = requestedDistance;

    while (remainingDistance != Pair(0, 0)) {
        std::cout << "stepping motion.. " << remainingDistance << std::endl;

        // perform motion based on if the player is grounded
        if (continueWalking) {
            std::cout << "walking" << std::endl;

            // TODO we shouldn't do any of these transitions here,
            // instead this should be deferred until after collision is resolved
            Pair groundPosition = currentEcb->bottom;
            double distance = remainingDistance.x;
            continueWalking = segment.getPlatform()->stepAlongSegment(
                segment, groundPosition, distance);

            predictedEcb->setBottom(groundPosition);
        } else {
            std::cout << "not walking" << std::endl;
            predictedEcb->setOrigin(currentEcb->origin + remainingDistance);
        }

        CollisionDatum collision;
        if (!getClosestCollision(currentEcb->bottom, predictedEcb->bottom,
                                 collision)) {
            std::cout << "no collision. "
                      << (predictedEcb->origin - currentEcb->origin)
                      << std::endl;
            std::cout << "remaining " << remainingDistance << std::endl;

            remainingDistance -= (predictedEcb->origin - currentEcb->origin);
            currentEcb = predictedEcb;
            continue;
        }
        std::cout << "collision of type " << collision.type << std::endl;

        if (collision.type == FLOOR_COLLISION) {
            std::cout << "landing " << std::endl;
            printf("predicted ecb is @ %p\n", predictedEcb);

            player.land(collision.segment.getPlatform(), collision.position);
            predictedEcb->setBottom(collision.position);
            break;
        }

        // // walls clamp the x. We move the current Ecb to either the
        // // end of the wall or the y position on the wall of the predicted
        // // ecb
        // else if (collision.type == WALL_COLLISION) {
        //     // moving down
        //     double destination_y;

        //     // move either to the end of the platform or the
        //     // destination y
        //     if (currentEcb.origin.y < predictedEcb.origin.y) {
        //         std::cout << "move down" << std::endl;
        //         destination_y =
        //             std::min(std::min(predictedEcb.origin.y,
        //                               collision.segment.firstPoint()->y),
        //                      collision.segment.secondPoint()->y);
        //     } else {
        //         std::cout << "move up" << std::endl;
        //         destination_y =
        //             std::max(std::max(predictedEcb.origin.y,
        //                               collision.segment.firstPoint()->y),
        //                      collision.segment.secondPoint()->y);
        //     }

        //     // get the old slope
        //     double yDiff = (destination_y - currentEcb.origin.y);
        //     double oldSlope = (predictedEcb.origin.x - currentEcb.origin.x) /
        //                       (predictedEcb.origin.y - currentEcb.origin.y);
        //     double oldPredictedX = predictedEcb.origin.x + yDiff * oldSlope;

        //     // move either to the end of the platform or the
        //     // destination y
        //     Pair destinationPoint =
        //         currentEcb.origin + collision.segment.slope() * yDiff;
        //     currentEcb.setOrigin(destinationPoint +
        //                          Pair(-currentEcb.widthRight, 0));

        //     // update the predictedEcb's x position
        //     Pair updatedOrigin = predictedEcb.origin +
        //                          Pair(oldPredictedX - destinationPoint.x, 0);
        //     predictedEcb.setOrigin(updatedOrigin);

        // }

        // ceilings clamp the y. We move the current Ecb to either the
        // end of the wall or the y position on the wall of the predicted
        // ecb
        // else if (collision.type == CEIL_COLLISION) {
        //     // todo
        // }

        else {
            std::cout << "unhandled collision" << std::endl;
            break;
        }
    };

    // update player to moved ecb?
    printf("______ updating location ________\n");
    player.position = currentEcb->origin - PLAYER_ECB_OFFSET;
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
