#ifndef __PLAYER_COLLISION
#define __PLAYER_COLLISION

#include "./ecb.hpp"
#include "engine/pair.hpp"

class PlayerCollision {
   public:
    Ecb root;
    Ecb playerModified;
    Ecb postCollision;

    void reset(Pair origin);
};

#endif
