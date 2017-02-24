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

    TerrainCollisionType checkCollision(Pair const& previous, Pair const& next, Pair& out, int & segmentNo);

    bool groundedMovement(Pair& position, Pair& velocity);

    // move from start to destination, clamping x at wall.
    // returns the endpoint of the traversal
    Pair moveAlongWall(Pair const& start, Pair const& destination, int segmentNo);

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    void render(SDL_Renderer* r);
    bool isPassable();
    static bool isWall(double angle);
};

#endif