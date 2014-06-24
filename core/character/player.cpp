/*player definitions*/
#include "character.h"
#include "player.h"
#include "monster.h"
#include "inventory.h"


Player::Player()
{
	Name = "Generic";
	Atk = 5;
	Def = 5;
	Hp = 20;
	maxHp = 20;
	Exp = 0;
	Level = 0;
	Gold = 0;
	wName = "Stick";
	wID = 0;
	wAtk = 1;
	wGold = 20;
	nextLevel = 100;
	aName = "Ragz";
	aDef = 1;
	aGold = 20;

	backpack = new Inventory[3];
	backpack[0].setCategory("Weapons");
	backpack[1].setCategory("Armor");
	backpack[2].setCategory("Items");
}

void Player::attack(Monster *m)
{
	cout << "Attacking " << m->getName()  << " with your mighty " << wName << " ..."<< endl << endl;
	int x = Atk + wAtk;
	int j = m->getDef();
	x = x-j;
	if(x <= 0)
		x = 1;
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

void Player::inventoryMenu()
{
	int inventoryChoice;
	for(int i=0; i < 3; i++)
	{
		cout << i+1 << ": " << backpack[i].getCategory() << endl;
	}
	cin >> inventoryChoice;
	switch(inventoryChoice)
	{
	case 1:
	backpack[0].list();
	cout << "Yep" << endl;
	addToInventory("001", "knife", 3, 1);
	backpack[0].list();
	break;

	case 2:
	backpack[1].list();

	addToInventory("101", "shell", 4, 1);
	addToInventory("102", "plate", 4, 1);
	backpack[1].list();
	break;
	case 3:
	backpack[2].list();
	break;
	default:
	cout << "Error, incorrect entry" << endl;
	break;
	}

}

void Player::addToInventory(string itemID, string itemName, int itemValue, int itemAmount)
{
	int placer;
	string ID = itemID;
	string name = itemName;
	//int value = itemValue;
	int amount = itemAmount;
	cout << "ID starter is " << ID[0] << endl;
	if(ID[0] == '0')
		placer = 0;
	if(ID[0] == '1')
		placer = 1;
	if(ID[0] == '2')
		placer = 2;
	for(int i=0; i < 3; i++)
	{
		if(i == placer)
		{
			cout << "Got to here" << endl;
			backpack[i].add(ID, name, itemValue, amount);
		}
	}
}

