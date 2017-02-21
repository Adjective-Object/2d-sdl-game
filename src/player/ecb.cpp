#include "ecb.hpp"
#include "engine/pair.hpp"

#define ECB_DEFAULT_WIDTH 0.06
#define ECB_DEFAULT_HEIGHT 0.09

#define _left(length) left(origin + Pair(-length, 0))
#define _right(length) right(origin + Pair(+length, 0))
#define _top(length) top(origin + Pair(0, -length))
#define _bottom(length) bottom(origin + Pair(0, length))

Ecb::Ecb()
    : origin(Pair(0, 0)),
      _left(ECB_DEFAULT_WIDTH),
      _right(ECB_DEFAULT_WIDTH),
      _top(ECB_DEFAULT_HEIGHT),
      _bottom(ECB_DEFAULT_HEIGHT) {}

Ecb::Ecb(Pair origin)
    : origin(origin),
      _left(ECB_DEFAULT_WIDTH),
      _right(ECB_DEFAULT_WIDTH),
      _top(ECB_DEFAULT_HEIGHT),
      _bottom(ECB_DEFAULT_HEIGHT) {}

Ecb::Ecb(Pair origin, double width, double height)
    : origin(origin),
      _left(width),
      _right(width),
      _top(height),
      _bottom(height) {}

Ecb::Ecb(Pair origin,
         double widthLeft,
         double heightTop,
         double widthRight,
         double heightBottom)
    : origin(origin),
      _left(widthLeft),
      _right(widthRight),
      _top(heightTop),
      _bottom(heightBottom) {}

void Ecb::setOrigin(Pair newOrigin) {
    Pair delta = newOrigin - origin;
    origin = newOrigin;
    left += delta;
    right += delta;
    top += delta;
    bottom += delta;
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