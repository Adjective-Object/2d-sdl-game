#include <vector>
#include <cmath>
#include <iostream>
#include <SDL.h>
#include "engine/pair.hpp"
#include "platform.hpp"
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
                                              PlatformSegment& segmentOut) {
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
            segment.platform = this;
            segment.index = i;
            return isWall(angles[i]) ? WALL_COLLISION : FLOOR_COLLISION;
        }
    }

    return NO_COLLISION;
}

Pair Platform::moveAlongWall(Pair const& start,
                             Pair const& destination,
                             int segment) {
    // TODO make it work for left walls too lol
    double dest_x, dest_y, frac;
    Pair upperWallPoint, lowerWallPoint;

    if (destination.x < start.x) {
        upperWallPoint = points[segment + 1];
        lowerWallPoint = points[segment];
    } else {
        upperWallPoint = points[segment];
        lowerWallPoint = points[segment + 1];
    }

    if (destination.y > start.y) {
        dest_y = std::min(destination.y, upperWallPoint.y);
    } else {
        dest_y = std::max(destination.y, upperWallPoint.y);
    }

    // move linearly along the platform to dest_y
    frac = (dest_y - lowerWallPoint.y) / (upperWallPoint.y - lowerWallPoint.y);
    dest_x = frac * upperWallPoint.x + (1 - frac) * lowerWallPoint.x;

    return Pair(dest_x, dest_y);
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

bool Platform::groundedMovement(Pair& position, Pair& velocity) {
    Pair wsRelPos = position - points[0];
    if (wsRelPos.x < 0) {
        std::cerr << "grounded movement starts before platform" << std::endl;
        return false;
    }

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
        std::cerr << "grounded movement starts off of platform (" << i << ")"
                  << std::endl;
        return false;
    }

    // std::cout << "i: " << i << std::endl;

    // std::cout << "resting on segment " << i << std::endl;
    // std::cout << "length is " << lengths[i] << std::endl;

    double currentPlatformPercent =
        (position - points[i]).euclid() / lengths[i];
    double remainingDistance = std::abs(velocity.x);
    int direction = velocity.x == 0 ? 1 : sign(velocity.x);

    // std::cout << "direction " << direction << std::endl;
    // std::cout << "distance " << remainingDistance << std::endl;

    while (1) {
        // std::cout << "reducing movment by remaining len of platform " << i
        //           << std::endl;
        // std::cout << "length: " << lengths[i]
        //           << " percent: " << currentPlatformPercent << std::endl;

        if (direction < 0) {
            // leftware motion
            remainingDistance -= lengths[i] * currentPlatformPercent;
            currentPlatformPercent = 1;
        } else {
            // rightward motion
            remainingDistance -= lengths[i] * (1 - currentPlatformPercent);
            currentPlatformPercent = 0;
        }

        // std::cout << "remaining dist " << remainingDistance << std::endl;

        // if we've gone too negative remainingDistance, then we've
        // exhausted the requested platform motion. Undo the previous
        // motion to get to remainingDistance of zero and resturn the
        // corresponding position w/ 0 velocity
        if (remainingDistance < 0) {
            // std::cout << "ending motion" << std::endl;

            currentPlatformPercent = -remainingDistance / lengths[i];
            if (direction < 0) {
                currentPlatformPercent = 1 - currentPlatformPercent;
            }
            Pair newPosition = points[i] * currentPlatformPercent +
                               points[i + 1] * (1 - currentPlatformPercent);
            position.x = newPosition.x;
            position.y = newPosition.y;
            velocity.x = 0;
            return true;
        }

        i += direction;

        // if we step off the platform, return the position of the last
        // position on the platform with x velocity corresponding to
        // remaining distance
        if (i < 0 || i >= lengths.size()) {
            // printf(
            //     "stepping off platform %d (direction: %d, dist left:%f)\n",
            //     i, direction, remainingDistance);
            i -= direction;
            velocity.x = direction * remainingDistance;
            position.x = points[i].x;
            position.y = points[i].y;
            return false;
        }

        if (isWall(angles[i])) {
            if (direction == -1) {
                i++;
            }
            velocity.x = direction * remainingDistance;
            position.x = points[i].x;
            position.y = points[i].y;
            return false;
        }
    }
}

bool Platform::isPassable() {
    return passable;
}

void Platform::init(){};
void Platform::preUpdate(){};
void Platform::update(){};
void Platform::postUpdate(){};

PlatformSegment::PlatformSegment(Platform* p, int index)
    : platform(platform), index(index) {}

Pair* PlatformSegment::firstPoint() {
    return platform->points[index];
}

Pair* PlatformSegment::secondPoint() {
    return platform->points[index + 1];
}

Pair PlatformSegment::slope() {
    Pair p;
    p = (firstPoint() - secondPoint());
    return p / p.euclid();
}

