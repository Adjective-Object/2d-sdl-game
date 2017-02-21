#include "gtest/gtest.h"
#include "engine/pair.hpp"
#include "terrain/platform.hpp"

TEST(Platform, GroundedMovement_NoMovement) {
    // flat surface with no movement
    Platform p = Platform({Pair(0, 0), Pair(1, 0)});
    Pair pos = Pair(0, 0), vel = Pair(0, 0);
    p.groundedMovement(pos, vel);
    EXPECT_EQ(Pair(0, 0), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, GroundedMovement_SingleSegmentMovement) {
    // flat surface with minimal movement
    Platform p = Platform({Pair(0.0, 0), Pair(1, 0)});
    Pair pos = Pair(0.3, 0), vel = Pair(0.1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(0.4, 0), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, GroundedMovement_SingleSegmentMovement_Left) {
    Platform p = Platform({Pair(0.0, 0), Pair(1, 0)});
    Pair pos = Pair(0.3, 0), vel = Pair(-0.1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(0.2, 0), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, GroundedMovement_MultiSegmentMovement) {
    // flat surface with rightward movement accrss multiple surfaces
    Platform p = Platform({Pair(0, 0), Pair(1, 0), Pair(2, 0)});
    Pair pos = Pair(0, 0), vel = Pair(1.1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(1.1, 0), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, GroundedMovement_DiagonalMovement) {
    // diagonal surface with rightward movement
    Platform p = Platform({
        Pair(0, 0), Pair(8, 6),
    });
    Pair pos = Pair(0, 0), vel = Pair(5, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(4, 3), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, GroundedMovement_DiagonalMultiSegmentMovement) {
    // segmented diagonal surface with rightward movement
    Platform p = Platform({
        Pair(0, 0), Pair(8, 6), Pair(10, 6),
    });
    Pair pos = Pair(0, 0), vel = Pair(11, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(9, 6), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, GroundedMovement_Walkoff) {
    // flat surface with walkoff
    Platform p = Platform({
        Pair(0, 0), Pair(1, 0),
    });
    Pair pos = Pair(0.5, 0), vel = Pair(1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(1, 0), pos);
    EXPECT_EQ(Pair(0.5, 0), vel);

    pos = Pair(0.5, 0);
    vel = Pair(-1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(0, 0), pos);
    EXPECT_EQ(Pair(-0.5, 0), vel);
}

TEST(Platform, checkCollision_Basic) {
    // flat surface with walkoff
    Platform p = Platform({
        Pair(0, 1), Pair(2, 1),
    });
    Pair lastPosition = Pair(1, 0), newPosition = Pair(1, 2);
    Pair out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(lastPosition, newPosition, out),
              FLOOR_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);
}
