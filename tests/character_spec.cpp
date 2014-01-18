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

TEST(Character, getHp)
{
	Character *a = new Character;
	int i = a->getHp();					//expected result 0

	//EXPECT_EQ(a->getHp(), 1);			//expected to fail
	
	EXPECT_EQ(a->getHp(), 0);
}

TEST(Character, setHp)
{
	Character *a = new Character;
	int i = 1;
	int j = 15;
	int c = 0;

	a->setHp(i);					//expected result 1

	//EXPECT_EQ(a->getHp(), 0);			//expected to fail

	EXPECT_EQ(a->getHp(), 1);

	a->setHp(j);					//expected result 15

	EXPECT_EQ(a->getHp(), 15);

	a->setHp(c);					//expected result 0

	EXPECT_EQ(a->getHp(), c);
}

TEST(Character, getmaxHp)
{
	Character *a = new Character;
	
	int i = a->getmaxHp();			//expected result 0

	//EXPECT_EQ(a->getmaxHp(), 1);	//expected to fail

	EXPECT_EQ(i, 0);
}

TEST(Character, setmaxHp)
{
	Character *a = new Character;
	int i = 1;
	int j = 20;
	int c = 500;

	a->setmaxHp(i);					//expected result 1

	//EXPECT_EQ(a->getmaxHp(), 0);		//expected to fail

	EXPECT_EQ(a->getmaxHp(), 1);

	a->setmaxHp(j);					//expected result 20

	EXPECT_EQ(a->getmaxHp(), 20);

	a->setmaxHp(c);					//expected result 500

	EXPECT_EQ(a->getmaxHp(), c);
}

TEST(Character, getExp)
{
	Character *a = new Character;
	
	int i = a->getExp();			//expected result 0

	//EXPECT_EQ(a->getExp(), 1);		//expected to fail

	EXPECT_EQ(i, 0);
}

TEST(Character, setExp)
{
	Character *a = new Character;
	
	int i = 1;
	int j = 15;

	a->setExp(i);					//expected result 1

	//EXPECT_EQ(a->getExp(), 0);		//expected to fail
	
	EXPECT_EQ(a->getExp(), 1);

	a->setExp(j);						//expected result 15

	EXPECT_EQ(a->getExp(), j);
}

TEST(Character, getLevel)
{
	Character *a = new Character;

	int i = a->getLevel();				//expected result -

	//EXPECT_EQ(a->getLevel(), 3);		//expected to fail

	EXPECT_EQ(i, 0);

}

TEST(Character, setLevel)
{
	Character *a = new Character;
	int i = 5;
	int j = 15;

	a->setLevel(i);						//expected result 5

	//EXPECT_EQ(a->getLevel(), 0);		//expected to fail

	EXPECT_EQ(a->getLevel(), 5);

	a->setLevel(j);						//expected result 15

	EXPECT_EQ(a->getLevel(), j);
}

TEST(Character, getnextLevel)
{
	Character *a = new Character;
	int i = a->getnextLevel();			//expected result 0

	EXPECT_EQ(i, 0);
}

TEST(Character, setnextLevel)
{
	Character *a = new Character;
	int i = 100;
	int j = 1000;

	a->setnextLevel(i);					//expected result 100

	//EXPECT_EQ(a->getnextLevel(), 0);	//expected to fail

	EXPECT_EQ(a->getnextLevel(), 100);

	a->setnextLevel(j);					//expected result 1000

	EXPECT_EQ(a->getnextLevel(), j);
}

TEST(Character, getGold)
{
	Character *a = new Character;
	int i = a->getGold();				//expected result 0

	//EXPECT_EQ(a->getGold(), 1);			//expected to fail

	EXPECT_EQ(a->getGold(), 0);
}

TEST(Character, setGold)
{
	Character *a = new Character;
	int j = 5;
	int d = 20000;

	a->setGold(j);						//expected result 5

	//EXPECT_EQ(a->getGold(), 1);			//expected to fail

	EXPECT_EQ(a->getGold(), 5);

	a->setGold(d);						//expected result 20000

	EXPECT_EQ(a->getGold(), d);
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

TEST(Character, getaID)
{
	Character *a = new Character;
	int i = a->getaID();				//expected result 0

	EXPECT_EQ(i, 0);
}

TEST(Character, setaID)
{
	Character *a = new Character;
	int i = 1;
	int j = 10;

	a->setaID(i);						//expected result 1

	//EXPECT_EQ(a->getaID(), 0);		//expected to fail

	EXPECT_EQ(a->getaID(), 1);

	a->setaID(j);						//expected result 10

	EXPECT_EQ(a->getaID(), 10);
}

TEST(Character, getaName)
{
	Character *a = new Character;

	string tmp = a->getaName();			//expected result ""

	EXPECT_EQ(tmp, "");
}

TEST(Character, setaName)
{
	Character *a = new Character;
	string i = "yep";
	string temp = "yeppers";

	a->setaName(i);						//expected result "yep"

	//EXPECT_EQ(a->getaName(), "");		//expected to fail

	EXPECT_EQ(a->getaName(), "yep");

	a->setaName(temp);					//expected result "yeppers"
	
	EXPECT_EQ(a->getaName(), temp);
}

TEST(Character, getaDef)
{
	Character *a = new Character;

	int i = a->getaDef();				//expected result 0

	EXPECT_EQ(i, 0);
}

TEST(Character, setaDef)
{
	Character *a = new Character;
	int i = 1;
	int j = 20;

	a->setaDef(i);						//expected result 1

	//EXPECT_EQ(a->getaDef(), 0);			//expected to fail

	EXPECT_EQ(a->getaDef(), 1);

	a->setaDef(j);						//expected result 20

	EXPECT_EQ(a->getaDef(), j);
}

TEST(Character, getaGold)
{
	Character *a = new Character;
	
	int i = a->getaGold();				//expected result 0

	EXPECT_EQ(i, 0);
}

TEST(Character, setaGold)
{
	Character *a = new Character;
	int i = 200;
	int j = 10000;

	a->setaGold(i);						//expected result 200

	EXPECT_EQ(a->getaGold(), 200);

	a->setaGold(j);						//expected result 10000

	EXPECT_EQ(a->getaGold(), j);
}
/* Nope
TEST(World, goldCheck)
{
	Character *c = new Character;
	World *b = new World;
	int i = 5;
	int j = 0;
	
	c->setGold(i);							//expected result true

	EXPECT_EQ(b->goldCheck(j), true );		


}
*/

