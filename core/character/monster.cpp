/* monster definition */
#include "character.h"
#include "monster.h"
#include "player.h"
#include "inventory.h"

Monster::Monster()
{
	Name = "booM";
	ID = 0;
	Atk = 3;
	Def = 3;
	Hp = 25;
	maxHp = 25;
	Exp = 50;
	Gold = 50;
}

void Monster::retaliate(Player *p)
{
	cout << Name << " swings wildly!" << endl << endl;
	int i = p->getDef() + p->getaDef();
	int x = Atk - i;
	if(x <=0)
		x=1;			//incase def beats out enemy atk
	int y = p->getHp() - x;

	p->setHp(y);
	cout << p->getName() << " got hit for " << x << " damage!" << endl << endl;
}