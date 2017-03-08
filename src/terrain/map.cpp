#include "./map.hpp"
#include "util.hpp"
#include "engine/util.hpp"
#include "constants.hpp"
#include <iostream>
#include "engine/game.hpp"
#include "widthbuf.hpp"
#include "map_movement.hpp"

// helpers for abusing template functions violently

using namespace Terrain;

widthstream Terrain::out(255, std::cout);

Map::Map(std::vector<Platform> platforms, std::vector<Ledge> ledges)
    : platforms(platforms), ledges(ledges){};

bool Map::getClosestCollision(
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

        if (segment == ignoredCollision) {
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

bool Map::getClosestEdgeCollision(Pair const& a1,
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

void basicProjection(Player& player,
                     Pair& requestedDistance,
                     Pair& projectedPosition) {
    if (player.isGrounded()) {
        // move player along platform
        projectedPosition = player.position;
        player.getCurrentPlatform()->groundedMovement(projectedPosition,
                                                      requestedDistance);

        if (requestedDistance.euclidSquared() > 0) {
            player.fallOffPlatform();
        }

        // add remaining distnace (for falling)
        projectedPosition += requestedDistance;
    }

    // if the player is not grounded, just move them according to requested
    // movement
    else {
        projectedPosition = player.position + requestedDistance;
    }
}

void Map::moveRecursive(Player& player,
                        Ecb& currentEcb,
                        Ecb& projectedEcb) const {
    // ecb after resolving the next step of motion
    Ecb nextStepEcb = projectedEcb;

    out.indent(4);

    out << std::endl;
    out << "===========================" << std::endl;
    out << "moveRecursive" << std::endl;
    out << "    " << currentEcb << std::endl;
    out << "    " << projectedEcb << std::endl;

#define debugEcb()                                             \
    {                                                          \
        out << "currentEcb   : " << currentEcb << std::endl;   \
        out << "nextStepEcb  : " << nextStepEcb << std::endl;  \
        out << "projectedEcb : " << projectedEcb << std::endl; \
    };

#define debugTmpEcb()                                                \
    {                                                                \
        out << "currentEcb      : " << currentEcb << std::endl;      \
        out << "tmpNextStepEcb  : " << tmpNextStepEcb << std::endl;  \
        out << "tmpProjectedEcb : " << tmpProjectedEcb << std::endl; \
    };

#define overrideEcbs(name, type, side)                                      \
    {                                                                       \
        out << "---- " << name << std::endl;                                \
        if (thisProjectedDistance < currentClosestDistance) {               \
            out << "updated current predictions" << std::endl;              \
            out << thisProjectedDistance << " < " << currentClosestDistance \
                << std::endl;                                               \
            closestCollisionPointEcb = tmpCollisionPointEcb;                \
            closestNextStepEcb = tmpNextStepEcb;                            \
            closestProjectedEcb = tmpProjectedEcb;                          \
            closestLastWallCollision = tmpLastWallCollision;                \
            currentClosestDistance = thisProjectedDistance;                 \
            e = type;                                                       \
            debugTmpEcb();                                                  \
        } else {                                                            \
            out << "ignoring, current is closer" << std::endl;              \
            out << thisProjectedDistance << " > " << currentClosestDistance \
                << std::endl;                                               \
        }                                                                   \
        out << "----" << std::endl;                                         \
    }

    PlatformSegment lastWallCollision = PlatformSegment(NULL, -1);

    int iterationCount = 0;
    do {
        // panic state
        iterationCount++;
        if (iterationCount > 10) {
            out << "panicing and exiting on iteration " << iterationCount
                << std::endl;
            // exit(1);
            // out << indent_manip::pop;
            out.indent(-4);
            return;
        }

        out << std::endl;
        out << "---------------------------" << std::endl;
        debugEcb();
        out << "---------------------------" << std::endl;

        double currentClosestDistance = DOUBLE_INFINITY;
        double thisProjectedDistance = DOUBLE_INFINITY;
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
        if (rightWallCollision(*this, player_const, Pair(1, 0),
                               tmpCollisionPointEcb, tmpNextStepEcb,
                               tmpProjectedEcb, thisProjectedDistance,
                               tmpLastWallCollision)) {
            overrideEcbs("Right Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // perform left wall collision
        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        tmpLastWallCollision = lastWallCollision;
        if (leftWallCollision(*this, player_const, Pair(-1, 0),
                              tmpCollisionPointEcb, tmpNextStepEcb,
                              tmpProjectedEcb, thisProjectedDistance,
                              tmpLastWallCollision)) {
            overrideEcbs("Left Wall collision", ENVIRONMENT_WALL_COLLISION,
                         origin);
        }

        // // perform ceiling collision
        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        tmpLastWallCollision = lastWallCollision;
        if (ceilingCollision(*this, player_const, Pair(0, -1),
                             tmpCollisionPointEcb, tmpNextStepEcb,
                             tmpProjectedEcb, thisProjectedDistance,
                             tmpLastWallCollision)) {
            overrideEcbs("Ceiling collision", ENVIRONMENT_CEIL_COLLISION,
                         origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (topRightEdgeCollision(*this, player_const, tmpCollisionPointEcb,
                                  tmpNextStepEcb, tmpProjectedEcb,
                                  thisProjectedDistance)) {
            overrideEcbs("Top Right Edge collision", ENVIRONMENT_EDGE_COLLISION,
                         origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (bottomRightEdgeCollision(*this, player_const, tmpCollisionPointEcb,
                                     tmpNextStepEcb, tmpProjectedEcb,
                                     thisProjectedDistance)) {
            overrideEcbs("Bottom Right Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (bottomLeftEdgeCollision(*this, player_const, tmpCollisionPointEcb,
                                    tmpNextStepEcb, tmpProjectedEcb,
                                    thisProjectedDistance)) {
            overrideEcbs("Bottom Left Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
        }

        tmpCollisionPointEcb = currentEcb;
        tmpNextStepEcb = nextStepEcb;
        tmpProjectedEcb = projectedEcb;
        if (topRightEdgeCollision(*this, player_const, tmpCollisionPointEcb,
                                  tmpNextStepEcb, tmpProjectedEcb,
                                  thisProjectedDistance)) {
            overrideEcbs("Bottom Left Edge collision",
                         ENVIRONMENT_EDGE_COLLISION, origin);
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
            out << "######## movement was interrupted, recursing!" << std::endl;
            // start the recursive walk at the position of the collision
            currentEcb = closestCollisionPointEcb;
            Ecb predictedNextStepEcb = closestNextStepEcb;
            moveRecursive(player, currentEcb, closestNextStepEcb);
            if (predictedNextStepEcb.origin != closestNextStepEcb.origin) {
                // the other motion interrupted this motion, so
                // our projected ECB is no longer valid. The recursive call
                // will have resolved motion ,so we break;
                out << "recursive walk changed projected ECB" << std::endl;
                out << "breaking loop" << std::endl;
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

    out << "resolving: " << currentEcb << std::endl;
    out << "===========================" << std::endl;
    out.indent(-4);
    // out << indent_manip::pop;
}

void Map::movePlayer(Player& player, Pair& requestedDistance) const {
    // TODO think about ledge grabbing
    // grabLedges(player);

    out << "===========================" << std::endl;
    out << "===========================" << std::endl;
    out << "===========================" << std::endl;
    out << "requested distance: " << requestedDistance << std::endl;
    out << "grounded? " << player.isGrounded() << std::endl;

    if (requestedDistance.x == 0 && requestedDistance.y == 0)
        return;

    // if the player is grounded, move them along the platform
    Pair projectedPosition = player.position;
    basicProjection(player, requestedDistance, projectedPosition);

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

    out << "remaining distance after motion: " << requestedDistance
        << std::endl;
    out << "projected pos:      " << projectedPosition << std::endl;

    moveRecursive(player, currentEcb, projectedEcb);

    // reset player position to the projected Ecb
    player.moveTo(currentEcb);
}

void Map::grabLedges(Player& player) {
    if (player.canGrabLedge()) {
        for (Ledge& l : ledges) {
            Pair ledgebox_position = player.position + Pair(0, -LEDGEBOX_BASE);
            Pair diff = l.position - ledgebox_position;
            if (sign(diff.x) == sign(player.face) && player.face != l.facing &&
                std::abs(diff.x) < LEDGEBOX_WIDTH &&
                diff.y > -LEDGEBOX_HEIGHT && diff.y < 0) {
                player.grabLedge(&l);
                return;
            }
        }
    }
}

void Map::render(SDL_Renderer* r) {
    for (Platform& p : platforms) {
        p.render(r);
    }

    for (Ledge& l : ledges) {
        l.render(r);
    }
}

Platform* Map::getPlatform(size_t index) {
    return &(platforms[index]);
}

// Pair slide(
//     Pair const& l1,
//     Pair const& l2,
//     Pair const& coll,
//     Pair const& dest) {

//     Pair slope = l2 - l1;
//     Pair perp = Pair(-slope.y, slope.x);
//     Pair projected = dest + perp;

//     Pair intersectionPoint;
//     checkLineIntersection(l1, l2, dest, projected, intersectionPoint);

//     if (onLine(l1, l2, intersectionPoint)) {
//         return intersectionPoint - coll;
//     } else if (r > 1){
//         return l2 - coll;
//     } else {
//         return l1 - coll;
//     }

// }
