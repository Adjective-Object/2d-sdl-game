#include "engine/pair.hpp"
#include "./util.hpp"

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
        out = p0 * (1.0 - t) + p1 * t;
        return sign(ip);
    }

    return 0;
}

bool checkLineSweep(
        Pair const& a1,
        Pair const& a2,
        Pair const& b1,
        Pair const& b2,
        Pair const& c,
        Pair & out1,
        Pair & out2,
        double epsilon) {
    return false;
}

