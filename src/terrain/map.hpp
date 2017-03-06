#ifndef __GAME_MAP
#define __GAME_MAP

#include <vector>
#include "player/player.hpp"
#include "./platform.hpp"
#include "./ledge.hpp"
#include "./collisiondatum.hpp"

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

    void grabLedges(Player& player);

    template <Pair const& (*getEcbSide)(Ecb const&),
              void (*setEcbSide)(Ecb&, Pair const pos),
              double (*x)(Pair const& pos),
              double (*y)(Pair const& pos),
              void (*setNonblockingAxis)(Pair& pos, double value)>
    bool performWallCollision(Player const& player,
                              const Pair expectedDirection,
                              Ecb& currentEcb,
                              Ecb& nextStepEcb,
                              Ecb& projectedEcb,
                              double& distance);

    template <Pair const& (*getForwardEdge)(Ecb const&),
              Pair const& (*getBackEdge)(Ecb const&),
              void (*setForwardEdge)(Ecb&, Pair const pos)>
    bool performWallEdgeCollision(Player const& player,
                                  Ecb& currentEcb,
                                  Ecb& nextStepEcb,
                                  Ecb& projectedEcb,
                                  double& distance);

    bool performFloorCollision(Player& player,
                               Ecb& currentEcb,
                               Ecb& nextStepEcb,
                               Ecb& projectedEcb,
                               Platform*& collidedPlatform,
                               double& distance);

   public:
    Map(std::vector<Platform> platforms, std::vector<Ledge> ledges);
    void movePlayer(Player& player, Pair& requestedDistance);
    void moveRecursive(Player& player, Ecb& currentEcb, Ecb& projectedEcb);
    void render(SDL_Renderer* r);

    bool getClosestCollision(Pair const& start,
                             Pair const& end,
                             CollisionDatum& out,
                             Platform* ignoredPlatform = NULL);

    bool getClosestEdgeCollision(Pair const& a1,
                                 Pair const& a2,
                                 Pair const& b1,
                                 Pair const& b2,
                                 EdgeCollision& out);

    bool getClosestEcbCollision(Ecb const& start,
                                Ecb const& end,
                                CollisionDatum& out);

    Platform* getPlatform(size_t index);
};
}
#endif
