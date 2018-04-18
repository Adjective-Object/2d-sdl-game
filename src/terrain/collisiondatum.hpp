#ifndef __GAME_COLLISIONDATUM
#define __GAME_COLLISIONDATUM

#include "./platformsegment.hpp"
#include "./collisiontype.hpp"

class CollisionDatum {
public:
    TerrainCollisionType type;
    PlatformSegment segment;
    Pair position;
};

class EdgeCollision {
    public:
    PlatformSegment s1;
    PlatformSegment s2;
    Pair cornerPosition;
    Pair collisionLine1;
    Pair collisionLine2;
};

std::ostream& operator<<(std::ostream& strm, const CollisionDatum& p);


#endif