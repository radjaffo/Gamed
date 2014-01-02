/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#include <cstdlib>

#include "world.h"
#include "character/character.h"

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

void World::looper()
{
  int x, y, cc=3;
  string choice;
  cout << endl << endl <<"Loopin this sht" << endl;
  do
  {
    cout << "Player : hp" << endl << "Monster : hp" << endl<< endl;
    cout << "What would you like to do?" << endl;
    cout << "1.attack" << endl << "2.run" << endl << "3.defend" << endl;
    cin >> choice;
    if(choice == "attack")
    {
      cout << endl <<"Player attacks the moonstar" << endl << endl << endl;
    }
    else if(choice == "run")
    {
      cout << endl <<"Player runs like little girl" << endl << endl;
      cc = 0;
      cout << "Success, you got away!" << endl;
    }
    else if(choice == "defend")
    {
      cout << endl <<"Defending!" << endl << endl << endl;
    }
    else
      cout << "Error! incorrect entry, please try again" << endl;


  }while(cc!=0);
}