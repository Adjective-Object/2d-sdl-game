#include <iostream>
#include <string>

#include <SDL.h>
#include <SDL_image.h>

#include "game.hpp"
#include "util.hpp"
#include "engine/pair.hpp"

/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error:
*SDL_GetError()
**/
void logSDLError(std::ostream& os, const std::string& msg) {
    os << msg << " error: " << SDL_GetError() << std::endl;
}

double computeVelocity(double v, double a, double drag, double cap) {
    if (a != 0) {
        v += a * EnG->elapsed;
    }

    else if (drag != 0) {
        drag = drag * EnG->elapsed;

        if (v - drag > 0)
            v = v - drag;
        else if (v + drag < 0)
            v += drag;
        else
            v = 0;
    }

    if ((v != 0) && (cap != DOUBLE_INFINITY)) {
        if (v > cap)
            v = cap;
        else if (v < -cap)
            v = -cap;
    }

    return v;
}

template <typename T>
int sign(T val) {
    return (T(0) < val) - (val < T(0));
};

int checkLineIntersection(Pair const& p0,
                          Pair const& p1,
                          Pair const& p2,
                          Pair const& p3,
                          Pair& out,
                          double epsilon) {
    Pair const s1 = p1 - p0;
    Pair const s2 = p3 - p2;

    Pair const u = p0 - p2;

    // 1 over the cross product of s1 and s2
    float const ip = 1.f / (-s2.x * s1.y + s1.x * s2.y);

    float const s = (-s1.y * u.x + s1.x * u.y) * ip;
    float const t = (s2.x * u.y - s2.y * u.x) * ip;

    double epsilon_s = epsilon / s1.euclid();
    double epsilon_t = epsilon / s2.euclid();

    if (s >= -epsilon_s && s <= 1 + epsilon_s && t >= -epsilon_t &&
        t <= 1 + epsilon_t) {
        out = p0 * (1.0 - s) + p1 * s;
        return -sign(ip);
    }

    return 0;
}
