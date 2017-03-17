#include <cmath>
#include "engine/pair.hpp"
#include "./util.hpp"

#include <iostream>

#define _debug(...)
// #define _debug(...) { __VA_ARGS__; }

double Dot(const Pair& a, const Pair& b) {
    return (a.x * b.x) + (a.y * b.y);
}

double PerpDot(const Pair& a, const Pair& b) {
    return (a.y * b.x) - (a.x * b.y);
}

int checkLineIntersection(Pair const& p0,
                          Pair const& p1,
                          Pair const& p2,
                          Pair const& p3,
                          Pair& out,
                          double epsilon) {
    Pair a = p1 - p0;
    Pair b = p3 - p2;

    double f = PerpDot(a, b);
    if (!f)  // lines are parallel
        return 0;

    Pair c(p3 - p1);
    double aa = PerpDot(a, c);
    double bb = PerpDot(b, c);

    if (f < 0) {
        if (aa > epsilon)
            return 0;
        if (bb > epsilon)
            return 0;
        if (aa < f - epsilon)
            return 0;
        if (bb < f - epsilon)
            return 0;
    }

    else {
        if (aa < -epsilon)
            return 0;
        if (bb < -epsilon)
            return 0;
        if (aa > f + epsilon)
            return 0;
        if (bb > f + epsilon)
            return 0;
    }

    double r = std::max(0.0, 1.0 - std::min(1.0, aa / f));
    out = ((p3 - p2) * r) + p2;
    return -sign(f);
}

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

int checkLineSweep(Pair const& a1,
                   Pair const& a2,
                   Pair const& b1,
                   Pair const& b2,
                   Pair const& c,
                   Pair& out1,
                   Pair& out2,
                   double epsilon) {
    _debug(std::cout << "a1: " << a1 << std::endl;
           std::cout << "a2: " << a2 << std::endl;
           std::cout << "b1: " << b1 << std::endl;
           std::cout << "b2: " << b2 << std::endl;
           std::cout << "c:  " << c << std::endl;)

        Pair intersectionA,
        intersectionB;
    Pair diff1 = b1 - a1;
    Pair diff2 = b2 - a2;

    _debug(std::cout << "diff1: " << diff1 << std::endl;
           std::cout << "diff2: " << diff2 << std::endl;
           std::cout << "diff1 len^2: " << diff1.euclidSquared() << std::endl;
           std::cout << "diff2 len^2: " << diff2.euclidSquared() << std::endl;)

        double biggestLen =
            std::max(diff1.euclidSquared(), diff2.euclidSquared());

    if (biggestLen == 0) {
        _debug(std::cout << "biggestLen = 0" << std::endl;);
        out1 = a1;
        out2 = a2;
        return 1;
    }

    Pair biggestDiff = diff1 * (std::sqrt(biggestLen) / diff1.euclid());

    _debug(std::cout << "biggest diff " << biggestDiff << std::endl);

    int wasIntersection1 =
        checkLineIntersection(a1, a2, c, c - biggestDiff, intersectionA);

    int wasIntersection2 =
        checkLineIntersection(b1, b2, c, c + biggestDiff, intersectionB);

    if (wasIntersection1 == 0 || wasIntersection2 == 0)
        return 0;

    _debug(std::cout << "line a intersection: " << intersectionA << std::endl;
           std::cout << "line b intersection: " << intersectionB << std::endl;
           std::cout << "wasIntersection A: " << wasIntersection1 << std::endl;
           std::cout << "wasIntersection B: " << wasIntersection2
                     << std::endl;);

    double pointADist = (intersectionA - c).euclid();
    double pointBDist = (intersectionB - c).euclid();
    double diffDist = pointADist + pointBDist;

    if (diffDist == 0) {
        _debug(std::cout << "diffDist = 0" << std::endl);
        ;
        out1 = c;
        out2 = c;
        return -wasIntersection1;
    };

    double rC = pointADist / diffDist;

    _debug(std::cout << "rC" << rC << std::endl;

           std::cout << "b1 - a1: " << (b1 - a1) << std::endl;
           std::cout << "b2 - a2: " << (b2 - a2) << std::endl;

           std::cout << "(b1 - a1) * rC: " << (b1 - a1) * rC << std::endl;
           std::cout << "(b2 - a2) * rC: " << (b2 - a2) * rC << std::endl;);

    out1 = a1 + ((b1 - a1) * rC);
    out2 = a2 + ((b2 - a2) * rC);

    return -wasIntersection1;
};

#define EPSILON 0.0001
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
    Pair predictedPoint = l1 + slope / slope.x * xdiff;

    _debug(std::cout << "ratio:     " << ratio << std::endl;
           std::cout << "predicted: " << predictedPoint << std::endl;
           std::cout << "point:     " << point << std::endl;
           std::cout << "diff:      " << (predictedPoint - point)
                     << std::endl;);

    return (predictedPoint - point).euclid() < EPSILON;
}
