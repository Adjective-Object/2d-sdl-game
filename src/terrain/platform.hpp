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

    TerrainCollisionType checkCollision(
        Pair const& previous,
        Pair const& next,
        Pair& out,
        PlatformSegment& segment,
        TerrainCollisionType expectedCollisionType) const;

    bool checkEdgeCollision(Pair const& a1,
                            Pair const& a2,
                            Pair const& b1,
                            Pair const& b2,
                            EdgeCollision& collision) const;

    bool groundedMovement(Pair& position, Pair& distance) const;

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    void render(SDL_Renderer* r);
    bool isPassable() const;
    PlatformSegment getSegment(int index) const;

    static bool isWall(double angle);
    static bool isCeil(double angle);
};

#endif
