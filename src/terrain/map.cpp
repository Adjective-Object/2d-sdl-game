#include "./map.hpp"
#include <iostream>
#include "constants.hpp"
#include "engine/game.hpp"
#include "engine/mesh/cube.hpp"
#include "engine/shader/meshshader.hpp"
#include "engine/util.hpp"
#include "map_movement.hpp"
#include "terrain/platform_point_iterator.hpp"
#include "terrain/platform_segment_iterator.hpp"
#include "util.hpp"
#include "widthbuf.hpp"

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// helpers for abusing template functions violently

using namespace Terrain;

#define _debug(...) \
    {}

// #define _debug(...) \
//    { __VA_ARGS__ }

widthstream Terrain::out(255, std::cout);

void Map::makeMapMesh() {
    std::vector<GLfloat>* meshPoints = new std::vector<GLfloat>();
    std::vector<GLfloat>* meshColors = new std::vector<GLfloat>();
    std::vector<WORLDSPACE_MESH_INDEX_TYPE>* meshIndecies =
        new std::vector<WORLDSPACE_MESH_INDEX_TYPE>();
    WORLDSPACE_MESH_INDEX_TYPE totalNumPoints = 0;
    size_t totalNumTris = 0;
    for (PlatformSegment p : getSegments()) {
        Pair a = *p.firstPoint();
        Pair b = *p.secondPoint();
        std::cout << p.getPlatform() << "  " << a << ".." << b << std::endl;

        meshPoints->push_back(a.x);
        meshPoints->push_back(a.y);
        meshPoints->push_back(0.5);

        meshPoints->push_back(a.x);
        meshPoints->push_back(a.y);
        meshPoints->push_back(-0.5);

        meshPoints->push_back(b.x);
        meshPoints->push_back(b.y);
        meshPoints->push_back(0.5);

        meshPoints->push_back(b.x);
        meshPoints->push_back(b.y);
        meshPoints->push_back(-0.5);

        for (size_t i = 0; i < 4; i++) {
            if (p.getPlatform()->isPassable()) {
                meshColors->push_back(0.39f);
                meshColors->push_back(0.30f);
                meshColors->push_back(1.0f);
            } else if (Platform::isCeil(p.angle())) {
                meshColors->push_back(0.78f);
                meshColors->push_back(0.117f);
                meshColors->push_back(0.117f);
            } else if (Platform::isWall(p.angle())) {
                meshColors->push_back(0.0f);
                meshColors->push_back(0.78f);
                meshColors->push_back(1.0f);
            } else {
                meshColors->push_back(0.5f);
                meshColors->push_back(0.5f);
                meshColors->push_back(0.5f);
            }
        }

        meshIndecies->push_back(totalNumPoints);
        meshIndecies->push_back(totalNumPoints + 1);
        meshIndecies->push_back(totalNumPoints + 2);

        meshIndecies->push_back(totalNumPoints + 2);
        meshIndecies->push_back(totalNumPoints + 1);
        meshIndecies->push_back(totalNumPoints + 3);

        totalNumPoints+=4;
        totalNumTris+=2;
    }

    std::cout << "=== MAP MESH ===" <<std::endl;
    std::cout << "meshPoints->size(): " << meshPoints->size() << std::endl;
    std::cout << "meshIndecies->size(): " << meshIndecies->size() << std::endl;
    std::cout << "totalNumTris: " << totalNumTris << std::endl;
    std::cout << "=== END MESH ===" << std::endl;   

    WorldspaceMesh* m = new WorldspaceMesh();
    m->init(&(*meshPoints)[0],         // verticies
            &(*meshIndecies)[0],       // indecies
            &(*meshColors)[0],         // colours
            NULL,                      // uvs
            (meshPoints->size()) / 3,  // num_verts
            totalNumTris               // num_tris
    );

    renderer = new MeshRenderer(&vertexColorShader, m);
}

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges) {}

