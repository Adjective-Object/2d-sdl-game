#ifndef __TERRAIN_PLATFORM
#define __TERRAIN_PLATFORM

#include <SDL.h>
#include <vector>
#include "./collisiondatum.hpp"
#include "./collisiontype.hpp"
#include "./platform_movement.hpp"
#include "./platform_point_iterator.hpp"
#include "./platform_segment_iterator.hpp"
#include "./platformpoint.hpp"
#include "./platformsegment.hpp"
#include "engine/entity.hpp"
#include "engine/pair.hpp"

class Platform : public Entity {
    friend class PlatformSegment;
    friend class PlatformPoint;
    friend class PlatformPointArray;
    friend class PlatformSegmentArray;
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

    bool checkEdgeCollision(Pair const& a1,
                            Pair const& a2,
                            Pair const& b1,
                            Pair const& b2,
                            EdgeCollision& collision) const;

    bool groundedMovement(Pair& position, Pair& distance) const;

    bool stepGroundedMovement(Pair& position,
                              Pair& distance,
                              PlatformMovementState&) const;
    bool initGroundedMovement(Pair& position,
                              Pair& velocity,
                              PlatformMovementState& out) const;

    void init();
    void preUpdate();
    void update();
    void postUpdate();
    void render(SDL_Renderer* r);
    bool isPassable() const;
    PlatformSegment getSegment(int index) const;
    size_t getSegmentIndexByLocation(Pair position, int direction = 0) const;

    static bool isWall(double angle);
    static bool isCeil(double angle);

    PlatformSegmentArray segments_iter() const;
    PlatformPointArray points_iter() const;
};

#endif
