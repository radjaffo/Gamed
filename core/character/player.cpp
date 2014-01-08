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
}

void Player::attack(Monster *m)
{
	cout << "Attacking " << m->getName()  << "..."<< endl << endl;
	int y = m->getHp() - Atk;
	m->setHp(y);
	cout << "Hit " << m->getName() << " for " << Atk << " damage!" << endl << endl;
	//cout << m->getName() << ":" << m->getHp() << endl;
}

void Player::defend()
{
	cout << Name << " defends!" << endl;
	Def = Def*2;
	cout << Def << endl;			//test
}
