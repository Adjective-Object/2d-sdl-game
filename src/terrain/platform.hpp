#ifndef __TERRAIN_PLATFORM
#define __TERRAIN_PLATFORM

#include <SDL.h>
#include <vector>
#include "../engine/pair.hpp"
#include "../engine/entity.hpp"

class Platform : public Entity {
    std::vector<Pair> points;
    std::vector<double> angles;
    std::vector<double> lengths;

   public:
    Platform(std::vector<Pair> points);
    ~Platform();

    Pair movePointToSegmentSpace(Pair& platformPair,
                                 double platformAngle,
                                 Pair& otherPair);

    bool checkCollision(Pair& previous, Pair& next, double* out);
    bool groundedMovement(Pair& position, Pair& velocity);

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    void render(SDL_Renderer* r);
};

#endif