#define PLATFORM_LAND_EPSILON 0.000001
bool Map::getClosestCollision(
    Pair const& start,
    Pair const& end,
    CollisionDatum& outputCollision,
    PlatformSegment& ignoredCollision,
    TerrainCollisionType expectedCollisionType) const {
    double closestDist = DOUBLE_INFINITY;
    PlatformSegment segment;
    bool anyCollision = false;

    for (PlatformSegment segment : getSegments()) {
        if (segment == ignoredCollision && false) {
            _debug(out << "ignoring collision with platform because it was "
                          "previously "
                          "collided with"
                       << std::endl;
                   out << ignoredCollision << std::endl;
                   out << segment << std::endl;);
            continue;
        }

        Pair p1 = *segment.firstPoint(), p2 = *segment.secondPoint(),
             intersectionPoint;
        int direction = checkLineIntersection(
            start, end, p1, p2, intersectionPoint, PLATFORM_LAND_EPSILON);

        if (direction >= 0)
            continue;

        double angle = segment.angle();
        switch (expectedCollisionType) {
            case CEIL_COLLISION:
                std::cout << "ceil coll! " << angle << "  "
                          << Platform::isCeil(angle) << std::endl;
                if (!Platform::isCeil(angle))
                    continue;
                break;
            case WALL_COLLISION:
                if (Platform::isCeil(angle) || !Platform::isWall(angle))
                    continue;
                break;
            case FLOOR_COLLISION:
                if (Platform::isCeil(angle) || Platform::isWall(angle))
                    continue;
                break;
            case NO_COLLISION:
                break;
        }

        double distance = (intersectionPoint - start).euclid();
        if (distance < closestDist) {
            closestDist = distance;
            outputCollision.type = expectedCollisionType;
            outputCollision.segment = segment;
            outputCollision.position = intersectionPoint;
            anyCollision = true;
        }
    }

    return anyCollision;
}

bool Map::getClosestEdgeCollision(Pair const& a1,
                                  Pair const& a2,
                                  Pair const& b1,
                                  Pair const& b2,
                                  EdgeCollision& collision,
                                  PlatformSegment* ignoredCollision) const {
    for (PlatformPoint const& p : getPoints()) {
        // TODO compare if multiple colls happen same frame?
        Pair point = p.point();
        if (p.getPlatform()->isPassable())
            continue;

        int direction =
            checkLineSweep(a1, a2, b1, b2, point, collision.collisionLine1,
                           collision.collisionLine2);

        if (direction != -1)
            continue;

        if (ignoredCollision != NULL &&
            (point == *ignoredCollision->firstPoint() ||
             point == *ignoredCollision->secondPoint())) {
            continue;
            std::cout << "ignoring this platform, i'm standing on it!"
                      << std::endl;
        }

        collision.cornerPosition = point;
        collision.s1 = p.firstSegment();
        collision.s2 = p.secondSegment();
        return true;
    }

    return false;
}

void basicProjection(Player& player,
                     Pair& requestedDistance,
                     Pair& projectedPosition,
                     PlatformMovementState& ms) {
    if (player.isGrounded()) {
        // move player along platform
        projectedPosition = player.position;
        if (!ms.initialized) {
            if (!player.getCurrentPlatform()->initGroundedMovement(
                    projectedPosition, requestedDistance, ms)) {
                requestedDistance = Pair(0, 0);
                return;
            }
        }

        if (!ms.platform->stepGroundedMovement(projectedPosition,
                                               requestedDistance, ms)) {
            if (requestedDistance.euclidSquared() > 0) {
                if (player.canFallOff()) {
                    player.fallOffPlatform();
                } else {
                    requestedDistance = Pair(0, 0);
                }
            }
        }

    }

    // if the player is not grounded, just move them according to requested
    // movement
    else {
        projectedPosition = player.position + requestedDistance;
        requestedDistance = Pair(0, 0);
    }
}

