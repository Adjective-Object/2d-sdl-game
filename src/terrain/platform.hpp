#ifndef __TERRAIN_PLATFORM
#define __TERRAIN_PLATFORM

#include <SDL.h>
#include <vector>
#include "engine/pair.hpp"
#include "engine/entity.hpp"
#include "./collisiontype.hpp"

class Platform : public Entity {
    std::vector<Pair> points;
    std::vector<double> angles;
    std::vector<double> lengths;
    bool passable;

   public:
    Platform(std::vector<Pair> points, bool passable = false);
    ~Platform();

    static Pair movePointToSegmentSpace(Pair& platformPair,
                                        double platformAngle,
                                        Pair& otherPair);

    TerrainCollisionType checkCollision(Pair& previous, Pair& next, Pair& out);
    bool groundedMovement(Pair& position, Pair& velocity);

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    void render(SDL_Renderer* r);
    bool isPassable();
    static bool isWall(double angle);
};

#endif