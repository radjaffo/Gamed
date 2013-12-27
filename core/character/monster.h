/*Monster class blah*/
#ifndef MONSTER_H
#define MONSTER_H
//#include "character.h"

class Character;
class Player;

class Monster:public Character
{
public:
    Monster();
    void retaliate(Player *p);
};

#endif