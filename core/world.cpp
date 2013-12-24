/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#include "world.h"

using namespace std;

World::World() {
  Hero = "H";
  Mob = "M";

  cout << Hero << " \n " << Mob;
}












string World::getHero() {
  return Hero;
}