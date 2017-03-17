#include "physics.hpp"
#include "engine/pair.hpp"
#include "terrain/map.hpp"
#include "terraincollisiontype.hpp"

namespace Physics {

bool getClosestCollision(
    Map const & m,
    Pair const& start,
    Pair const& end,
    CollisionDatum& outputCollision,
    PlatformSegment& ignoredCollision,
    TerrainCollisionType expectedCollisionType) const {
    double closestDist = DOUBLE_INFINITY;
    PlatformSegment segment;
    Pair collisionPoint;
    bool anyCollision = false;

    for (Platform const& p : platforms) {
        TerrainCollisionType t = p.checkCollision(
            start, end, collisionPoint, segment, expectedCollisionType);

        if (t != expectedCollisionType) {
            continue;
        }

        if (segment == ignoredCollision && false) {
            out << "ignoring collision with platform because it was previously "
                   "collided with"
                << std::endl;
            out << ignoredCollision << std::endl;
            out << segment << std::endl;
            continue;
        }

        double distance = (collisionPoint - start).euclid();
        if (distance < closestDist) {
            closestDist = distance;
            outputCollision.type = t;
            outputCollision.segment = segment;
            outputCollision.position = collisionPoint;
            anyCollision = true;
        }
    }

    return anyCollision;
}

bool getClosestEdgeCollision(
        Map const & m,
        Pair const& a1,
        Pair const& a2,
        Pair const& b1,
        Pair const& b2,
        EdgeCollision& collision) const {
    for (Platform const& platform : platforms) {
        if (!platform.isPassable() &&
            platform.checkEdgeCollision(a1, a2, b1, b2, collision)) {
            return true;
        }
    }

    return false;
}

}

