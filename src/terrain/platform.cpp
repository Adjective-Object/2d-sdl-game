#include <vector>
#include <cmath>
#include <iostream>
#include <SDL.h>
#include "engine/pair.hpp"
#include "platform.hpp"
#include "platformsegment.hpp"
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

#define PLATFORM_LAND_EPSILON 0.000001
TerrainCollisionType Platform::checkCollision(Pair const& previous,
                                              Pair const& next,
                                              Pair& out,
                                              PlatformSegment& segment) {
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
            return isWall(angles[i]) ? WALL_COLLISION : FLOOR_COLLISION;
        }
    }

    return NO_COLLISION;
}

#define PLATFORM_DIR_OFFSET 0.03
void Platform::render(SDL_Renderer* r) {
    for (size_t i = 0; i < points.size() - 1; i++) {
        if (passable) {
            SDL_SetRenderDrawColor(r, 100, 100, 255, 255);
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

bool Platform::findSegment(Pair& position, PlatformSegment& out) {
    // find the segment of the platform we're on
    size_t i;
    for (i = 0; i < points.size() - 1; i++) {
        if (!isWall(angles[i]) && points[i].x <= position.x &&
            position.x <= points[i + 1].x) {
            break;
        }
    }

    // if we've stepped beyond the end of the platform, abandon it
    if (i == points.size()) {
        return false;
    }

    out = PlatformSegment(this, i);
    return true;
}

// move a point some distance along the given segment of a platform
// stops when the segment is shorter than distance
//
// returns false when movement ends or we step off the platform
bool Platform::stepAlongSegment(PlatformSegment& segment,
                                Pair& position,
                                double& distance) {
    double currentPlatformPercent =
        (position - points[segment.index]).euclid() / lengths[segment.index];
    double remainingDistance = std::abs(distance);

    int direction = distance == 0 ? 1 : sign(distance);

    printf("distance request: %f\n", distance);
    printf("distance remaining: %f\n", remainingDistance);
    printf("direction: %d\n", direction);
    printf("current platform percent: %f\n", currentPlatformPercent);

    if (direction < 0) {
        // leftward motion
        remainingDistance -= lengths[segment.index] * currentPlatformPercent;
    } else {
        // rightward motion
        remainingDistance -=
            lengths[segment.index] * (1 - currentPlatformPercent);
    }

    // if we have stepped past distance, step back and return
    if (remainingDistance < 0) {
        currentPlatformPercent = -remainingDistance / lengths[segment.index];
        if (direction < 0) {
            currentPlatformPercent = 1 - currentPlatformPercent;
        }

        printf("remaining distance after step: %f\n", remainingDistance);
        Pair newPosition =
            points[segment.index] * currentPlatformPercent +
            points[segment.index + 1] * (1 - currentPlatformPercent);

        position.x = newPosition.x;
        position.y = newPosition.y;
        distance = 0;
        return false;
    }

    segment.index += direction;

    // we have stepped off of the platform
    if (segment.index < 0 || segment.index >= lengths.size()) {
        std::cout << "stepped off" << std::endl;
        segment.index -= direction;
        distance = direction * remainingDistance;
        position.x = points[segment.index].x;
        position.y = points[segment.index].y;
        return false;
    }

    // we have walked up to a part of the platform that we can't walk past.
    else if (isWall(angles[segment.index])) {
        std::cout << "wall" << std::endl;
        if (direction == -1) {
            segment.index++;
        }

        distance = direction * remainingDistance;
        position.x = points[segment.index].x;
        position.y = points[segment.index].y;
        return false;
    }

    return true;
}

bool Platform::isPassable() {
    return passable;
}

PlatformSegment Platform::getSegment(int index) {
    return PlatformSegment(this, index);
}

void Platform::init(){};
void Platform::preUpdate(){};
void Platform::update(){};
void Platform::postUpdate(){};
