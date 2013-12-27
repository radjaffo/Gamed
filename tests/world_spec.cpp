#include "gtest/gtest.h"
#include "../core/world.h"
#include <iostream>

using namespace std;

// Generic test to make sure tests are working
TEST(firstTest, abs) {
    EXPECT_EQ(1, abs(-1));
    EXPECT_EQ(1, abs(1));
}

TEST(worldConstructor, World) {
    World *a = new World;

    tmp = a->getHero();

    EXPECT_EQ(tmp, "H");
}