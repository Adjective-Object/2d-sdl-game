#include "./map.hpp"
#include "util.hpp"
#include "constants.hpp"
#include <iostream>

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges){};

bool Map::getClosestCollision(
            Pair const& start,
            Pair const& end,
            CollisionDatum & out) {

    double closestDist = DOUBLE_INFINITY;
    int segment;
    Pair collisionPoint;

    for(Platform & p: platforms) {
        TerrainCollisionType t = p.checkCollision(
            start, end, collisionPoint, segment);

        double distance = (collisionPoint - start).euclid();
        if (t != NO_COLLISION && distance < closestDist) {
            out.type = t;
            out.platform = &p;
            out.position = collisionPoint;
            out.segment = segment;
        }
    }
}

bool Map::getClosestEcbCollision(
            Ecb const& start,
            Ecb const& end,
            CollisionDatum & closestCollisionut) {

    double closestDist = DOUBLE_INFINITY;
    CollisionDatum collision;
    bool anyCollision = false;

    getClosestCollision(start.left, end.left, collision);
    if ((collision.position - start).euclid() < closestDist){
        closestCollision = collision;
        closestCollision.position.x -= start.widthLeft;
        anyCollision = true;
    }

    getClosestCollision(start.right, end.right, collision);
    if ((collision.position - start).euclid() < closestDist) {
        closestCollision = collision;
        closestCollision.position.x += start.widthRight;
        anyCollision = true;
    }

    getClosestCollision(start.top, end.top, collision);
    if ((collision.position - start).euclid() < closestDist) {
        closestCollision = collision;
        closestCollision.position.y -= start.heightTop;
        anyCollision = true;
    }

    getClosestCollision(start.bottom, end.bottom, collision);
    if ((collision.position - start).euclid() < closestDist) {
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

    while(currentEcb.origin != predictedEcb.origin) {
        CollisionDatum collision;

        getClosestCollision(
            currentEcb.right,
            predictedEcb.right,
            collision
        );

        // walls clamp the x. We move the current Ecb to either the
        // end of the wall or the y position on the wall of the predicted
        // ecb
        if (collision.type == WALL_COLLISION) {

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
