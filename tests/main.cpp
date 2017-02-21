#include "gtest/gtest.h"
#include "./platform.cpp"
#include "./util.cpp"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
