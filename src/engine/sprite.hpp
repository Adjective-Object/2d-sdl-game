#ifndef __ENGINE_SPRITE
#define __ENGINE_SPRITE

#include <SDL.h>
#include "entity.hpp"
#include "pair.hpp"

typedef enum Direction {
    UP, DOWN, LEFT, RIGHT
} Direction;

class Sprite : public Entity {
public:
    double rotation;
    Pair position = Pair(0, 0);
    Pair velocity = Pair(0, 0);
    Pair acceleration = Pair(0, 0);

    Direction facing;

    Sprite();
    ~Sprite();
    void update(double timeStep);
    void render(SDL_Renderer * ren);
};

#endif
