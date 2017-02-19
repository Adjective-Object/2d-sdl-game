#include <vector>
#include <cmath>
#include <iostream>
#include <SDL.h>
#include "../engine/pair.hpp"
#include "platform.hpp"
#include "../scenes.hpp"

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

        if (psPreviousPair.y < 0 && psNextPair.y >= 0) {
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

void Platform::init(){};
void Platform::preUpdate(){};
void Platform::update(){};
void Platform::postUpdate(){};
