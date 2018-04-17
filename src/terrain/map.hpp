#ifndef __GAME_MAP
#define __GAME_MAP

#include <vector>
#include "./collisiondatum.hpp"
#include "./ledge.hpp"
#include "./platform.hpp"
#include "engine/entity.hpp"
#include "engine/renderer/meshrenderer.hpp"
#include "iterator_wrapper.hpp"
#include "player/player.hpp"
#include "widthbuf.hpp"

namespace Terrain {

typedef enum ENVIRONMENT_COLLISION_TYPE {
    NO_ENVIRONMENT_COLLISION,
    ENVIRONMENT_WALL_COLLISION,
    ENVIRONMENT_EDGE_COLLISION,
    ENVIRONMENT_CEIL_COLLISION,
    ENVIRONMENT_FLOOR_COLLISION,
} ENVIRONMENT_COLLISION_TYPE;

class Map : public Entity {
    std::vector<Platform> platforms;
    std::vector<Ledge> ledges;
    MeshRenderer* renderer;

    void grabLedges(Player& player) const;
    void makeMapMesh();

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

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    AbstractRenderer* getRenderer();
};

extern widthstream out;
}  // namespace Terrain

#endif
