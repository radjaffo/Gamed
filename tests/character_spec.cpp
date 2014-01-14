#include "gtest/gtest.h"
#include <iostream>


#include "../core/character/character.h"
#include "../core/world.h"


using namespace std;

// Generic test to make sure tests are working


TEST(Character, getId) {
    Character *a = new Character;


    int tmp = a->getID();	//expected result 0

    EXPECT_EQ(tmp, 0); 
}

TEST(Character, setId)
{
	Character *b = new Character;

	int i = 3;
	int j = 1;
	int c = 10000;

	b->setID(i);		//expected result 3

	EXPECT_EQ(b->getID(), i);

	b->setID(j);		//expected result 1

	EXPECT_EQ(b->getID(), j);
	
	b->setID(c);		//expected result 10000

	EXPECT_EQ(b->getID(), c);

}

Test(World, weaponList)
{
	World *c = new World;

	string weapons = "000 nope nope";
	string weps = "001 Dagger 01";	//expected result 001

	EXPECT_EQ(c->weaponList(), weapons); 		//expected to fail

	EXPECT_EQ(c->weaponList(), weps);

}