/* monster definition */
#include "character.h"
#include "monster.h"
#include "player.h"

Monster::Monster()
{
	Name = "booM";
	Atk = 2;
	Def = 2;
	Hp = 25;
}

void Monster::retaliate(Player *p)
{
	cout << Name << " swings wildly!" << endl;
	int y = p->getHp() - Atk;
	p->setHp(y);
	cout << p->getName() << " got hit for " << Atk << " damage!" << endl;
}