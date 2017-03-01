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

    template <Pair& (*getEcbSide)(Ecb*), void (*setEcbSide)(Ecb*, Pair pos)>
    void performWallCollision(Player& player,
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

    bool getClosestEcbCollision(Ecb const& start,
                                Ecb const& end,
                                CollisionDatum& out);

    Platform* getPlatform(size_t index);
};

#endif
