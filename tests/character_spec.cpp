#include "gtest/gtest.h"
#include <iostream>


#include "../core/character/character.h"


using namespace std;

// Generic test to make sure tests are working


TEST(Character, getId) {
    Character *a = new Character;

    int tmp = a->getID();	//expected result 0

    EXPECT_EQ(tmp, 0); 
}