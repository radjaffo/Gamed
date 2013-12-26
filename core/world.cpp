/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#include <cstdlib>

#include "world.h"
#include "character.h"

using namespace std;

World::World() {
  Hero = "H";
  Mob = "M";
  createMap();
  placeCharacters();
}


bool World::createMap() {
  for(int i = 0; i < 5; i++) {
    for(int j=0; j < 5; j++) {
      Map[i][j] = '_';
    }
  }
  // Creates an empty map for the world using an array of strings
  // Return TRUE: Success
  // Return FALSE: Failed
  return(true);   // True - Success
}

void World::displayMap() 
{
  for(int i=0; i < 5; i++) 
  {
    for(int j=0; j< 5; j++)
    {
     cout << Map[i][j];   
    }
    cout << endl;
  }
}

void World::placeCharacters()
// Insert characters into the map in static spots
{
  Map[0][0] = Hero;
  Map[4][4] = Mob;
}

void World::randomMoveBoth()
{
  int x = rand()%5;
  int y = rand()%5;

  cout << "[" << x << "," << y << "]" << endl;
  Map[x][y] = Hero;
}

string World::getHero() {
  return Hero;
}

string World::getMob() {
  return Mob;
}