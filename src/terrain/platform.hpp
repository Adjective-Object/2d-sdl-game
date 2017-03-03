#ifndef __TERRAIN_PLATFORM
#define __TERRAIN_PLATFORM

#include <SDL.h>
#include <vector>
#include "engine/pair.hpp"
#include "engine/entity.hpp"
#include "./platformsegment.hpp"
#include "./collisiontype.hpp"
#include "./collisiondatum.hpp"

class Platform : public Entity {
    friend class PlatformSegment;
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

    TerrainCollisionType checkCollision(Pair const& previous,
                                        Pair const& next,
                                        Pair& out,
                                        PlatformSegment& segment);

    bool checkEdgeCollision(Pair const& a1,
                            Pair const& a2,
                            Pair const& b1,
                            Pair const& b2,
                            Pair& collidedPoint,
                            Pair& collidedLine1,
                            Pair& collidedLine2);

    bool groundedMovement(Pair& position, Pair& distance);

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    void render(SDL_Renderer* r);
    bool isPassable();
    PlatformSegment getSegment(int index);

    static bool isWall(double angle);
    static bool isCeil(double angle);
};

#endif