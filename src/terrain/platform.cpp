#include <vector>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "engine/pair.hpp"
#include "platform.hpp"
#include "platformsegment.hpp"
#include "platform_movement.hpp"
#include "constants.hpp"
#include "util.hpp"
#include "./collisiontype.hpp"

Platform::Platform(std::vector<Pair> points, bool passable)
    : points(points), passable(passable) {
    if (points.size() < 2) {
        // this is an error situation
        std::cerr << "platform construciton with less than 2 points"
                  << std::endl;
    }

    angles = std::vector<double>(points.size());
    lengths = std::vector<double>(points.size());
    for (size_t i = 0; i < points.size() - 1; i++) {
        Pair p1 = points[i];
        Pair p2 = points[i + 1];
        angles[i] = std::atan2(p2.y - p1.y, p2.x - p1.x);
        lengths[i] = (p2 - p1).euclid();
    }
}

Platform::~Platform() {}

Pair Platform::movePointToSegmentSpace(Pair& platformPoint,
                                       double platformAngle,
                                       Pair& otherPoint) {
    // move other point into relative world space
    Pair wsRelPair = otherPoint - platformPoint;
    double length = wsRelPair.euclid();

    // rotate it into platform space
    double wsAngle = std::atan2(wsRelPair.y, wsRelPair.x);
    double psAngle = wsAngle - platformAngle;
    return Pair(std::cos(psAngle) * length, std::sin(psAngle) * length);
}

bool Platform::isWall(double angle) {
    return (std::abs(angle) > M_PI * 3.0 / 8.0);
}

bool Platform::isCeil(double angle) {
    return (std::abs(angle - M_PI) < M_PI * 1.0 / 8.0);
}

#define PLATFORM_LAND_EPSILON 0.000001
TerrainCollisionType Platform::checkCollision(
    Pair const& previous,
    Pair const& next,
    Pair& out,
    PlatformSegment& segment,
    TerrainCollisionType expectedCollisionType) const {
    if (points.size() < 2) {
        // this is an error situation
        std::cerr << "less than 2 points wtf" << std::endl;
        return NO_COLLISION;
    }

    for (size_t i = 0; i < points.size() - 1; i++) {
        Pair p1 = points[i];
        Pair p2 = points[i + 1];
        Pair intersectionPoint = Pair(0, 0);
        int direction = checkLineIntersection(
            previous, next, p1, p2, intersectionPoint, PLATFORM_LAND_EPSILON);
        if (direction < 0) {
            out = intersectionPoint;
            segment = PlatformSegment(this, i);

            if (isCeil(angles[i])) {
                if (expectedCollisionType != CEIL_COLLISION)
                    continue;
                return CEIL_COLLISION;
            }

            else if (isWall(angles[i])) {
                if (expectedCollisionType != WALL_COLLISION)
                    continue;
                return WALL_COLLISION;
            }

            if (expectedCollisionType != FLOOR_COLLISION)
                continue;
            return FLOOR_COLLISION;
        }
    }

    return NO_COLLISION;
}

bool Platform::checkEdgeCollision(Pair const& a1,
                                  Pair const& a2,
                                  Pair const& b1,
                                  Pair const& b2,
                                  EdgeCollision& collision) const {
    for (size_t i = 0; i < points.size() - 1; i++) {
        // TODO compare if multiple colls happen same frame?
        int direction =
            checkLineSweep(a1, a2, b1, b2, points[i], collision.collisionLine1,
                           collision.collisionLine2);
        if (direction == -1) {
            collision.cornerPosition = points[i];
            collision.s1 = (i >= 0) ? PlatformSegment(this, i - 1)
                                    : PlatformSegment(this, points.size() - 1);
            collision.s2 = (i < points.size() - 1) ? PlatformSegment(this, i)
                                                   : PlatformSegment(this, 0);
            return true;
        }
    }

    return false;
}

#define PLATFORM_DIR_OFFSET 0.03
void Platform::render(SDL_Renderer* r) {
    for (size_t i = 0; i < points.size() - 1; i++) {
        if (passable) {
            SDL_SetRenderDrawColor(r, 100, 100, 255, 255);
        } else if (isCeil(angles[i])) {
            SDL_SetRenderDrawColor(r, 200, 30, 30, 255);
        } else if (isWall(angles[i])) {
            SDL_SetRenderDrawColor(r, 0, 200, 255, 255);
        } else {
            SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
        }

        SDL_RenderDrawLine(r, (int)(points[i].x * PLAYER_SCALE),
                           (int)(points[i].y * PLAYER_SCALE),
                           (int)(points[i + 1].x * PLAYER_SCALE),
                           (int)(points[i + 1].y * PLAYER_SCALE));

        Pair offset = Pair(-std::sin(angles[i]) * PLATFORM_DIR_OFFSET,
                           std::cos(angles[i]) * PLATFORM_DIR_OFFSET);
        Pair q1 = points[i] + offset;
        Pair q2 = points[i + 1] + offset;

        SDL_SetRenderDrawColor(r, 200, 0, 200, 255);
        SDL_RenderDrawLine(
            r, (int)(q1.x * PLAYER_SCALE), (int)(q1.y * PLAYER_SCALE),
            (int)(q2.x * PLAYER_SCALE), (int)(q2.y * PLAYER_SCALE));
    }
}

