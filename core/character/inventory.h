/*Item Class model*/
#include <iostream>
#include <string>
#ifndef INVENTORY_H
#define INVENTORY_H

using namespace std;

class Item
{
private:
	string name;
	string ID;
	int wepAtk;
	int armDef;
	int amount;
	int goldCost;
	Item *next;

public:
	Item();

	string getName();
	void setName(string itemName);

	string getID();
	void setID(string ID);

	int getWepAtk();
	void setWepAtk(int atk);

	int getArmDef();
	void setArmDef(int def);

	int getAmount();
	void setAmount(int itemAmount);

	int getGoldCost();
	void setGoldCost(int price);

	Item *getNext();
	void setNext(Item* theNext);
};

class Inventory
{
private:
string category;
Item *head;

public:
	Inventory();

	string getCategory();
	void setCategory(string type);

	Item *getHead();
	void setHead(Item* theHead);

	void list();
	void printList(Item* temp);
	void add(string itemID, string itemName, int attack, int itemAmount);
	void equip();
	void trash();

};


#endif
