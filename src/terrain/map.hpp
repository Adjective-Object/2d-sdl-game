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

   public:
    Map(std::vector<Platform> platforms, std::vector<Ledge> ledges);
    void movePlayer(Player& player, Pair& requestedDistance);
    void render(SDL_Renderer* r);

    bool getClosestCollision(Pair const& start,
                             Pair const& end,
                             CollisionDatum& out);

    bool getClosestEcbCollision(Ecb const& start,
                                Ecb const& end,
                                CollisionDatum& out);

    Platform* getPlatform(size_t index);
};

#endif
