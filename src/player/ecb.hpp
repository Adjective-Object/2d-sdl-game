#ifndef __PLAYER_ECB
#define __PLAYER_ECB
#include <SDL.h>
#include "engine/pair.hpp"

/**
 * Class for managing environemnt collision box
 *
 * the ECB is a quadrilateral with a fixed center relative to the player
 * origin, which is typically a trapezid during normal movement
 *
 * It is usually controlled by animated points on the skeleton, but as
 * we do not at preset have a skeleton to animate off of , it is manually
 * controlled by the player class.
 */
class Ecb {
   public:
    Pair origin;
    Pair left;
    Pair right;
    Pair bottom;
    Pair top;

    Ecb();
    Ecb(Pair origin);
    Ecb(Pair origin, double width, double height);
    Ecb(Pair origin,
        double widthLeft,
        double heightTop,
        double widthRight,
        double heightBottom);

    void setOrigin(Pair origin);
    void render(SDL_Renderer* r, double scale);
};

#endif