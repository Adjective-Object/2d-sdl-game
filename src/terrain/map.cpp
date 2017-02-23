#include "./map.hpp"

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges){};

void Map::updateCollision(Player& player) {
    // perform collisions
    for (Platform& p : platforms) {
        Pair collPos = Pair(0, 0);
        TerrainCollisionType collisionType;

        Ecb* oldEcb = &(player.previousCollision->postCollision);
        Ecb* newEcb = &(player.currentCollision->postCollision);

        collisionType =
            p.checkCollision(oldEcb->bottom, newEcb->bottom, collPos);

        if (player.velocity.y > 0 &&
            player.getAction()->isLandable(player, &p) &&
            collisionType == FLOOR_COLLISION) {
            player.land(&p, collPos);
        }

        collisionType =
            p.checkCollision(oldEcb->origin, newEcb->right, collPos);

        if (collisionType == WALL_COLLISION) {
            std::cout << "wall on right" << std::endl;

            std::cout << "player moving at " << player.cVel << std::endl;
            std::cout << "player at " << player.position << std::endl;
            std::cout << "right ecb at " << newEcb->right << std::endl;
            std::cout << "collision at " << collPos << std::endl;
            std::cout << (newEcb->right - collPos) << std::endl;
            player.moveTo(player.position - (newEcb->right - collPos));
            std::cout << "player ends at " << player.position << std::endl;
            std::cout << "right ecb end sat "
                      << player.currentCollision->postCollision.right
                      << std::endl;
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
