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

bool World::createMap() {
  for(int i = 0; i < 5; i++) {
    for(int j=0; j < 5; j++) {
      Map[i][j] = '_';
      cout << Map[i][j];
    }
    cout << "\n";
  }
  // Creates an empty map for the world using an array of strings
  // Return TRUE: Success
  // Return FALSE: Failed
  return(true);   // True - Success
}







string World::getHero() {
  return Hero;
}