void Map::moveRecursive(Player& player,
                        Ecb& currentEcb,
                        Ecb& projectedEcb) const {
    // ecb after resolving the next step of motion
    Ecb nextStepEcb = projectedEcb;

    _debug(out.indent(4); out << std::endl;
           out << "===========================" << std::endl;
           out << "moveRecursive" << std::endl;
           out << "    " << currentEcb << std::endl;
           out << "    " << projectedEcb << std::endl;);

#define debugEcb()                                             \
    {                                                          \
        out << "currentEcb   : " << currentEcb << std::endl;   \
        out << "nextStepEcb  : " << nextStepEcb << std::endl;  \
        out << "projectedEcb : " << projectedEcb << std::endl; \
    }

#define debugTmpEcb()                                                \
    {                                                                \
        out << "currentEcb      : " << currentEcb << std::endl;      \
        out << "tmpNextStepEcb  : " << tmpNextStepEcb << std::endl;  \
        out << "tmpProjectedEcb : " << tmpProjectedEcb << std::endl; \
    };

#define overrideEcbs(name, type, side)                                \
    {                                                                 \
        _debug(out << "---- " << name << std::endl;);                 \
        if (!(tmpProjectedEcb.origin == projectedEcb.origin) &&       \
            (thisProjectedDistance < currentClosestDistance ||        \
             (thisProjectedDistance == currentClosestDistance &&      \
              thisPriority > currentPriority))) {                     \
            _debug(out << "updated current predictions" << std::endl; \
                   out << thisProjectedDistance << " < "              \
                       << currentClosestDistance << std::endl;);      \
            closestCollisionPointEcb = tmpCollisionPointEcb;          \
            closestNextStepEcb = tmpNextStepEcb;                      \
            closestProjectedEcb = tmpProjectedEcb;                    \
            closestLastWallCollision = tmpLastWallCollision;          \
            currentClosestDistance = thisProjectedDistance;           \
            currentPriority = thisPriority;                           \
            e = type;                                                 \
            debugTmpEcb();                                            \
        } else {                                                      \
            _debug(out << "ignoring, current is closer" << std::endl; \
                   out << thisProjectedDistance << " > "              \
                       << currentClosestDistance << std::endl;);      \
        }                                                             \
        _debug(out << "----" << std::endl;);                          \
    }

    PlatformSegment lastWallCollision = PlatformSegment(NULL, -1);

    int iterationCount = 0;
    do {
        // panic state
        iterationCount++;
        if (iterationCount > 10) {
            _debug(out << "panicing and exiting on iteration " << iterationCount
                       << std::endl;
                   // exit(1);
                   out.indent(-4););
            return;
        }

        _debug(out << std::endl;
               out << "---------------------------" << std::endl; debugEcb();
               out << "---------------------------" << std::endl;);

        double currentClosestDistance = DOUBLE_INFINITY;
        double thisProjectedDistance = DOUBLE_INFINITY;
        int currentPriority = 0, thisPriority;
        Ecb closestCollisionPointEcb = nextStepEcb;
        Ecb closestNextStepEcb = nextStepEcb;
        Ecb closestProjectedEcb = projectedEcb;

        Ecb tmpCollisionPointEcb = currentEcb;
        Ecb tmpNextStepEcb = nextStepEcb;
        Ecb tmpProjectedEcb = projectedEcb;
        PlatformSegment closestLastWallCollision = lastWallCollision;
        PlatformSegment tmpLastWallCollision = lastWallCollision;

        ENVIRONMENT_COLLISION_TYPE e = NO_ENVIRONMENT_COLLISION;

        // we make movements in short segments.
        // each of these collisions will optionally update nextStepEcb if they
        // are closer than the original ecb

        const Platform* currentPlatform = NULL;
        Player const& player_const = player;

        // perform right wall collision
        if ((thisPriority = rightWallCollision(
                 *this, player_const, Pair(1, 0), tmpCollisionPointEcb,
                 tmpNextStepEcb, tmpProjectedEcb, thisProjectedDistance,
                 tmpLastWallCollision))) {
            overrideEcbs("Right Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // perform left wall collision
        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        tmpLastWallCollision = lastWallCollision;
        if ((thisPriority = leftWallCollision(
                 *this, player_const, Pair(-1, 0), tmpCollisionPointEcb,
                 tmpNextStepEcb, tmpProjectedEcb, thisProjectedDistance,
                 tmpLastWallCollision))) {
            overrideEcbs("Left Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // // perform ceiling collision
        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        tmpLastWallCollision = lastWallCollision;
        if ((thisPriority = ceilingCollision(
                 *this, player_const, Pair(0, -1), tmpCollisionPointEcb,
                 tmpNextStepEcb, tmpProjectedEcb, thisProjectedDistance,
                 tmpLastWallCollision))) {
            overrideEcbs("Ceiling collision", ENVIRONMENT_CEIL_COLLISION,
                         origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if ((thisPriority = topRightEdgeCollision(
                 *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                 tmpProjectedEcb, thisProjectedDistance))) {
            overrideEcbs("Top Right Edge collision", ENVIRONMENT_EDGE_COLLISION,
                         origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if ((thisPriority = bottomRightEdgeCollision(
                 *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                 tmpProjectedEcb, thisProjectedDistance))) {
            overrideEcbs("Bottom Right Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if ((thisPriority = bottomLeftEdgeCollision(
                 *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                 tmpProjectedEcb, thisProjectedDistance))) {
            overrideEcbs("Bottom Left Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if ((thisPriority = topRightEdgeCollision(
                 *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                 tmpProjectedEcb, thisProjectedDistance))) {
            overrideEcbs("Bottom Left Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if ((thisPriority = topLeftEdgeCollision(
                 *this, player_const, tmpCollisionPointEcb, tmpNextStepEcb,
                 tmpProjectedEcb, thisProjectedDistance))) {
            overrideEcbs("Top Left Edge collision", ENVIRONMENT_EDGE_COLLISION,
                         origin);
        }

        if (!player.isGrounded()) {
            // perform this collision last so that we can call player::land()
            // without it being overridden
            tmpCollisionPointEcb = currentEcb;
            tmpNextStepEcb = nextStepEcb;
            tmpProjectedEcb = projectedEcb;
            if (performFloorCollision(*this, player, tmpCollisionPointEcb,
                                      tmpNextStepEcb, tmpProjectedEcb,
                                      currentPlatform, thisProjectedDistance)) {
                overrideEcbs("Floor Collision", ENVIRONMENT_FLOOR_COLLISION,
                             bottom);
            }
        }

        // this only works because landing terminates collision
        if (e == ENVIRONMENT_FLOOR_COLLISION) {
            player.land(currentPlatform);
        }

        // recursively update this step of motion if we were interrupted
        if (currentClosestDistance != DOUBLE_INFINITY &&
            closestNextStepEcb.origin != projectedEcb.origin) {
            _debug(out << "######## movement was interrupted, recursing!"
                       << std::endl;);
            // start the recursive walk at the position of the collision
            currentEcb = closestCollisionPointEcb;
            Ecb predictedNextStepEcb = closestNextStepEcb;
            moveRecursive(player, currentEcb, closestNextStepEcb);
            if (predictedNextStepEcb.origin != closestNextStepEcb.origin) {
                // the other motion interrupted this motion, so
                // our projected ECB is no longer valid. The recursive call
                // will have resolved motion ,so we break;
                _debug(out << "recursive walk changed projected ECB"
                           << std::endl;
                       out << "breaking loop" << std::endl;);
                // currentEcb = closestNextStepEcb;
                break;
            }
        } else {
            // otherwise, just jump the player to the next step of their motion
            // this will be the projected ecb
            currentEcb = closestNextStepEcb;
        }
        lastWallCollision = closestLastWallCollision;
        nextStepEcb = closestProjectedEcb;
        projectedEcb = closestProjectedEcb;

    } while (currentEcb.origin != projectedEcb.origin);

    _debug(out << "resolving: " << currentEcb << std::endl;
           out << "===========================" << std::endl; out.indent(-4););
}

void Map::movePlayer(Player& player, Pair& requestedDistance) const {
    // TODO think about ledge grabbing
    grabLedges(player);

    _debug(out << "===========================" << std::endl;
           out << "===========================" << std::endl;
           out << "===========================" << std::endl;
           out << "requested distance: " << requestedDistance << std::endl;
           out << "grounded? " << player.isGrounded() << std::endl;);

    if (requestedDistance.x == 0 && requestedDistance.y == 0)
        return;

    // if the player is grounded, move them along the platform
    Pair projectedPosition = player.position;
    PlatformMovementState movementState;
    while (requestedDistance != Pair(0, 0)) {
        _debug(out << "++++++++++++++++++" << std::endl;);
        basicProjection(player, requestedDistance, projectedPosition,
                        movementState);
        // motion state has 3 components.
        // current position
        Ecb currentEcb = player.currentCollision->playerModified;
        // eventual ecb after resolving all motion
        Ecb projectedEcb = player.currentCollision->postCollision;
        projectedEcb.setOrigin(projectedPosition + PLAYER_ECB_OFFSET);
        player.currentCollision->root.setOrigin(projectedPosition +
                                                PLAYER_ECB_OFFSET);
        player.currentCollision->playerModified.setOrigin(projectedPosition +
                                                          PLAYER_ECB_OFFSET);

        _debug(out << "remaining distance after motion: " << requestedDistance
                   << std::endl;
               out << "projected pos:      " << projectedPosition
                   << std::endl;);

        moveRecursive(player, currentEcb, projectedEcb);

        // reset player position to the projected Ecb
        player.moveTo(currentEcb);
    }
}

void Map::grabLedges(Player& player) const {
    if (!player.canGrabLedge())
        return;

    for (Ledge const& l : ledges) {
        Pair ledgebox_position = player.position + Pair(0, -LEDGEBOX_BASE);
        Pair diff = l.position - ledgebox_position;
        if (sign(diff.x) == sign(player.face) && player.face != l.facing &&
            std::abs(diff.x) < LEDGEBOX_WIDTH && diff.y > -LEDGEBOX_HEIGHT &&
            diff.y < 0) {
            player.grabLedge(&l);
            return;
        }
    }
}

Platform* Map::getPlatform(size_t index) {
    return &(platforms[index]);
}

IteratorChain<PlatformPointArray> Map::getPoints() const {
    std::vector<PlatformPointArray> arrays;
    for (Platform const& p : platforms) {
        arrays.push_back(p.points_iter());
    }
    return IteratorChain<PlatformPointArray>(arrays);
}

IteratorChain<PlatformSegmentArray> Map::getSegments() const {
    std::vector<PlatformSegmentArray> arrays;
    for (Platform const& p : platforms) {
        arrays.push_back(p.segments_iter());
    }
    return IteratorChain<PlatformSegmentArray>(arrays);
}

void Map::init() {
    makeMapMesh();
}
void Map::preUpdate() {}
void Map::update() {}
void Map::postUpdate() {}

AbstractRenderer* Map::getRenderer() {
    return renderer;
}
