#include "gtest/gtest.h"
#include "./platform.cpp"
#include "./player.cpp"
#include "./util.cpp"
#include "./ecb.cpp"
#include "./map.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
