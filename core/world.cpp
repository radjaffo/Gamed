/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "world.h"
#include "character/character.h"
#include "character/player.h"
#include "character/monster.h"

using namespace std;

World::World() {
  Hero = "H";
  Mob = "M";
  createMap();
  placeCharacters();
  c = new Player;
  d = new Monster;
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
  srand(time(NULL)%50);
  int y = rand()%5;

  cout << "[" << x << "," << y << "]" << endl;
  Map[x][y] = Hero;
  srand(time(NULL)%50);
  int a = rand()%5;
  srand(time(NULL)%10);
  int b = rand()%5;
  Map[a][b] = Mob;
  cout << "[" << a << "," << b << "]" << endl;

  if (Map[x][y] == Map[a][b])
  {
    cout << "Monster encountered!! Time to fight!" << endl;
   fight();
  }
}

string World::getHero() {
  return Hero;
}

string World::getMob() {
  return Mob;
}
void World::looper()
{
 int x, y, mc = 1;
 string choice;
 //Player *c = new Player; 
 //Monster *d = new Monster;
 createHero();
 do
 {
  cout << endl << endl << c->getName() << " : " << c->getHp() << endl << endl;
  cout << "1. Search" << endl << "2. Quit" << endl;
  cin >> choice;
  if(c->getHp() <= 0)
    mc = 2;
  if(choice == "search")
  {
    randomMoveBoth();
  }
  if(choice == "quit")
  {
    cout <<"Thanks for playing, goodbye!" << endl;
    mc = 2;
  }
 }
 while(mc == 1);
}

void World::fight()
{
  int x, y, cc=3;
  string choice;
 //Player *c = new Player; 
 //Monster *d = new Monster;
  do
  {
    srand(time(NULL));
    if(c->getHp() <=0)
    {
      cc = 1;
      break;
    }
    else if (d->getHp() <=0)
    {
      cc = 1;
      break;
    }
    else
    cout << endl << c->getName() << " : " << c->getHp() << endl << d->getName() << " : " << d->getHp() << endl<< endl;
    cout << "What would you like to do?" << endl;
    cout << "1.attack" << endl << "2.run" << endl << "3.defend" << endl;
    cin >> choice;
    if(choice == "attack")
    {
      int b = rand()%100+1;
      cout << endl << "Player attacks the moonstar" << endl << endl << endl;
      c->attack(d);
      d->retaliate(c);
    }
    else if(choice == "run")
    {
      int b = rand()%100+1;
      cout << endl <<"Player runs like little girl" << endl << endl;
      if(b > 40)
      {
      cc = 1;
      cout << "Success, you got away!" << endl;
      }
      else
      {
      cout << "Failed to run!" <<endl;
      d->retaliate(c);
      }
    }
    else if(choice == "defend")
    {
      cout << endl <<"Defending!" << endl << endl << endl;
      int x = c->getDef();
      x= x*2;
      c->setDef(x);
      d->retaliate(c);
      x=x/2;
      c->setDef(x);
    }
    else
      cout << "Error! incorrect entry, please try again" << endl;


  }while(cc != 1);
  if(c->getHp() <= 0)
  {
    cout << "Oh noes you are dead :(" << endl;
    cout << "Game over!" << " Thanks for playing!" << endl;
  }
  else if(d->getHp() <= 0)
  { 
    cout << "You win! " << d->getName() << " is defeated!" << endl;
    cout << "You got x experience "  << "and " <<  "y gold!" << endl << endl;

  }
  else
    cout << "Returning to the forest" <<endl;
}

void World::createHero()
{
  string name;

  cout << "Welcome to the world, what should we call you?" << endl;
  cin >> name;
  cout << "Alright, " << name << " welcome to Gamed" << endl;
  c->setName(name);
  cout << endl;

}

