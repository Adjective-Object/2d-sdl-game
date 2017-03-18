#ifndef __GAME_MAP
#define __GAME_MAP

#include <vector>
#include "player/player.hpp"
#include "./platform.hpp"
#include "./ledge.hpp"
#include "./collisiondatum.hpp"
#include "widthbuf.hpp"
#include "iterator_wrapper.hpp"

namespace Terrain {

typedef enum ENVIRONMENT_COLLISION_TYPE {
    NO_ENVIRONMENT_COLLISION,
    ENVIRONMENT_WALL_COLLISION,
    ENVIRONMENT_EDGE_COLLISION,
    ENVIRONMENT_CEIL_COLLISION,
    ENVIRONMENT_FLOOR_COLLISION,
} ENVIRONMENT_COLLISION_TYPE;

class Map {
    std::vector<Platform> platforms;
    std::vector<Ledge> ledges;

    void grabLedges(Player& player) const;

   public:
    Map(std::vector<Platform> platforms, std::vector<Ledge> ledges);
    void movePlayer(Player& player, Pair& requestedDistance) const;
    void moveRecursive(Player& player,
                       Ecb& currentEcb,
                       Ecb& projectedEcb) const;

    bool getClosestCollision(
        Pair const& start,
        Pair const& end,
        CollisionDatum& out,
        PlatformSegment& ignoredSegment,
        TerrainCollisionType expectedEnvironmentCollision) const;

    bool getClosestEdgeCollision(Pair const& a1,
                                 Pair const& a2,
                                 Pair const& b1,
                                 Pair const& b2,
                                 EdgeCollision& out,
                                 PlatformSegment* ignored) const;

    Platform* getPlatform(size_t index);

    IteratorChain<PlatformPointArray> getPoints() const;
    IteratorChain<PlatformSegmentArray> getSegments() const;
};

extern widthstream out;
}

#endif
