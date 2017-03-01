#ifndef __GAME_UTIL
#define __GAME_UTIL
#include "engine/pair.hpp"

template <typename T>
int sign(T val) {
    return (T(0) < val) - (val < T(0));
};

int checkLineIntersection(Pair const& p0,
                          Pair const& p1,
                          Pair const& p2,
                          Pair const& p3,
                          Pair& out,
                          double epsilon = 0);

bool checkLineSweep(Pair& a1,
                    Pair& a2,
                    Pair& b1,
                    Pair& b2,
                    Pair& c,
                    Pair& out1,
                    Pair& out2,
                    double epsilon = 0);

#define M_PI 3.14159265358979323846 /* pi */
bool onLine(Pair const& l1, Pair const& l2, Pair const& point);

#endif
