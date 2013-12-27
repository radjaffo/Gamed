/*Player class model*/
#ifndef PLAYER_H
#define PLAYER_H
//#include "character.h"
//#include "monster.h"

class Character;
class Monster;

class Player:public Character
{
public:
   Player();
   void attack(Monster *m);
   void defend();
};

#endif