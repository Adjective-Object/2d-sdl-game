#ifndef __GAME_MAP
#define __GAME_MAP

#include <vector>
#include "player/player.hpp"
#include "./platform.hpp"
#include "./ledge.hpp"
#include "./collisiondatum.hpp"

class Map {
    std::vector<Platform> platforms;
    std::vector<Ledge> ledges;

    void grabLedges(Player& player);

    template <TerrainCollisionType expectedType,
              Pair& (*getEcbSide)(Ecb*),
              void (*setEcbSide)(Ecb*, Pair pos),
              double (*getBlockingAxis)(Pair& pos),
              double (*getNonblockingAxis)(Pair& pos),
              void (*setNonblockingAxis)(Pair& pos, double value)>
    bool performWallCollision(Player& player,
                              Ecb*& currentEcb,
                              Ecb*& projectedEcb);

    template <Pair& (*getForwardEdge)(Ecb*),
              Pair& (*getBackEdge)(Ecb*),
              void (*setForwardEdge)(Ecb*, Pair pos)>
    bool performWallEdgeCollision(Player& player,
                                  Ecb*& currentEcb,
                                  Ecb*& projectedEcb);

   public:
    Map(std::vector<Platform> platforms, std::vector<Ledge> ledges);
    void movePlayer(Player& player, Pair& requestedDistance);
    void render(SDL_Renderer* r);

    bool getClosestCollision(Pair const& start,
                             Pair const& end,
                             CollisionDatum& out,
                             Platform* ignoredPlatform = NULL);

    bool getClosestEdgeCollision(Pair const& a1,
                                 Pair const& a2,
                                 Pair const& b1,
                                 Pair const& b2,
                                 Pair& out,
                                 Pair& collidedLine1,
                                 Pair& collidedLine2);

    bool getClosestEcbCollision(Ecb const& start,
                                Ecb const& end,
                                CollisionDatum& out);

    Platform* getPlatform(size_t index);
};

#endif
