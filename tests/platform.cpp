#include <math.h>
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

#define M_PI 3.14159265358979323846 /* pi */
// note: it looks like calculations are done in y-inverted
// cartesian coordinates
TEST(Platform, movePointToSegmentSpace) {
    Pair origin = Pair(0, 0);
    Pair other = Pair(0, 0);

    EXPECT_EQ(Platform::movePointToSegmentSpace(origin, 0, other), Pair(0, 0));

    // 45 degree triangle
    other = Pair(1, 0);
    EXPECT_EQ(
        Platform::movePointToSegmentSpace(origin,
                                          -M_PI / 4,  // angle of the platform
                                          other),
        Pair(sqrt(2) / 2, sqrt(2) / 2));

    // 45 degree triangle in negative
    EXPECT_EQ(
        Platform::movePointToSegmentSpace(origin,
                                          M_PI / 4,  // angle of the platform
                                          other),
        Pair(sqrt(2) / 2, -sqrt(2) / 2));

    // same as above, but not at origin

    // 45 degree triangle
    origin = Pair(1, 0);
    other = Pair(2, 0);
    EXPECT_EQ(
        Platform::movePointToSegmentSpace(origin,
                                          -M_PI / 4,  // angle of the platform
                                          other),
        Pair(sqrt(2) / 2, sqrt(2) / 2));

    // 45 degree triangle in negative
    EXPECT_EQ(
        Platform::movePointToSegmentSpace(origin,
                                          M_PI / 4,  // angle of the platform
                                          other),
        Pair(sqrt(2) / 2, -sqrt(2) / 2));
}

TEST(Platform, checkCollision_Basic_Floor) {
    // collision with floor
    Platform p = Platform({
        Pair(0, 1), Pair(2, 1),
    });
    Pair lastPosition = Pair(1, 0), newPosition = Pair(1, 2);
    Pair out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(lastPosition, newPosition, out),
              FLOOR_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);
}

TEST(Platform, checkCollision_Reverse_Floor) {
    // collising going up through floor
    Platform p = Platform({
        Pair(0, 1), Pair(2, 1),
    });
    Pair lastPosition = Pair(1, 0), newPosition = Pair(1, 2);
    Pair out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(newPosition, lastPosition, out), NO_COLLISION);
}

TEST(Platform, checkCollision_Basic_Wall) {
    // collision through wall
    Platform p = Platform({
        Pair(1, 2), Pair(1, 0),
    });
    Pair lastPosition = Pair(0, 1), newPosition = Pair(2, 1);
    Pair out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(lastPosition, newPosition, out), WALL_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);
}

TEST(Platform, checkCollision_Reverse_Wall) {
    // collision through wall
    Platform p = Platform({
        Pair(1, 2), Pair(1, 0),
    });
    Pair lastPosition = Pair(0, 1), newPosition = Pair(2, 1);
    Pair out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(newPosition, lastPosition, out), NO_COLLISION);
}

TEST(Platform, checkCollision_Diagonal_Floor) {
    // check that up to 45 degrees is considered a floor collision
    Platform p = Platform({
        Pair(0, 0), Pair(2, 2),
    });
    Pair lastPosition = Pair(0, 2), newPosition = Pair(2, 0);
    Pair out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(lastPosition, newPosition, out),
              FLOOR_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);

    p = Platform({
        Pair(0, 0), Pair(2, -2),
    });
    lastPosition = Pair(2, 0), Pair(0, -2);
    out = Pair(0, 0);

    EXPECT_EQ(p.checkCollision(lastPosition, newPosition, out),
              FLOOR_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);
}
