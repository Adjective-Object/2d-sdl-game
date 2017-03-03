#include "gtest/gtest.h"
#include "engine/pair.hpp"
#include "util.hpp"

TEST(Util, checkLineIntersection_Basic) {
    Pair a1 = Pair(-1, 1), a2 = Pair(2, 1);
    Pair b1 = Pair(1, 0), b2 = Pair(1, 2);

    Pair out = Pair(0, 0);

    EXPECT_EQ(checkLineIntersection(a1, a2, b1, b2, out), 1);
    EXPECT_EQ(out, Pair(1, 1));

    EXPECT_EQ(checkLineIntersection(a1, a2, b2, b1, out), -1);
    EXPECT_EQ(out, Pair(1, 1));
}

TEST(Util, checkLineIntersection_Basic_2) {
    Pair a1 = Pair(1, 5), a2 = Pair(1, -5);
    Pair b1 = Pair(0, 0), b2 = Pair(4, 0);

    Pair out = Pair(0, 0);

    EXPECT_EQ(checkLineIntersection(a1, a2, b1, b2, out), 1);
    EXPECT_EQ(out, Pair(1, 0));

    EXPECT_EQ(checkLineIntersection(a1, a2, b2, b1, out), -1);
    EXPECT_EQ(out, Pair(1, 0));
}

TEST(Util, checkLineIntersection_Basic_3) {
    Pair a1 = Pair(1, 1), a2 = Pair(1, 2);
    Pair b1 = Pair(0.5, 1.5), b2 = Pair(1.5, 1.5);

    Pair out = Pair(0, 0);

    EXPECT_EQ(checkLineIntersection(a1, a2, b1, b2, out), -1);
    EXPECT_EQ(out, Pair(1, 1.5));

    EXPECT_EQ(checkLineIntersection(a1, a2, b2, b1, out), 1);
    EXPECT_EQ(out, Pair(1, 1.5));
}

TEST(Util, checkLineSweep_Horizontal) {
    //
    // a1      b1
    // |   .c  |
    // a2      b2
    //

    Pair a1 = Pair(1, 0), a2 = Pair(1, 1);
    Pair b1 = Pair(2, 0), b2 = Pair(2, 1);

    Pair c = Pair(1.5, 0.5);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
    EXPECT_EQ(out1, Pair(1.5, 0));
    EXPECT_EQ(out2, Pair(1.5, 1));
}

TEST(Util, checkLineSweep_Horizontal_Miss) {
    //
    // a1      b1
    // |       |   .c
    // a2      b2
    //

    Pair a1 = Pair(1, 0), a2 = Pair(1, 1);
    Pair b1 = Pair(2, 0), b2 = Pair(2, 1);

    Pair c = Pair(3.5, 0.5);

    Pair out1, out2;

    EXPECT_FALSE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
}

TEST(Util, checkLineSweep_Horizontal_Miss_2) {
    //
    //      a1      b1
    //  .c  |       |
    //      a2      b2
    //

    Pair a1 = Pair(1, 0), a2 = Pair(1, 1);
    Pair b1 = Pair(2, 0), b2 = Pair(2, 1);

    Pair c = Pair(0.5, 0.5);

    Pair out1, out2;

    EXPECT_FALSE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
}

TEST(Util, checkLineSweep_Vertical_Miss) {
    //
    // a1------b1
    //             .c
    // a2------b2
    //

    Pair a1 = Pair(2, 0), a2 = Pair(3, 0);
    Pair b1 = Pair(2, 1), b2 = Pair(3, 1);

    Pair c = Pair(3.5, 0.5);

    Pair out1, out2;

    EXPECT_FALSE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
}

TEST(Util, checkLineSweep_Vertical_Miss_2) {
    //
    //      a1------b1
    //  .c
    //      a2------b2
    //

    Pair a1 = Pair(2, 0), a2 = Pair(3, 0);
    Pair b1 = Pair(2, 1), b2 = Pair(3, 1);

    Pair c = Pair(0.5, 0.5);

    Pair out1, out2;

    EXPECT_FALSE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
}

TEST(Util, checkLineSweep_Horizontal_Reversed) {
    //
    //  a2      b2
    //  |   .c  |
    //  a1      b1
    //

    Pair a1 = Pair(1, 1), a2 = Pair(1, 0);
    Pair b1 = Pair(2, 1), b2 = Pair(2, 0);

    Pair c = Pair(1.5, 0.5);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
    EXPECT_EQ(out1, Pair(1.5, 1));
    EXPECT_EQ(out2, Pair(1.5, 0));
}

TEST(Util, checkLineSweep_Horizontal_Cross) {
    //
    //  a1      b1
    //  |  >.c< |
    //  a2      b2
    //

    Pair a1 = Pair(1, 1), a2 = Pair(1, 2);
    Pair b1 = Pair(2, 2), b2 = Pair(2, 1);

    Pair c = Pair(1.5, 1.5);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a2, a1, b2, b1, c, out1, out2));
    EXPECT_EQ(out1, Pair(1.5, 1.5));
    EXPECT_EQ(out2, Pair(1.5, 1.5));
}

TEST(Util, checkLineSweep_Cross) {
    /*
      a1      b2
       \  .c  /
        \    /
         \  /
          \/
          /\
    */

    Pair a1 = Pair(0, 0), a2 = Pair(10, 10);
    Pair b1 = Pair(10, 0), b2 = Pair(0, 10);

    Pair c = Pair(6, 3);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
    EXPECT_EQ(out1, Pair(7.5, 0));
    EXPECT_EQ(out2, Pair(2.5, 10));
}

TEST(Util, checkLineSweep_Vertical) {
    // a1 ----- a2
    //
    //     .c
    //
    // b1 ----- b2

    Pair a1 = Pair(1, 0), a2 = Pair(2, 0);
    Pair b1 = Pair(1, 1), b2 = Pair(2, 1);

    Pair c = Pair(1.5, 0.5);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
    EXPECT_EQ(out1, Pair(1, 0.5));
    EXPECT_EQ(out2, Pair(2, 0.5));
}

TEST(Util, checkLineSweep_Vertical_Inverted) {
    // a2 ----- a1
    //
    //     .c
    //
    // b2 ----- b1
    Pair a1 = Pair(2, 0), a2 = Pair(1, 0);
    Pair b1 = Pair(2, 1), b2 = Pair(1, 1);

    Pair c = Pair(1.5, 0.5);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
    EXPECT_EQ(out1, Pair(2, 0.5));
    EXPECT_EQ(out2, Pair(1, 0.5));
}

TEST(Util, checkLineSweep_Specific) {
    // a1 ----- a2
    //
    //     .c
    //
    // b1 ----- b2

    Pair a1 = Pair(9, 0), a2 = Pair(8, -1);
    Pair b1 = Pair(19, 0), b2 = Pair(18, -1);

    Pair c = Pair(10, -0.1);

    Pair out1, out2;

    ASSERT_TRUE(checkLineSweep(a1, a2, b1, b2, c, out1, out2));
    EXPECT_EQ(out1, Pair(9.1, -1));
    EXPECT_EQ(out2, Pair(10.1, 0));
}
