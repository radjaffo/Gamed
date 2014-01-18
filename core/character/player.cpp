/*player definitions*/
#include "character.h"
#include "player.h"
#include "monster.h"

Player::Player()
{
	Name = "debeers";
	Atk = 5;
	Def = 5;
	Hp = 20;
	maxHp = 20;
	Exp = 0;
	Level = 0;
	wName = "stick";
	wID = 0;
	wAtk = 1;
	wGold = 20;
}

void Player::attack(Monster *m)
{
	cout << "Attacking " << m->getName()  << "..."<< endl << endl;
	int x = Atk + wAtk;
	int y = m->getHp() - x;
	m->setHp(y);
	cout << "Hit " << m->getName() << " for " << x << " damage!" << endl << endl;
}

void Player::defend()
{
	cout << Name << " defends!" << endl;
	Def = Def*2;
	cout << Def << endl;			//test
}