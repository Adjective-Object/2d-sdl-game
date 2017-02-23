#ifndef __GAME_LEDGE
#define __GAME_LEDGE

#include <SDL.h>
#include "engine/pair.hpp"
#include "facing.hpp"

// forward declare map class
class Ledge {
    Pair position;
    Facing facing;

   public:
    Ledge(Pair position, Facing facing);
    void render(SDL_Renderer* r);
};

#endif