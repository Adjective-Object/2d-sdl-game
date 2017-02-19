#include <vector>
#include <cmath>
#include <iostream>
#include <SDL.h>
#include "../engine/pair.hpp"
#include "platform.hpp"
#include "../scenes.hpp"
#include "../util.hpp"

Platform::Platform(std::vector<Pair> points) : points(points) {
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

bool Platform::checkCollision(Pair& previous, Pair& next, double* out) {
    if (points.size() < 2) {
        // this is an error situation
        std::cerr << "less than 2 points wtf" << std::endl;
        return false;
    }

    for (size_t i = 0; i < points.size() - 1; i++) {
        Pair p1 = points[i];
        double angle = angles[i];

        // get point in platform space
        Pair psPreviousPair =
            this->movePointToSegmentSpace(p1, angle, previous);

        Pair psNextPair = this->movePointToSegmentSpace(p1, angle, next);

        if (psPreviousPair.y <= 0 && psNextPair.y >= 0) {
            // the player has crossed the platform, check the x bounds
            // TODO think about a better way to do this..
            Pair p2 = points[i + 1];

            std::cout << "player crossed platform:\t" << psPreviousPair.x
                      << ",\t" << psPreviousPair.y << "\t"
                      << "\t->\t" << psNextPair.x << ",\t" << psNextPair.y
                      << "\t" << std::endl;

            std::cout << "other platform:\t" << (p2 - p1).x << ", "
                      << (p2 - p1).y << std::endl;

            if ((psPreviousPair.x > 0 || psNextPair.x > 0) &&
                (psPreviousPair.x < lengths[i] || psNextPair.x < lengths[i])) {
                std::cout << "collision detected @ " << p1.y << std::endl;

                *out = (double)p1.y;  // TODO
                return true;
            }
        }
    }

    return false;
}

void Platform::render(SDL_Renderer* r) {
    for (size_t i = 0; i < points.size() - 1; i++) {
        SDL_SetRenderDrawColor(r, 255, 255, 255, 255);

        SDL_RenderDrawLine(r, (int)(points[i].x * PLAYER_SCALE),
                           (int)(points[i].y * PLAYER_SCALE),
                           (int)(points[i + 1].x * PLAYER_SCALE),
                           (int)(points[i + 1].y * PLAYER_SCALE));
    }
}

bool Platform::groundedMovement(Pair& position, Pair& velocity) {
    Pair wsRelPos = position - points[0];
    if (wsRelPos.x < 0) {
        std::cerr << "grounded movement starts before platform" << std::endl;
        return false;
    }

    // find the segment of the platform we're on
    size_t i = 0;
    while (i < points.size() && position.x >= points[i].x) {
        i++;
    }

    // if we've stepped beyond the end of the platform, abandon it
    if (i == points.size()) {
        std::cerr << "grounded movement starts off of platform (" << i << ")"
                  << std::endl;
        return false;
    }

    i--;

    std::cout << "i: " << i << std::endl;

    // std::cout << "resting on segment " << i << std::endl;
    // std::cout << "length is " << lengths[i] << std::endl;

    double currentPlatformPercent =
        (position - points[i]).euclid() / lengths[i];
    double remainingDistance = std::abs(velocity.x);
    double direction = velocity.x == 0 ? 1 : sign(velocity.x);

    std::cout << "direction " << direction << std::endl;
    std::cout << "distance " << remainingDistance << std::endl;

    while (1) {
        std::cout << "reducing movment by remaining length of current platform"
                  << std::endl;
        std::cout << "length: " << lengths[i]
                  << " percent: " << currentPlatformPercent << std::endl;

        if (direction < 0) {
            // leftware motion
            remainingDistance -= lengths[i] * currentPlatformPercent;
            currentPlatformPercent = 1;
        } else {
            // rightward motion
            remainingDistance -= lengths[i] * (1 - currentPlatformPercent);
            currentPlatformPercent = 0;
        }
        std::cout << "remaining distance " << remainingDistance << std::endl;

        // if we've gone too negative remainingDistance, then we've
        // exhausted the requested platform motion. Undo the previous
        // motion to get to remainingDistance of zero and resturn the
        // corresponding position w/ 0 velocity
        if (remainingDistance < 0) {
            std::cout << "ending motion" << std::endl;

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
            printf("stepping off platform (direction: %f, reamining dist:%f)",
                   direction, remainingDistance);
            i -= direction;
            velocity.x = direction * remainingDistance;
            position.x = points[i].x;
            position.y = points[i].y;
            return false;
        }
    }
}

void Platform::init(){};
void Platform::preUpdate(){};
void Platform::update(){};
void Platform::postUpdate(){};
