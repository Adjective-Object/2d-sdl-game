#include "gtest/gtest.h"
#include "player/player.hpp"

TEST(Player, moveTo) {
    Player p = Player("./assets/attributes.yaml", 0, 0);

    Ecb oldEcb = p.currentCollision->root;
    p.moveTo(Pair(10, 10));

    EXPECT_EQ(p.currentCollision->root.left - oldEcb.left, Pair(10, 10));
    EXPECT_EQ(p.currentCollision->root.right - oldEcb.right, Pair(10, 10));
    EXPECT_EQ(p.currentCollision->root.top - oldEcb.top, Pair(10, 10));
    EXPECT_EQ(p.currentCollision->root.bottom - oldEcb.bottom, Pair(10, 10));
}
