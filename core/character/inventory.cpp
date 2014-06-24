/* Item definition*/
//#include "character.h"
//#include "player.h"
#include "inventory.h"


Item::Item()
{
	name = "";
	ID = "";
	wepAtk = 0;
	armDef = 0;
	amount = 0;
	goldCost = 0;
	next = NULL;

}

string Item::getName()
{
	return name;
}

void Item::setName(string itemName)
{
	name = itemName;
}

string Item::getID()
{
	return ID;
}

void Item::setID(string itemID)
{
	ID = itemID;
}

int Item::getWepAtk()
{
	return wepAtk;
}

void Item::setWepAtk(int atk)
{
	wepAtk = atk;
}

int Item::getArmDef()
{
	return armDef;
}

void Item::setArmDef(int def)
{
	armDef = def;
}

int Item::getAmount()
{
	return amount;
}

void Item::setAmount(int itemAmount)
{
	amount = itemAmount;
}

int Item::getGoldCost()
{
	return goldCost;
}

void Item::setGoldCost(int price)
{
	goldCost = price;
}

Item* Item::getNext()
{
	return next;
}

void Item::setNext(Item* theNext)
{
	next = theNext;
}



Inventory::Inventory()
{
	category = "";
	head = NULL;
}

string Inventory::getCategory()
{
	return category;
}

void Inventory::setCategory(string type)
{
	category = type;
}

Item* Inventory::getHead()
{
	return head;
}

void Inventory::setHead(class Item* theHead)
{
	head = theHead;
}

void Inventory::list()
{
	Item *temp = head;
	cout << getCategory() << endl;
	if(temp == NULL)
	{
		cout << "Inventory is empty" << endl;
		return;
	}

	if(temp->getNext() == NULL)
	{
		printList(temp);
	}
	else
	{
		do
		{
		printList(temp);
		temp = temp->getNext();
		} while (temp != NULL);
	}
	cout << "Printed List" << endl;
}

void Inventory::printList(Item *temp)
{
	cout <<"ID: " << temp->getID() << "\t" << "Amount: " << temp->getAmount() << endl;
	cout <<"Name: " << temp->getName() << endl;
		if(temp->getWepAtk() != 0)
			cout << "Attack: " << temp->getWepAtk() << endl;
		if(temp->getArmDef() != 0)
			cout << "Defense: " << temp->getArmDef() << endl;
	cout << endl;
	cout << "What is happening here?" << endl; 
}

void Inventory::add(string itemID, string itemName, int attack, int itemAmount)
{
	string ID = itemID;
	Item *temp2 = head;
	Item *newNode = new Item;

		newNode->setID(ID);
		//cout << "ID set correctly" << endl;
		newNode->setName(itemName);
		//cout << "Name set correctly" << endl;
		newNode->setWepAtk(attack);
		//cout << "Attack set correctly" << endl;
		newNode->setAmount(itemAmount);
		//cout << "Amount set correctly" << endl;
		newNode->setNext(NULL);

	cout << "Head set correctly" << endl;
	if(temp2 != NULL)
	{
	cout << "Temp isn't null so adding another" << endl;
	
		cout << "Adding something" << endl;
		do
		{

			if(temp2->getID() == newNode->getID() && temp2->getNext() == NULL)
			{
				cout << "Adding duplicate item" << endl;
				int counter = temp2->getAmount();
				counter = counter+itemAmount;
				temp2->setAmount(counter);
				delete newNode;
				return;
			}

			if(temp2->getID() == newNode->getID())
			{
				cout << "Adding duplicate item" << endl;
				int counter = temp2->getAmount();
				counter = counter+itemAmount;
				temp2->setAmount(counter);
				delete newNode;
				return;
			}



			if(temp2->getNext() == NULL)		//something here isn't working... set it after?
			{
				temp2->setNext(newNode);
				newNode->setNext(NULL);
				return;
			}

			else
			{
			//cout << "Looping temp inventory" << endl;
			temp2 = temp2->getNext();
			}

		} while(temp2 != NULL);
		return;

	
	}

	else			//temp is equal to NULL
	{
		cout << "List empty, adding new entry to head" << endl;
		setHead(newNode);
		return;
		
	}

}
