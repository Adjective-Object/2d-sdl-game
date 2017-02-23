#include "gtest/gtest.h"
#include "engine/pair.hpp"
#include "util.hpp"

TEST(Util, checkLineIntersection_Basic) {
    // flat surface with walkoff
    Pair a1 = Pair(0, 1), a2 = Pair(2, 1);
    Pair b1 = Pair(1, 0), b2 = Pair(1, 2);

    Pair out = Pair(0, 0);

    EXPECT_EQ(checkLineIntersection(a1, a2, b1, b2, out), 1);
    EXPECT_EQ(Pair(1, 1), out);

    EXPECT_EQ(checkLineIntersection(a1, a2, b2, b1, out), -1);
    EXPECT_EQ(Pair(1, 1), out);
}
