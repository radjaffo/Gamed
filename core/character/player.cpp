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
}

void Player::attack(Monster *m)
{
	cout << "Attacking " << m->getName()  << "..."<< endl << endl;
	int y = m->getHp() - Atk;
	m->setHp(y);
	cout << "Hit " << m->getName() << " for " << Atk << " damage!" << endl << endl;
}

void Player::defend()
{
	cout << Name << " defends!" << endl;
	Def = Def*2;
	cout << Def << endl;			//test
}