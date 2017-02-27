#ifndef __GAME_COLLISIONDATUM
#define __GAME_COLLISIONDATUM

#include "./platformsegment.hpp"

class CollisionDatum {
public:
    TerrainCollisionType type;
    PlatformSegment segment;
    Pair position;
};

std::ostream& operator<<(std::ostream& strm, const CollisionDatum& p);


#endif