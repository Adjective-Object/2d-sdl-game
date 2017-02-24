#include <math.h>
#include "gtest/gtest.h"
#include "engine/pair.hpp"
#include "terrain/platform.hpp"
#include "terrain/map.hpp"

// void Map::getClosestCollision(
//             Pair const& start,
//             Pair const& end,
//             CollisionDatum & out) {
//     Platform * platform;
//     int segment;
//     Pair position;


TEST(Map, getClosestCollision) {
    Map m = Map ({
        Platform({Point(1,-5), Point(1,5)})
        Platform({Point(2,-5), Point(2,5)})
        Platform({Point(3,-5), Point(3,5)})
        Platform({Point(4,-5), Point(4,5)})
    }, {});

    CollisionDatum collision;

    EXPECT_TRUE(m.getClosestCollision(Point(0,0), Point(0,4), collision));

    EXPECT_EQ(collision.type, WALL_COLLISION);
    EXPECT_EQ(collision.segment, 0);
    EXPECT_EQ(position, Point(1, 0));

}


TEST(Map, getClosestCollision_Miss) {
    Map m = Map ({
        Platform({Point(1,-5), Point(1,5)})
        Platform({Point(2,-5), Point(2,5)})
        Platform({Point(3,-5), Point(3,5)})
        Platform({Point(4,-5), Point(4,5)})
    }, {});

    CollisionDatum collision;

    EXPECT_FALSE(m.getClosestCollision(Point(0,0), Point(10,0), collision));
}


TEST(Map, getClosestEcbCollision) {
    Map m = Map ({
        Platform({Point(1,-5), Point(1,5)})
        Platform({Point(2,-5), Point(2,5)})
        Platform({Point(3,-5), Point(3,5)})
        Platform({Point(4,-5), Point(4,5)})
    }, {});

    CollisionDatum collision;

    Ecb start = Ecb(0,0, 0.3, 0.3);
    Ecb finish = Ecb(0,0, 0.3, 0.3);

    EXPECT_TRUE(true);
}

