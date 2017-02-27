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

   public:
    Map(std::vector<Platform> platforms, std::vector<Ledge> ledges);
    void updateCollision(Player& player);
    void render(SDL_Renderer* r);

    bool getClosestCollision(Pair const& start,
                             Pair const& end,
                             CollisionDatum& out);

    bool getClosestEcbCollision(Ecb const& start,
                                Ecb const& end,
                                CollisionDatum& out);
};

#endif
