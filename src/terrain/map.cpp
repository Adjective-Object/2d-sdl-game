#include "./map.hpp"
#include "util.hpp"
#include "constants.hpp"
#include <iostream>

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

void Map::updateCollision(Player& player) {
    // grab ledges
    if (player.canGrabLedge()) {
        for (Ledge& l : ledges) {
            Pair ledgebox_position = player.position + Pair(0, -LEDGEBOX_BASE);
            Pair diff = l.position - ledgebox_position;
            if (sign(diff.x) == sign(player.face) && player.face != l.facing &&
                std::abs(diff.x) < LEDGEBOX_WIDTH &&
                diff.y > -LEDGEBOX_HEIGHT && diff.y < 0) {
                player.grabLedge(&l);
                break;
            }
        }
    }

    Ecb currentEcb = player.previousCollision->playerModified;
    Ecb predictedEcb = player.currentCollision->playerModified;
    Pair direction = predictedEcb.origin - currentEcb.origin;

    while (currentEcb.origin != predictedEcb.origin) {
        CollisionDatum collision;

        getClosestCollision(currentEcb.right, predictedEcb.right, collision);

        std::cout << collision << std::endl;

        // walls clamp the x. We move the current Ecb to either the
        // end of the wall or the y position on the wall of the predicted
        // ecb
        if (collision.type == WALL_COLLISION) {
            // moving down
            double destination_y;

            // move either to the end of the platform or the
            // destination y
            if (currentEcb.origin.y < predicted.origin.y) {
                destination_y =
                    std::min(
                        predictedEcb.origin.y,
                        collision.segment.firstPoint().y,
                        collision.segment.secondPoint().y
                        );
            } else {
                destination_y =
                    std::max(
                        predictedEcb.origin.y,
                        collision.segment.firstPoint().y,
                        collision.segment.secondPoint().y
                        );
            }

            // get the old slope
            double yDiff = (destination_y - currentEcb.position.y);
            double oldSlope = (predictedEcb.origin.x - currentEcb.origin.x) /
                (predictedEcb.origin.y - currentEcb.origin.y) 
            double oldPredictedX = yDiff * oldSlope; 

            // move either to the end of the platform or the
            // destination y
            Pair destinationPoint = currentEcb.origin + collision.segment.slope() * yDiff;
            currentEcb.setOrigin(destinationPoint + Pair(- currentEcb.widthRight, 0));

            // update the predictedEcb's x position
            Pair updatedOrigin = predictedEcb.origin + Pair(oldPredictedX - destinationPoint.x, 0);
            predictedEcb.setOrigin(updatedOrigin);

        }

        // ceilings clamp the y. We move the current Ecb to either the
        // end of the wall or the y position on the wall of the predicted
        // ecb
        else if (collision.type == CEIL_COLLISION) {
            double destination_x;

            // move either to the end of the platform or the
            // destination x
            if (currentEcb.origin.x < predicted.origin.x) {
                destination_x =
                    std::min(
                        predictedEcb.origin.x,
                        collision.segment.firstPoint().x,
                        collision.segment.secondPoint().x
                        );
            } else {
                destination_x =
                    std::max(
                        predictedEcb.origin.x,
                        collision.segment.firstPoint().x,
                        collision.segment.secondPoint().x
                        );
            }

            // get the old slope
            double xDiff = (destination_x - currentEcb.position.x);
            double oldSlope = (predictedEcb.origin.x - currentEcb.origin.x) /
                (predictedEcb.origin.x - currentEcb.origin.x) 
            double oldPredictedY = xDiff * oldSlope; 

            // move either to the end of the platform or the
            // destination x
            Pair destinationPoint = currentEcb.origin + collision.segment.slope() * xDiff;
            currentEcb.setOrigin(destinationPoint + Pair(0, - currentEcb.heightTop));

            // update the predictedEcb's x position
            Pair updatedOrigin = predictedEcb.origin + Pair(0, oldPredictedY - destinationPoint.x);
            predictedEcb.setOrigin(updatedOrigin);
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
