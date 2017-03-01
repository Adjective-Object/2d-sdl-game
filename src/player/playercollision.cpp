#include "./playercollision.hpp"
#include "engine/pair.hpp"

void PlayerCollision::reset(Pair origin) {
    root.setOrigin(origin);
    playerModified = root;
    postCollision = root;
}

void PlayerCollision::reset(Ecb& ecb) {
    root = ecb;
    playerModified = ecb;
    postCollision = ecb;
}
