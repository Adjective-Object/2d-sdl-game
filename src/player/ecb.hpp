#ifndef __PLAYER_ECB
#define __PLAYER_ECB
#include <SDL.h>
#include "engine/pair.hpp"

#define ECB_DEFAULT_WIDTH 0.06
#define ECB_DEFAULT_HEIGHT 0.1

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
    Pair origin, left, right, top, bottom;
    double widthLeft, widthRight, heightTop, heightBottom;

    Ecb();
    Ecb(Pair origin);
    Ecb(Pair origin, double width, double height);
    Ecb(Pair origin,
        double widthLeft,
        double heightTop,
        double widthRight,
        double heightBottom);

    void setOrigin(Pair origin);
    void setRight(Pair right);
    void setLeft(Pair left);
    void setBottom(Pair bottom);
    void setTop(Pair top);
    void render(SDL_Renderer* r, double scale);
};

std::ostream& operator<<(std::ostream& strm, const Ecb& p);

#endif