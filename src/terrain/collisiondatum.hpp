#ifndef __GAME_COLLISIONDATUM
#define __GAME_COLLISIONDATUM

class CollisionDatum {
public:
    TerrainCollisionType type;
    PlatformSegment segment;
    Pair position;
};

#endif