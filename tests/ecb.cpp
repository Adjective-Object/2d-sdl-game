#include "player/ecb.hpp"
#include "gtest/gtest.h"

TEST(Ecb, construct) {
    Ecb e = Ecb(Pair(0, 0), 1, 1, 1, 1);

    EXPECT_EQ(e.left, Pair(-1, 0));
    EXPECT_EQ(e.right, Pair(1, 0));
    EXPECT_EQ(e.top, Pair(0, -1));
    EXPECT_EQ(e.bottom, Pair(0, 1));
}

TEST(Ecb, setOrigin) {
    Ecb e = Ecb(Pair(0, 0), 1, 1, 1, 1);
    e.setOrigin(Pair(10, 20));

    EXPECT_EQ(e.left, Pair(9, 20));
    EXPECT_EQ(e.right, Pair(11, 20));
    EXPECT_EQ(e.top, Pair(10, 19));
    EXPECT_EQ(e.bottom, Pair(10, 21));
}
