#ifndef __ENGINE_SPRITE
#define __ENGINE_SPRITE

#include <SDL.h>

#include "pair.hpp"

class Entity {
public:
    virtual ~Entity();
    virtual void init() = 0;
    virtual void update(long elapsed_millis) = 0;
    virtual void render(SDL_Renderer * ren) = 0;
};


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
