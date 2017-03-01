#include <cmath>
#include "engine/pair.hpp"
#include "./util.hpp"

#include <iostream>

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

inline double _checkLineSweep(double const& a1_x,
                              double const& a1_y,
                              double const& a2_x,
                              double const& a2_y,
                              double const& b1_x,
                              double const& b1_y,
                              double const& b2_x,
                              double const& b2_y) {
    double rB = (b1_y) / (b1_y - b2_y);
    double rA = (a1_y) / (a1_y - a2_y);

    // printf("rA: %.4f, rB: %.4f\n", rA, rB);
    if (rB < 0 || rB > 1.0 || rA < 0 || rA > 1.0)
        return -1;

    double B_x = rB * b1_x + (1 - rB) * b2_x;
    double A_x = rA * a1_x + (1 - rA) * a2_x;

    // printf("Bx: %.4f, Ax: %.4f\n", B_x, A_x);

    double rC = A_x / (A_x - B_x);

    return rC;
}

bool checkLineSweep(Pair& a1,
                    Pair& a2,
                    Pair& b1,
                    Pair& b2,
                    Pair& c,
                    Pair& out1,
                    Pair& out2,
                    double epsilon) {
    // set origin to c
    double a1_x = a1.x - c.x;
    double a1_y = a1.y - c.y;
    double a2_x = a2.x - c.x;
    double a2_y = a2.y - c.y;
    double b1_x = b1.x - c.x;
    double b1_y = b1.y - c.y;
    double b2_x = b2.x - c.x;
    double b2_y = b2.y - c.y;

    // std::cout
    //     << "a1_x: " << a1_x << " "
    //     << "a1_y: " << a1_y << ", "
    //     << "a2_x: " << a2_x << " "
    //     << "a2_y: " << a2_y << ", "
    //     << "b1_x: " << b1_x << " "
    //     << "b1_y: " << b1_y << ", "
    //     << "b2_x: " << b2_x << " "
    //     << "b2_y: " << b2_y << std::endl;

    double tmp;
#define exchange(i, j) \
    {                  \
        tmp = i;       \
        i = j;         \
        j = tmp;       \
    }

#define _rotate(x, y) \
    {                 \
        tmp = x;      \
        x = y;        \
        y = -tmp;     \
    }

    // handle case where the input is vertical
    bool rotate = (std::max(a1_y, a2_y) < std::min(b1_y, b2_y) ||
                   std::min(a1_y, a2_y) > std::max(b1_y, b2_y));

    // std::cout
    //     << "original      "
    //     << "a1: (" << a1_x << ", " << a1_y << ") "
    //     << "a2: (" << a2_x << ", " << a2_y << ") "
    //     << "b1: (" << b1_x << ", " << b1_y << ") "
    //     << "b2: (" << b2_x << ", " << b2_y << ") "
    //     << std::endl;

    if (rotate) {
        _rotate(a1_x, a1_y);
        _rotate(a2_x, a2_y);
        _rotate(b1_x, b1_y);
        _rotate(b2_x, b2_y);

        // std::cout
        //     << "rotated       "
        //     << "a1: (" << a1_x << ", " << a1_y << ") "
        //     << "a2: (" << a2_x << ", " << a2_y << ") "
        //     << "b1: (" << b1_x << ", " << b1_y << ") "
        //     << "b2: (" << b2_x << ", " << b2_y << ") "
        //     << std::endl;
    }

    // exchange points in vertical, line a
    if (a1_y > a2_y) {
        exchange(a1_x, a2_x);
        exchange(a1_y, a2_y);
    }

    // exchange points in vertical, line b
    if (b1_y > b2_y) {
        exchange(b1_x, b2_x);
        exchange(b1_y, b2_y);

        // std::cout << "inverted      "
        //     << "a1: (" << a1_x << ", " << a1_y << ") "
        //     << "a2: (" << a2_x << ", " << a2_y << ") "
        //     << "b1: (" << b1_x << ", " << b1_y << ") "
        //     << "b2: (" << b2_x << ", " << b2_y << ") "
        //     << std::endl;
    }

    double rC = _checkLineSweep(a1_x, a1_y, a2_x, a2_y, b1_x, b1_y, b2_x, b2_y);

    // std::cout << "rC = " << rC << std::endl;;
    if (rC < 0 || rC > 1)
        return false;

    if (rotate) {
        tmp = a1_x;
        a1_x = -a2_y;
        a2_y = tmp;

        tmp = a1_y;
        a1_y = a2_x;
        a2_x = -tmp;

        tmp = b1_x;
        b1_x = -b2_y;
        b2_y = tmp;

        tmp = b2_x;
        b2_x = -b1_y;
        b1_y = tmp;

        // std::cout
        //     << "rotated back  "
        //     << "a1: (" << a1_x << ", " << a1_y << ") "
        //     << "a2: (" << a2_x << ", " << a2_y << ") "
        //     << "b1: (" << b1_x << ", " << b1_y << ") "
        //     << "b2: (" << b2_x << ", " << b2_y << ") "
        //     << std::endl;

        out1 = Pair(a1_x + c.x, a1_y + c.y) * rC +
               Pair(b1_x + c.x, b1_y + c.y) * (1 - rC);
        out2 = Pair(a2_x + c.x, a2_y + c.y) * rC +
               Pair(b2_x + c.x, b2_y + c.y) * (1 - rC);

        return true;
    }

    out1 = Pair(a1_x + c.x, a1_y + c.y) * rC +
           Pair(b1_x + c.x, b1_y + c.y) * (1 - rC);
    out2 = Pair(a2_x + c.x, a2_y + c.y) * rC +
           Pair(b2_x + c.x, b2_y + c.y) * (1 - rC);

    return true;
};

#define EPSILON 0.000001
bool onLine(Pair const& l1, Pair const& l2, Pair const& point) {
    if (std::abs(l1.x - l2.x) < EPSILON) {
        return std::abs(point.x - l1.x) < EPSILON &&
               std::min(l1.y, l2.y) < point.y && std::max(l1.y, l2.y) > point.y;
    }

    Pair slope = l2 - l1;
    double xdiff = point.x - l1.x;
    double ratio = (xdiff / slope.x);
    if (ratio < 0 || ratio > 1)
        return false;
    Pair predictedPoint = l1 + slope * ratio;

    return (predictedPoint - point).euclid() < EPSILON;
}
