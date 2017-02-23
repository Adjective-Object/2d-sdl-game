#include "ecb.hpp"
#include "engine/pair.hpp"

#define ECB_DEFAULT_WIDTH 0.06
#define ECB_DEFAULT_HEIGHT 0.1

#define _left(length) left(origin + Pair(-length, 0))
#define _right(length) right(origin + Pair(+length, 0))
#define _top(length) top(origin + Pair(0, -length))
#define _bottom(length) bottom(origin + Pair(0, length))

Ecb::Ecb() : Ecb(Pair(0, 0)) {}

Ecb::Ecb(Pair origin) : Ecb(origin, ECB_DEFAULT_WIDTH, ECB_DEFAULT_HEIGHT) {}

Ecb::Ecb(Pair origin, double width, double height)
    : Ecb(origin,
          ECB_DEFAULT_WIDTH,
          ECB_DEFAULT_HEIGHT,
          ECB_DEFAULT_WIDTH,
          ECB_DEFAULT_HEIGHT) {}

Ecb::Ecb(Pair origin,
         double widthLeft,
         double heightTop,
         double widthRight,
         double heightBottom)
    : origin(origin),
      _left(widthLeft),
      _right(widthRight),
      _top(heightTop),
      _bottom(heightBottom),
      widthLeft(widthLeft),
      widthRight(widthRight),
      heightTop(heightTop),
      heightBottom(heightBottom) {}

void Ecb::setOrigin(Pair newOrigin) {
    origin = newOrigin;
    left = newOrigin + Pair(-widthLeft, 0);
    right = newOrigin + Pair(widthRight, 0);
    top = newOrigin + Pair(0, -heightTop);
    bottom = newOrigin + Pair(0, heightBottom);
}

void Ecb::render(SDL_Renderer* ren, double SCALE) {
    SDL_RenderDrawLine(ren, (int)(SCALE * left.x), (int)(SCALE * left.y),
                       (int)(SCALE * top.x), (int)(SCALE * top.y));

    SDL_RenderDrawLine(ren, (int)(SCALE * left.x), (int)(SCALE * left.y),
                       (int)(SCALE * bottom.x), (int)(SCALE * bottom.y));

    SDL_RenderDrawLine(ren, (int)(SCALE * right.x), (int)(SCALE * right.y),
                       (int)(SCALE * top.x), (int)(SCALE * top.y));

    SDL_RenderDrawLine(ren, (int)(SCALE * right.x), (int)(SCALE * right.y),
                       (int)(SCALE * bottom.x), (int)(SCALE * bottom.y));
}