#include "gtest/gtest.h"
#include <iostream>


#include "../core/character/character.h"
#include "../core/world.h"


using namespace std;

// Generic test to make sure tests are working


TEST(Character, getId)
 {
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

TEST(Character, getwName)
{
	Character *c = new Character;

	string name = "Stick";
	string nope = "failing";

	c->setwName(name);

	//EXPECT_EQ(c->getwName(), nope); 		//expected to fail

	EXPECT_EQ(c->getwName(), name);			//expected result "Stick"

}

TEST(Character, getwID)
{
	Character *d = new Character;
	int i = 0;
	int j = 2;

	d->setwID(i);

	//EXPECT_EQ(d->getwID(), j);			//expected to fail

	EXPECT_EQ(d->getwID(), i);			//expected result 0
}

TEST(Character, getwAtk)
{
	Character *a = new Character;
	int i = 1;
	int j = 2;

	a->setwAtk(i);

	//EXPECT_EQ(a->getwAtk(), j);				//expected to fail

	EXPECT_EQ(a->getwAtk(), i);			//expected result 1
	delete a;
}

TEST(Character, getwGold)
{
	Character *a = new Character;
	int i = 50;
	int j = 0;

	a->setwGold(i);

	//EXPECT_EQ(a->getwGold(), j);				//expected to fail

	EXPECT_EQ(a->getwGold(), i);			//expected result 50
}