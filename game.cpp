#include <iostream>
#include <string>
#include <ctime>
#include "core/world.h"
#include "core/character/character.h"
#include "core/character/player.h"
#include "core/character/monster.h"
 
using namespace std;

int main()
{

  World *a = new World;
  Character *b = new Character;
  //Player *c = new Player;
  //Monster *d = new Monster;

  
  a->displayMap();
  /*for(int i=0; i < 10; i++) 
  {
    a->randomMoveBoth();
    a->displayMap();
  }*/

  //c->attack(d);   //test player attack function
  //d->retaliate(c);  //test monster attack function

  a->looper();    //test loop function


  return 0;
}