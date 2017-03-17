#ifndef __GAME_PLAYER_PHYSICS
#define __GAME_PLAYER_PHYSICS

#include "map.hpp"
#include "game/pair.hpp"
#include "terraincollisiontype.hpp"

namespace Physics {

bool getClosestCollision(
    Map const &m,
    Pair const& start,
    Pair const& end,
    CollisionDatum& outputCollision,
    PlatformSegment& ignoredCollision,
    TerrainCollisionType expectedCollisionType) const;

bool getClosestEdgeCollision(
        Map const& m,
        Pair const& a1,
        Pair const& a2,
        Pair const& b1,
        Pair const& b2,
        EdgeCollision& collision) const;

}

#endif

