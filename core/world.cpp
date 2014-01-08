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
  Hero = "H";           //strings for graphics
  Mob = "M";
  createMap();          //functions for graphics
  placeCharacters();
  c = new Player;       //hero setup
  f = new Monster;      //first fight
  d = new Monster;      //forest
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
   fight(d);
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
 createHero();
 do
 {
  cout << endl << endl << c->getName() << " : " << c->getHp() << endl << endl;
  cout << "1. Search" << endl << "2. Town" << endl << "3. Quit" << endl;
  cin >> choice;
  if(c->getHp() <= 0)
    mc = 2;
  if(choice == "search")
  {
    randomMoveBoth();
  }
  else if (choice == "town")
  {
    cout << endl <<"Returning to town" << endl << endl << endl;
    town();
  }
  else if (choice == "quit")
  {
    cout << endl << "Thanks for playing... Goodbye!" << endl << endl;
    mc = 2;
  }
 }
 while(mc == 1);
}

void World::fight(Monster *m)
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
    else if (m->getHp() <=0)
    {
      cc = 1;
      break;
    }
    else
    displayCharBox(m);
    //cout << endl << c->getName() << " : " << c->getHp() << endl << m->getName() << " : " << m->getHp() << endl<< endl;
    cout << "What would you like to do?" << endl;
    //cout << "1.attack" << endl << "2.run" << endl << "3.defend" << endl;
    cin >> choice;
    if(choice == "attack")
    {
      int b = rand()%100+1;
      cout << endl << "Player attacks the moonstar" << endl << endl << endl;
      c->attack(m);
      m->retaliate(c);
    }
    else if(choice == "run")
    {
      int b = rand()%100+1;
      cout << endl <<"Player runs like little girl" << endl << endl;
      
      if(m->getName() == "Garthan")
      {
        cout << "Nope, nope, nope, can't run from this one" << endl;
        m->retaliate(c);
      }
      else if(b > 40)
      {
      cc = 1;
      cout << "Success, you got away!" << endl;
      int x = m->getmaxHp();
      m->setHp(x);
      }
      else
      {
      cout << "Failed to run!" <<endl;
      m->retaliate(c);
      }
    }
    else if(choice == "defend")
    {
      cout << endl <<"Defending!" << endl << endl << endl;
      int x = c->getDef();
      x= x*2;
      c->setDef(x);
      m->retaliate(c);
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
  else if(m->getHp() <= 0)
  { 
    cout << "You win! " << m->getName() << " is defeated!" << endl;
    cout << "You got x experience "  << "and " <<  "y gold!" << endl << endl;
    m->setHp(25);
  }
  else
    cout << "Returning to the forest" <<endl;
}

void World::createHero()
{
  string name, statAdjuster;

  cout << "Welcome to the world, what should we call you?" << endl;
  cin >> name;
  cout << "Alright, " << name << " welcome to Gamed" << endl;
  c->setName(name);
  cout << endl;
  cout << "You have 3 stat points to spend, choose wisely" << endl << endl;
  int stats = 3;
  do{
  cout << c->getName() << endl << "Atk : " << c->getAtk() << endl << "Def : " << c->getDef() << endl;
  cout << "Hp : " << c->getHp() << endl;
  cout << "atk = atk, def = def, hp = hp" << endl << endl;
  cout << "Put 1 stat point into... " << endl;
  cin >> statAdjuster;
  if(statAdjuster == "atk")
    {
      int x = c->getAtk();
      x++;
      c->setAtk(x);
      cout << endl << "Atk raised by 1!" << endl << endl;
      stats--;
    }
  else if (statAdjuster == "def")
  {
    int x = c->getDef();
    x++;
    c->setDef(x);
    cout << endl << "Def raised by 1!" << endl << endl;
    stats--;
  }
  else if (statAdjuster == "hp")
  {
    int x = c->getHp();
    x++;
    c->setHp(x);
    cout << endl << "Hp raised by 1!" << endl << endl;
    stats--;
  }
  else 
    cout << endl << "Error! Incorrect entry, please try again" << endl << endl;
} while (stats > 0);
firstFight();
}

