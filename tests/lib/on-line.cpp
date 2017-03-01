#include <cmath>
#include "on-line.hpp"
#include "engine/pair.hpp"

#define EPSILON 0.000001
bool on_line(Pair const& l1, Pair const& l2, Pair const& point) {
    if (std::abs(l1.x - l2.x) < EPSILON) {
        return std::abs(point.x - l1.x) < EPSILON &&
               std::min(l1.y, l2.y) < point.y && std::max(l1.y, l2.y) > point.y;
    }

    Pair slope = l2 - l1;
    double xdiff = point.x - l1.x;
    Pair predictedPoint = l1 + (slope / slope.x) * xdiff;

    std::cout << l1 << ".." << l2 << std::endl;
    std::cout << "predicted point " << predictedPoint << std::endl;
    std::cout << "real " << point << std::endl;
    std::cout << (predictedPoint - point).euclid() << std::endl;
    std::cout << ((predictedPoint - point).euclid() < EPSILON) << std::endl;

    return (predictedPoint - point).euclid() < EPSILON;
}
