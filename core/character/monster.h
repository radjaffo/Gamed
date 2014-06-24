/*Monster class blah*/
#ifndef MONSTER_H
#define MONSTER_H

class Character;
class Player;
class Inventory;

class Monster:public Character
{
public:
    Monster();
    void retaliate(Player *p);
};

#endif