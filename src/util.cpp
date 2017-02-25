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



// in this next function, we are considering a line that is sweeping,
// from the initial line 'line1' passing through the two points p1 = (x1,y1), p2 = (x2,y2)
// to the final line 'line2' passing through the two points p3 = (x3,y3) and p4 = (x4,y4)
// there are two sweeping parameters: 
//   't', which indicates how far along each line we are
//   's', which indicates how far we are sweeping between line1 and line2 (the main sweeping parameter)
// for instance:
//  s=0 means we are on line1,
//  s=1 means we are on line2,
//  t=0 means we are on the line between p1 and p3,
//  t=1 means we are on the line between p2 and p4
// this function returns a specific value for each of t and s,
// which correspond to when the swept line hits the origin O (at coordinates (0,0))
// if either of the parameters is not between 0 and 1, this function instead returns null

inline double _checkLineSweep(
    double const& a1_x,
    double const& a1_y,
    double const& a2_x,
    double const& a2_y,
    double const& b1_x,
    double const& b1_y,
    double const& b2_x,
    double const& b2_y
    ) {

    double rB = std::abs(b1_y) / (std::abs(b2_y) + std::abs(b1_y));
    double rA = std::abs(a1_y) / (std::abs(a2_y) + std::abs(a1_y));

    double B_x = rB * b1_x + (1 - rB) * b2_x;
    double A_x = rA * a1_x + (1 - rA) * a2_x;

    double rC = std::abs(A_x) / (std::abs(B_x) + std::abs(A_x));

    return rC;
}

bool checkLineSweep(
        Pair const& _a1,
        Pair const& _a2,
        Pair const& _b1,
        Pair const& _b2,
        Pair const& c,
        Pair & out1,
        Pair & out2,
        double epsilon) {

    Pair a1, a2, b1, b2;

    // exchange points if needed
    double tmp;
    if (_a1.y > _a2.y) {
        a1 = _a2;
        a2 = _a1;
    } else {
        a1 = _a1;
        a2 = _a2;
    }

    // exchange points if needed
    if (_b1.y > _b2.y) {
        b1 = _b2;
        b2 = _b1;
    } else {
        b1 = _b1;
        b2 = _b2;
    }

    // set origin to c
    double a1_x = a1.x - c.x;
    double a1_y = a1.x - c.y;
    double a2_x = a2.x - c.x;
    double a2_y = a2.x - c.y;
    double b1_x = b1.x - c.x;
    double b1_y = b1.x - c.y;
    double b2_x = b2.x - c.x;
    double b2_y = b2.x - c.y;

    double rC = _checkLineSweep(
        a1_x,
        a1_y,
        a2_x,
        a2_y,
        b1_x,
        b1_y,
        b2_x,
        b2_y
    );

    out1 = a1 * rC + b1 * (1 - rC);
    out2 = a2 * rC + b2 * (1 - rC);


    return true;
};
