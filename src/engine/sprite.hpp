#ifndef __ENGINE_SPRITE
#define __ENGINE_SPRITE

#include <SDL.h>
#include <limits>
#include "util.hpp"
#include "entity.hpp"
#include "pair.hpp"


typedef enum Direction {
    UP, DOWN, LEFT, RIGHT
} Direction;

class Sprite : public Entity {
public:
    double angle = 0;
    double angularVelocity = 0;
    double angularAcceleration = 0;
    double angularDrag = 0;

    Pair position = Pair(0, 0);
    Pair velocity = Pair(0, 0);
    Pair acceleration = Pair(0, 0);

    Pair drag = Pair(0, 0);

    Pair maxVelocity = Pair(DOUBLE_INFINITY, DOUBLE_INFINITY);
    double maxAngular = DOUBLE_INFINITY;

    Direction facing;

    Sprite();
    ~Sprite();
    virtual void update() override;
    virtual void preUpdate() override;
    virtual void postUpdate() override;
    void updateMotion();
    virtual void render(SDL_Renderer * ren) override;
};

#endif
