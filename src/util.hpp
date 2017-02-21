#ifndef __GAME_UTIL
#define __GAME_UTIL
#include "engine/pair.hpp"

template <typename T>
int sign(T val) {
    return (T(0) < val) - (val < T(0));
}

bool checkLineIntersection(
    Pair const& p0,
    Pair const& p1,
    Pair const& p2,
    Pair const& p3,
    Pair & out,
    double epsilon=0);

#endif