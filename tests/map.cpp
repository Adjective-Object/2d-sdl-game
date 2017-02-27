#include <math.h>
#include "gtest/gtest.h"
#include "engine/pair.hpp"
#include "terrain/platform.hpp"
#include "terrain/map.hpp"
#include "lib/mock-player.hpp"

// void Map::getClosestCollision(
//             Pair const& start,
//             Pair const& end,
//             CollisionDatum & out) {
//     Platform * platform;
//     int segment;
//     Pair position;

TEST(Map, getClosestCollision) {
    std::vector<Platform> platforms = {Platform({Pair(1, 5), Pair(1, -5)}),
                                       Platform({Pair(2, 5), Pair(2, -5)}),
                                       Platform({Pair(3, 5), Pair(3, -5)}),
                                       Platform({Pair(4, 5), Pair(4, -5)})};
    Map m = Map(platforms, {});

    CollisionDatum collision;

    ASSERT_TRUE(m.getClosestCollision(Pair(0, 0), Pair(4, 0), collision));

    EXPECT_EQ(WALL_COLLISION, collision.type);
    EXPECT_EQ(m.getPlatform(0)->getSegment(0), collision.segment);
    EXPECT_EQ(Pair(1, 0), collision.position);
}

TEST(Map, getClosestCollision_Miss) {
    Map m = Map({Platform({Pair(1, -5), Pair(1, 5)}),
                 Platform({Pair(2, -5), Pair(2, 5)}),
                 Platform({Pair(3, -5), Pair(3, 5)}),
                 Platform({Pair(4, -5), Pair(4, 5)})},
                {});

    CollisionDatum collision;

    EXPECT_FALSE(m.getClosestCollision(Pair(0, 0), Pair(10, 0), collision));
}

// TEST(Map, getClosestEcbCollision) {
//     Map m = Map({Platform({Pair(1, -5), Pair(1, 5)}),
//                  Platform({Pair(2, -5), Pair(2, 5)}),
//                  Platform({Pair(3, -5), Pair(3, 5)}),
//                  Platform({Pair(4, -5), Pair(4, 5)})},
//                 {});

//     CollisionDatum collision;

//     Ecb start = Ecb(0, 0, 0.3, 0.3);
//     Ecb finish = Ecb(0, 0, 0.3, 0.3);

//     EXPECT_TRUE(true);
// }

TEST(MAP, movePlayer_NoCollisions) {
    // setup scene
    Player p = makeMockPlayer(Pair(10, 10));
    Map m = Map({}, {});

    Pair requestedMotion = Pair(5, -2);
    m.movePlayer(p, requestedMotion);

    EXPECT_EQ(Pair(15, 8), p.position);
}

TEST(MAP, movePlayer_Grounded_Flat) {
    // setup scene
    Player p = makeMockPlayer(Pair(10, 10));
    p.init();
    Map m = Map({Platform({Pair(1, 10), Pair(20, 10)})}, {});

    p.land(m.getPlatform(0), Pair(10, 10));
    Pair requestedMotion = Pair(5, 0);
    m.movePlayer(p, requestedMotion);

    EXPECT_EQ(Pair(15, 10), p.position);
}