bool Platform::groundedMovement(Pair& position, Pair& velocity) const {
    PlatformMovementState m;
    bool stayOn = initGroundedMovement(position, velocity, m);
    int count = 0;
    while (stayOn && velocity != Pair(0, 0) && count < 10) {
        count++;
        stayOn &= stepGroundedMovement(position, velocity, m);
        std::cout << "velocity: " << velocity << std::endl;
        std::cout << "position: " << position << std::endl;
    }
    return stayOn;
}

bool Platform::initGroundedMovement(Pair& position,
                                    Pair& velocity,
                                    PlatformMovementState& out) const {
    out.initialized = true;

    Pair wsRelPos = position - points[0];
    if (wsRelPos.x < 0) {
        std::cerr << "grounded movement starts before platform" << std::endl;
        return false;
    }

    // find the segment of the platform we're on
    size_t i;
    for (i = 0; i < points.size() - 1; i++) {
        if (!isWall(angles[i]) && points[i].x <= position.x &&
            onLine(points[i], points[i + 1], position)) {
            break;
        }
    }

    std::cout << "i: " << i << std::endl;
    std::cout << "points: " << points.size() << std::endl;

    // if we've stepped beyond the end of the platform, abandon it
    if (i >= points.size() - 1) {
        std::cerr << "grounded movement starts off of platform (" << i << ")"
                  << std::endl;
        return false;
    }

    std::cout << "resting on segment " << i << std::endl;
    std::cout << "length is " << lengths[i] << std::endl;

    out.platform = this;
    out.currentSegment = i;
    out.currentPlatformPercent = (position - points[i]).euclid() / lengths[i];
    out.remainingDistance = std::abs(velocity.x);
    out.direction = velocity.x == 0 ? 1 : sign(velocity.x);
}

/** Move by up to the length of the current platform
 *
 * @return if the position would fall off the platform
 */
bool Platform::stepGroundedMovement(Pair& position,
                                    Pair& velocity,
                                    PlatformMovementState& ms) const {
    std::cout << "direction " << ms.direction << std::endl;
    std::cout << "distance " << ms.remainingDistance << std::endl;

    std::cout << "reducing movment by remaining len of platform "
              << ms.currentSegment << std::endl;
    std::cout << "length: " << lengths[ms.currentSegment]
              << " percent: " << ms.currentPlatformPercent << std::endl;

    if (ms.direction < 0) {
        // leftward motion
        ms.remainingDistance -=
            lengths[ms.currentSegment] * ms.currentPlatformPercent;
        ms.currentPlatformPercent = 1;
    } else {
        // rightward motion
        ms.remainingDistance -=
            lengths[ms.currentSegment] * (1 - ms.currentPlatformPercent);
        ms.currentPlatformPercent = 0;
    }

    std::cout << "remaining dist " << ms.remainingDistance << std::endl;

    // if we've gone too negative remainingDistance, then we've
    // exhausted the requested platform motion. Undo the previous
    // motion to get to remainingDistance of zero and resturn the
    // corresponding position w/ 0 velocity
    if (ms.remainingDistance <= 0) {
        std::cout << "ending motion, went so far" << std::endl;

        ms.currentPlatformPercent =
            -ms.remainingDistance / lengths[ms.currentSegment];
        if (ms.direction < 0) {
            ms.currentPlatformPercent = 1 - ms.currentPlatformPercent;
        }
        Pair newPosition =
            points[ms.currentSegment] * ms.currentPlatformPercent +
            points[ms.currentSegment + 1] * (1 - ms.currentPlatformPercent);
        position.x = newPosition.x;
        position.y = newPosition.y;
        velocity.x = 0;
        return true;
    }

    ms.currentSegment += ms.direction;

    // if we step off the platform, return the position of the last
    // position on the platform with x velocity corresponding to
    // remaining distance
    if (ms.currentSegment < 0 || ms.currentSegment >= lengths.size()) {
        printf("stepping off platform %d (direction: %d, dist left:%f)\n",
               ms.currentSegment, ms.direction, ms.remainingDistance);
        ms.currentSegment -= ms.direction;
        velocity.x = ms.direction * ms.remainingDistance;
        position.x = points[ms.currentSegment].x;
        position.y = points[ms.currentSegment].y;
        return false;
    }

    // walk off when we would be transitioning to a wall
    if (isWall(angles[ms.currentSegment])) {
        if (ms.direction == -1) {
            ms.currentSegment++;
        }
        velocity.x = ms.direction * ms.remainingDistance;
        position.x = points[ms.currentSegment].x;
        position.y = points[ms.currentSegment].y;
        return false;
    }

    velocity.x = ms.direction * ms.remainingDistance;
    return true;
}

bool Platform::isPassable() const {
    return passable;
}

PlatformSegment Platform::getSegment(int index) const {
    return PlatformSegment(this, index);
}

void Platform::init(){};
void Platform::preUpdate(){};
void Platform::update(){};
void Platform::postUpdate(){};
