/* monster definition */
#include "character.h"
#include "monster.h"
#include "player.h"

Monster::Monster()
{
	Name = "booM";
	Atk = 3;
	Def = 3;
	Hp = 25;
	maxHp = 25;
}

void Monster::retaliate(Player *p)
{
	cout << Name << " swings wildly!" << endl << endl;
	int x = Atk - p->getDef();
	if(x <=0)
		x=1;			//incase def beats out enemy atk
	int y = p->getHp() - x;

	p->setHp(y);
	cout << p->getName() << " got hit for " << x << " damage!" << endl << endl;
	//cout << p->getName() << " : " << p->getHp() << endl;
}