#include <math.h>
#include "gtest/gtest.h"
#include "engine/pair.hpp"
#include "terrain/platform.hpp"
#include "terrain/platformsegment.hpp"

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
    // flat surface with rightward movement accross multiple surfaces
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

TEST(Platform, GroundedMovement_Walkoff_Wall) {
    // flat surface with walkoff
    Platform p = Platform({
        Pair(0, 3), Pair(0, 0), Pair(1, 0), Pair(1, 3),
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

TEST(Platform, GroundedMovement_Walkoff_Wall_Platform) {
    // flat surface with walkoff
    //
    //     ____
    //  __|    |__
    //
    Platform p = Platform({
        Pair(-1, 3), Pair(0, 3), Pair(0, 0), Pair(1, 0), Pair(1, 3), Pair(2, 3),
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

TEST(Platform, GroundedMovmeent_Flat_ConvolutedSurface) {
    // flat surface with walkoff
    //
    //     _______
    //   __\     /__
    //
    Platform p = Platform({
        Pair(-1, 1), Pair(0.25, 1), Pair(0, 0), Pair(1, 0), Pair(0.75, 1),
        Pair(2, 1),
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

TEST(Platform, GroundedMovement_WalkIntoConvolutedSurface) {
    //
    //     _______
    //   __\     /__
    //
    Platform p = Platform({
        Pair(-1, 1), Pair(0.25, 1), Pair(0, 0), Pair(1, 0), Pair(0.75, 1),
        Pair(2, 1),
    });
    Pair pos = Pair(-0.5, 1), vel = Pair(1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(pos, Pair(0.25, 1));
    EXPECT_EQ(vel, Pair(0.25, 0));

    pos = Pair(1.5, 1);
    vel = Pair(-1, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(pos, Pair(0.75, 1));
    EXPECT_EQ(vel, Pair(-0.25, 0));
}

TEST(Platform, GroundedMovement_WalkFromExactEndOfSurface) {
    //
    //   _______
    //
    Platform p = Platform({
        Pair(1, 1), Pair(3, 1),
    });
    Pair pos = Pair(1, 1), vel = Pair(0, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(1, 1), pos);
    EXPECT_EQ(Pair(0, 0), vel);

    pos = Pair(3, 1);
    vel = Pair(0, 0);
    p.groundedMovement(pos, vel);

    EXPECT_EQ(Pair(3, 1), pos);
    EXPECT_EQ(Pair(0, 0), vel);
}

TEST(Platform, isWall) {
    EXPECT_FALSE(Platform::isWall(0));
    EXPECT_FALSE(Platform::isWall(0.25 * M_PI));
    EXPECT_FALSE(Platform::isWall(-0.25 * M_PI));
    EXPECT_FALSE(Platform::isWall(0.3 * M_PI));
    EXPECT_FALSE(Platform::isWall(-0.3 * M_PI));

    EXPECT_TRUE(Platform::isWall(0.5 * M_PI));
    EXPECT_TRUE(Platform::isWall(-0.5 * M_PI));
    EXPECT_TRUE(Platform::isWall(0.6 * M_PI));
    EXPECT_TRUE(Platform::isWall(-0.6 * M_PI));
    EXPECT_TRUE(Platform::isWall(0.7 * M_PI));
    EXPECT_TRUE(Platform::isWall(-0.7 * M_PI));
    EXPECT_TRUE(Platform::isWall(0.8 * M_PI));
    EXPECT_TRUE(Platform::isWall(-0.8 * M_PI));
    EXPECT_TRUE(Platform::isWall(0.9 * M_PI));
    EXPECT_TRUE(Platform::isWall(-0.9 * M_PI));
}

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
        Pair(-1, 1), Pair(2, 1),
    });
    Pair lastPosition = Pair(1, 0), newPosition = Pair(1, 2);
    Pair out = Pair(0, 0);
    PlatformSegment segment;

    ASSERT_EQ(p.checkCollision(lastPosition, newPosition, out, segment,
                               FLOOR_COLLISION),
              FLOOR_COLLISION);
    ASSERT_EQ(Pair(1, 1), out);
    EXPECT_EQ(Pair(-1, 1), *segment.firstPoint());
    EXPECT_EQ(Pair(2, 1), *segment.secondPoint());
}

TEST(Platform, checkCollision_Reverse_Floor) {
    // collising going up through floor
    Platform p = Platform({
        Pair(0, 1), Pair(2, 1),
    });
    Pair lastPosition = Pair(1, 0), newPosition = Pair(1, 2);
    Pair out = Pair(0, 0);
    PlatformSegment segment;

    ASSERT_EQ(p.checkCollision(newPosition, lastPosition, out, segment,
                               FLOOR_COLLISION),
              NO_COLLISION);
}

TEST(Platform, checkCollision_Basic_Wall) {
    // collision through wall
    Platform p = Platform({
        Pair(1, 2), Pair(1, 0),
    });
    Pair lastPosition = Pair(0, 1), newPosition = Pair(2, 1);
    Pair out = Pair(0, 0);
    PlatformSegment segment;

    ASSERT_EQ(p.checkCollision(lastPosition, newPosition, out, segment,
                               WALL_COLLISION),
              WALL_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);

    EXPECT_EQ(Pair(1, 2), *segment.firstPoint());
    EXPECT_EQ(Pair(1, 0), *segment.secondPoint());
}

TEST(Platform, checkCollision_Reverse_Wall) {
    // collision through wall
    Platform p = Platform({
        Pair(1, 2), Pair(1, 0),
    });
    Pair lastPosition = Pair(0, 1), newPosition = Pair(2, 1);
    Pair out = Pair(0, 0);
    PlatformSegment segment;

    ASSERT_EQ(p.checkCollision(newPosition, lastPosition, out, segment,
                               WALL_COLLISION),
              NO_COLLISION);
}

TEST(Platform, checkCollision_Diagonal_Floor) {
    // check that up to 45 degrees is considered a floor collision
    Platform p = Platform({
        Pair(0, 0), Pair(2, 2),
    });
    Pair newPosition = Pair(0, 2), lastPosition = Pair(2, 0);
    Pair out = Pair(0, 0);
    PlatformSegment segment;

    ASSERT_EQ(p.checkCollision(lastPosition, newPosition, out, segment,
                               FLOOR_COLLISION),
              FLOOR_COLLISION);
    EXPECT_EQ(Pair(1, 1), out);

    EXPECT_EQ(Pair(0, 0), *segment.firstPoint());
    EXPECT_EQ(Pair(2, 2), *segment.secondPoint());

    p = Platform({
        Pair(0, 0), Pair(2, -2),
    });
    lastPosition = Pair(0, -2);
    newPosition = Pair(2, 0);
    out = Pair(0, 0);

    ASSERT_EQ(p.checkCollision(lastPosition, newPosition, out, segment,
                               FLOOR_COLLISION),
              FLOOR_COLLISION);
    EXPECT_EQ(out, Pair(1, -1));

    EXPECT_EQ(Pair(0, 0), *segment.firstPoint());
    EXPECT_EQ(Pair(2, -2), *segment.secondPoint());
}

TEST(Platform, checkCollision_Diagonal_Floor_Miss) {
    // check that collisions missing the platform do not trigger
    // platform collision
    Platform p = Platform({
        Pair(0, 0), Pair(2, 2),
    });
    Pair newPosition = Pair(0, 2), lastPosition = Pair(3, 3);
    Pair out = Pair(0, 0);
    PlatformSegment segment;

    ASSERT_EQ(p.checkCollision(lastPosition, newPosition, out, segment,
                               WALL_COLLISION),
              NO_COLLISION);
    EXPECT_EQ(out, Pair(0, 0));

    p = Platform({
        Pair(0, 0), Pair(2, -2),
    });
    lastPosition = Pair(0, -2);
    newPosition = Pair(-3, -4);
    out = Pair(0, 0);

    ASSERT_EQ(p.checkCollision(lastPosition, newPosition, out, segment,
                               WALL_COLLISION),
              NO_COLLISION);
    EXPECT_EQ(out, Pair(0, 0));
}

TEST(Platform, checkCollision_Playtest_1) {
    // convoluted floor surface
    Platform p = Platform({
        Pair(0.1, 2.0), Pair(0.1, 1.35), Pair(0.7, 1.35), Pair(0.7, 1.2),
        Pair(0.9, 1.2), Pair(0.9, 1.6), Pair(2.2, 1.6), Pair(2.0, 2.0),
        Pair(2.0, 2.0), Pair(2.4, 2.0), Pair(3, 1.0), Pair(3.4, 1.0),

    });

    Pair a1 = Pair(0.737943, 1.13575);
    Pair a2 = Pair(0.677943, 1.23575);
    Pair b1 = Pair(0.737943, 1.16833);
    Pair b2 = Pair(0.677943, 1.26833);

    EdgeCollision e;

    ASSERT_TRUE(p.checkEdgeCollision(a1, a2, b1, b2, e));
}

TEST(Platform, pointsIterator) {
    std::vector<Pair> pts = std::vector<Pair>({
        Pair(0.1, 2.0), Pair(0.1, 1.35), Pair(0.7, 1.35), Pair(0.7, 1.2),
        Pair(0.9, 1.2), Pair(0.9, 1.6), Pair(2.2, 1.6), Pair(2.0, 2.0),
        Pair(2.4, 2.0), Pair(3, 1.0), Pair(3.4, 1.0),
    });
    std::set<Pair> pts_set = std::set<Pair>(pts.begin(), pts.end());

    Platform platform = Platform(pts);
    for (Pair p : platform.points_iter()) {
        auto position = pts_set.find(p);
        pts_set.erase(position);
    }

    ASSERT_TRUE(pts_set.size() == 0) << std::endl;
    if (pts_set.size() != 0) {
        std::cout << "set contains:" << std::endl;
        for (Pair p : pts_set) {
            std::cout << "    " << p << std::endl;
        }
    }
}

TEST(Platform, segmentsIterator) {
    std::vector<Pair> pts = std::vector<Pair>({
        Pair(0.1, 2.0), Pair(0.1, 1.35), Pair(0.7, 1.35), Pair(0.7, 1.2),
        Pair(0.9, 1.2), Pair(0.9, 1.6), Pair(2.2, 1.6), Pair(2.0, 2.0),
        Pair(2.4, 2.0), Pair(3, 1.0), Pair(3.4, 1.0),
    });

    Platform platform = Platform(pts);
    std::set<PlatformSegment> segment_set = std::set<PlatformSegment>();

    for (size_t i = 0; i < pts.size() - 1; i++) {
        PlatformSegment s = platform.getSegment(i);
        segment_set.insert(s);
    }

    for (PlatformSegment s : platform.segments_iter()) {
        auto position = segment_set.find(s);
        segment_set.erase(position);
    }

    ASSERT_TRUE(segment_set.size() == 0) << std::endl;
    if (segment_set.size() != 0) {
        std::cout << "set contains:" << std::endl;
        for (PlatformSegment s : segment_set) {
            std::cout << "    " << s << std::endl;
        }
    }
}