void World::firstFight()
{
  cout << "a then enter through pauses"; //gotta find a better way to do this
  string enter;
  cout << endl << endl <<"You wake up after a hefty night of ... completely confused with an empty stomachache..." << endl;
  enter = cin.get();  //nope
  cout << "No time to think... Above you stands a lone goblin with brandishing a leg of lamb!" << endl;
  cin >> enter;
  cout << "You pick up a nearby bone and charge the goblin!" << endl;
  cin >> enter;

  cout << string(25, '\n');
  cout << "                         ROUND 1... FIGHT"  << endl << endl << endl <<endl << endl << endl << endl << endl;
  cin >> enter;
  cout << string(25, '\n');
f->setName("Garthan");
f->setAtk(9);
f->setDef(3);
fight(f);
cout << "You grab the leg of lamb from the defeated goblin and devour it bone and all!!!" << endl << endl;
cin >> enter;
cout << "Exhausted ... you stumble through the dense forest" << endl << endl;
cin >> enter;
cout << "After what seems like hours you finally see a light shining through the darkness" << endl << endl;
cin >> enter;
cout << "Bloody and Bruised, you collapse upon entering the town. The last thing you hear are the ravens cawing" << endl << endl;
cin >> enter;
cout << string(12, '\n');
cout << endl << endl << endl << endl <<  "Darkness.." << endl << endl << endl << endl;  //insert birds ascii
cin >> enter;
cout << "You wake up in a soft bed of hay" << endl << endl;
c->setHp(20);
cout << "????:" << endl;
cout << "Awake are we? Ye stumbled in here lookin foul and just fell over..." << endl;
cin >> enter;
cout << "Harvey:" << endl;
cout << "Anyways me names Harvey and I own the inn over yonder" << endl;
cout << "Harvey points to a nearby building" << endl << endl;
cin >> enter;
cout << "Harvey:" << endl;
cout << "If ye ever needs to rest comon over, theres always a warm bed open" << endl;
cout << "Harvey stumbles away" << endl;
cin >> enter;
town();
}

void World::displayCharBox(Monster *m)
{
  cout << endl << endl;
  cout << " ______________________________________________________________" << endl;
  cout << "| Hero                            Enemy                        |" << endl;
  cout << "| " << c->getName() << "                           " << m->getName() << "                      |" << endl;
  displayHps(m);
  cout << "|                                                              |" << endl;
  cout << "|     1. attack                          2. defend             |" << endl;
  cout << "|     3. run                             4. ....?              |" << endl;
  cout << "|______________________________________________________________|" << endl << endl << endl << endl;

}

void World::displayHps(Monster *m)
{
  int cc = 5;
  int sc = 0;
  int x = c->getHp();
  int y = m->getHp();
  cout << "| Hp:";
  for(int i=0; i < x; i++)  //enhance this... if x > 20 ||y > 25 it wont work
  {
      cout << "/";
      cc++;
  }
  if(cc <25)
  {
    for(sc = 25; sc > cc; sc--)
      cout << " ";
  }
  cc = 37;
  sc = 62;
  cout << "         Hp:";
  for(int j=0; j < y; j++)
  {
    cout << "/";
    cc++;
  } 
  if(cc < 62)
  for(sc = 62; sc > cc; sc--)
      cout << " ";
  cout << " |" << endl;
}

void World::town()
{
  string tChoice;
  int cc = 1;
  do
  {
  cout << endl << endl << "Town" << endl << endl << endl;
  cout << "1.forest" << endl;
  cout << "2.inn" << endl;
  //cout << "3.Weapon shop" << endl;
  //cout << "4.Item shop" << endl << endl;
  cout <<"Choose where to go..." << endl;
    cin >> tChoice;
    if(tChoice == "forest")
    {
      cc = 2;
      cout << "Entering the forest!" << endl << endl;
    }
    else if(tChoice == "inn")
    {
      cout << "Heading to the Inn" << endl << endl;
      inn();
    }
    //else if(tChoice == "weapon")
    else
      cout <<"Nope, try again" << endl;

  }while(cc==1);

}

void World::inn()
{
  int ic = 1;
  do
  {
  cout << endl << endl << endl << endl << endl;
  string iChoice;
  cout <<"The Birdbath" << endl << endl;
  cout <<"1. Rest (recover Hp)" << endl;
  //cout <<"2. Save" << endl;
  cout <<"3. Town" << endl;
  cin >> iChoice;
  if(iChoice == "rest")
    {
    cout << "Hp restored!" << endl << endl << endl;
    int x = c->getmaxHp();
    c->setHp(x);
    }
  else if(iChoice == "town")
    {
    cout << "Returning to town!" << endl << endl;
    break;
    }
  else
    cout << "Nope, try again" << endl;
  }while(ic == 1);
}





