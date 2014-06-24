/*Player class model*/
#ifndef PLAYER_H
#define PLAYER_H

class Character;
class Monster;
class Inventory;

class Player:public Character
{
public:
   Player();
   void attack(Monster *m);
   void defend();
   void inventoryMenu();
   void addToInventory(string ID, string name, int value, int amount);
};

#endif