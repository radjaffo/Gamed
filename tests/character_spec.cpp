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

	EXPECT_EQ(b->getID(), 1);
	
	b->setID(c);		//expected result 10000

	EXPECT_EQ(b->getID(), 10000);

}

TEST(Character, generateID)
{
	Character *a = new Character;
	int i = 1;
	int d = 53;


	a->generateID(i);		//expected to increment i;

	int j = a->getID();		//expected result 2

	//EXPECT_EQ(a->getID() , 3);		//expected to fail	

	EXPECT_EQ(a->getID(), 2);

	a->generateID(d);

	int c = a->getID();		//expected result 54

	EXPECT_EQ(a->getID(), 54);

}

TEST(Character, getName)
{
	Character *a = new Character;
	string name = a->getName();		//expected result ""

	EXPECT_EQ(a->getName(), "");


}

TEST(Character, setName)
{
	Character *a = new Character;
	string name = "Dethrex";
	string name2 = "Cleetus";

	a->setName(name);				//expected result "Dethrex"

	EXPECT_EQ(a->getName(), "Dethrex");

	a->setName(name2);				//expected result "Cleetus"

	EXPECT_EQ(a->getName(), name2);
}

TEST(Character, getAtk)
{
	Character *a = new Character;
	
	int temp = a->getAtk();			//expected result 0

	//EXPECT_EQ(a->getAtk(), 2);		//expected to fail

	EXPECT_EQ(a->getAtk(), 0);



}

TEST(Character, setAtk)
{
	Character *a = new Character;

	int b = 1;
	int c = 50;

	a->setAtk(b);						//expected result 1

	//EXPECT_EQ(a->getAtk(), 0);			//expected to fail

	EXPECT_EQ(a->getAtk(), 1);

	a->setAtk(c);						//expected result 50

	EXPECT_EQ(a->getAtk(), 50);
}

TEST(Character, getDef)
{
	Character *a = new Character;

	int temp = a->getDef();				//expected result 0

	//EXPECT_EQ(temp, 1);					//expected to fail

	EXPECT_EQ(temp, 0);
}

TEST(Character, setDef)
{
	Character *a = new Character;
	int i = 1;
	int j = 20;
	int h = 5;

	a->setDef(i);						//expected result 1

	//EXPECT_EQ(a->getDef(), 0);			//expected to fail

	EXPECT_EQ(a->getDef(), 1);

	a->setDef(j);						//expected result 20

	EXPECT_EQ(a->getDef(), 20);		

	a->setDef(h);						//expected result 5

	EXPECT_EQ(a->getDef(), h);
}
TEST(Character, getwName)
{
	Character *c = new Character;

	string name = "Stick";
	string nope = "failing";

	c->setwName(name);						//expected result "Stick"

	//EXPECT_EQ(c->getwName(), nope); 		//expected to fail

	EXPECT_EQ(c->getwName(), "Stick");			

}

TEST(Character, getwID)
{
	Character *d = new Character;
	int i = 0;
	int j = 2;

	d->setwID(i);						//expected result 0

	//EXPECT_EQ(d->getwID(), j);			//expected to fail

	EXPECT_EQ(d->getwID(), 0);			
}

TEST(Character, getwAtk)
{
	Character *a = new Character;
	int i = 1;
	int j = 2;

	a->setwAtk(i);						//expected result 1

	//EXPECT_EQ(a->getwAtk(), j);				//expected to fail

	EXPECT_EQ(a->getwAtk(), 1);	
	delete a;
}

TEST(Character, getwGold)
{
	Character *a = new Character;
	int i = 50;
	int j = 0;

	a->setwGold(i);							//expected result 50

	//EXPECT_EQ(a->getwGold(), j);				//expected to fail

	EXPECT_EQ(a->getwGold(), i);

	a->setwGold(j);							//expected result 0

	EXPECT_EQ(a->getwGold(), 0);
}

