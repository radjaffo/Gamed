/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

#include "world.h"
#include "character/character.h"
#include "character/player.h"
#include "character/monster.h"

using namespace std;

World::World()
{       
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
 //weaponList(); //load file tester
 createHero();
 cout << "You walk into the dark forest, a few paths lay before you. What do you do?" << endl << endl;
 
 do
 {
  cout << endl << endl << c->getName() << " : " << c->getHp() << endl << endl;
  cout << "1. Search" << endl << "2. Town" << endl << "3. Quit" << endl;
  cin >> choice;
  if(c->getHp() <= 0)
    mc = 2;

  if(choice == "1" || choice == "search")
  {
    randomMoveBoth();
  }

  else if (choice == "2" || choice == "town")
  {
    cout << endl <<"Returning to town" << endl << endl << endl;
    town();
  }

  else if (choice == "3" || choice == "quit")
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
  string enter;

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
    if(choice == "1" || choice == "attack")
    {
      int b = rand()%100+1;
      cout << endl << "Player attacks the moonstar" << endl << endl << endl;
      c->attack(m);
      m->retaliate(c);
    }

    else if(choice == "2" || choice == "defend")
    {
      cout << endl <<"Defending!" << endl << endl << endl;
      int x = c->getDef();
      x= x*2;
      c->setDef(x);
      m->retaliate(c);
      x=x/2;
      c->setDef(x);
    }

    else if(choice == "3" || choice == "run")
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
    cout << "You got " << m->getExp() << " experience "  << "and " <<  m->getGold() << " gold!" << endl << endl;
    cin >> enter;
    int mExp = m->getExp();        //can make functions but temp vars work for now
    int pExp = c->getExp();
    int pGold = c->getGold();
    int mGold = m->getGold();
    b = b+a;
    d = d+e;
    c->setExp(b);
    c->setGold(d);
    cout << "Total Exp: " << c->getExp() << endl;
    cout << "Total Gold: " << c->getGold() << endl;
    //c->checkLevelUp();
    m->setHp(25);
  }
  else
    cout << "Returning to the forest" <<endl;
}

void World::createHero()
{
  string name, statAdjuster;

  cout << string(25, '\n');
  cout <<"Welcome to the world, what should we call you?" << endl;
  cin >> name;
  cout << "Alright, " << name << " welcome to Gamed" << endl << endl;
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
  char enter;
  cout << "Press a then enter to read more"; //gotta find a better way to do this
  cin >> enter;
  cin.ignore();
  cout << endl << endl <<"You wake up after a hefty night of ... completely confused with an empty stomachache..." << endl;
  cin >> enter;  //nope
  cout << "No time to think... Above you stands a lone goblin with brandishing a leg of lamb!" << endl;
  cin >> enter;
  cout << "You pick up a nearby stick and charge the goblin!" << endl;
  cin >> enter;

  cout << string(25, '\n');
  cout << "                         ROUND 1... FIGHT"  << endl << endl << endl <<endl << endl << endl << endl << endl;
  cin >> enter;
  cout << string(25, '\n');
f->setName("Garthan");
f->setAtk(9);
f->setDef(3);
f->setExp(100);
f->setGold(50);
fight(f);
cout << "You grab the leg of lamb from the defeated goblin and devour it bone and all!!!" << endl << endl;
cin >> enter;
cout << "Exhausted ... you stumble through the dense forest" << endl << endl;
cin >> enter;
cout << "After what seems like hours you finally see a light shining through the darkness" << endl << endl;
cin >> enter;
cout << "Bloody and Bruised, you collapse upon entering the town. The last thing you hear are the ravens cawing" << endl << endl;
cin >> enter;
cout << string(15, '\n');
cout << endl << endl << endl << endl <<  "Darkness.." << endl << endl << endl << endl;  //insert birds ascii
cin >> enter;
cout << string(15, '\n');
cout << "You wake up in a soft bed of hay" << string(5,'\n');
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
cout << "Harvey stumbles away" << endl<<endl;
cin >> enter;
town();
}

void World::displayCharBox(Monster *m)
{
  cout << endl << endl;
  cout << " ______________________________________________________________" << endl;
  cout << "| Hero   Lv:" << c->getLevel() << "                     Enemy                        |" << endl;
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
  if(cc < 25)
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
  cout << "1. Forest" << endl;
  cout << "2. Inn" << endl;
  cout << "3. Gear vendor" << endl;
  cout << "4. Item shop" << endl << endl;
  cout <<"Choose where to go..." << endl;
  cin >> tChoice;
    if(tChoice == "1" || tChoice == "forest")
    {
      cc = 2;
      cout << "Entering the forest!" << endl << endl;
    }
    else if(tChoice == "2" || tChoice == "inn")
    {
      cout << "Heading to the Inn" << endl << endl;
      inn();
    }
    else if(tChoice == "3" || tChoice == "gear")
    {
      cout << "You enter the weapons shop" << endl;
      weaponShop();
    }
    else if(tChoice == "4" || tChoice == "item")
    {
      cout << "You enter the items shop!" << endl << endl;
      itemShop();
    }
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
  cout <<"2. Save" << endl;
  cout <<"3. Town" << endl;
  cin >> iChoice;
  if(iChoice == "1" || iChoice == "rest")
    {
    cout << "Hp restored!" << endl << endl << endl;
    int x = c->getmaxHp();
    c->setHp(x);
    }
  else if(iChoice == "2" || iChoice == "save")
  {
    cout << "Sorry, not implemented yet :(";
  }
  else if(iChoice == "3" || iChoice == "town")
    {
    cout << "Returning to town!" << endl << endl;
    ic = 2;
    }
  else
    cout << "Nope, try again" << endl;
  }while(ic == 1);
}

void World::weaponShop()
{
  int ic = 1;
  int wC;
  do
  {
    string wChoice;
    cout << string(6, '\n');
    cout << "The Armory" << endl << endl << endl;
    cout <<"1. Weapons List" << endl;
    cout <<"2. Armor List" << endl;
    cout <<"3. Town" << endl;
    cin >> wChoice;
    if(wChoice == "1" || wChoice == "weapons")
    {
      cout << endl << "Weapons" << endl;
      weaponList();
      cout << "What would you like to buy?" << endl;
      cin >> wC;
      weaponList(wC);
    }
    else if (wChoice == "2" || wChoice == "armor")
    {
      cout << "Sorry, not implemented yet :(" << endl;
    }
    else if (wChoice == "3" || wChoice == "town")
    {
      cout << "Returning to town!" << endl << endl;
      ic = 3;
    }
    else
      cout << "Nope, try again" << endl;
  }while(ic == 1);
}


void World::itemShop()
{
  int ic = 1;
  do
  {
    string iChoice;
    cout << string(6, '\n');
    cout << "Le Potionz" << endl << endl << endl;
    cout << "1. Item List" << endl;
    cout << "2. Town" << endl;
    cin >> iChoice;
    if(iChoice == "1" || iChoice == "item")
    {
      cout << "Items" << endl;
      itemList();
    }
    else if(iChoice == "2" || iChoice == "town")
    {
      cout << "Returning to town!" << endl << endl;
      ic = 3;
    }
    else
      cout <<"Nope, try again" << endl;
  }while(ic == 1);
}

void World::weaponList()
{
  string weps;
  int wID[9];
  int wAtk;
  int wGold;
  char spacer;
  int i = 0;

  cout << string(6, '\n');
  cout << "You are fighting with a " << c->getwName() << "!" << endl << endl;

  ifstream inFile;
  inFile.open("core/databank/weapons.txt");
  //system("pwd");  test to see what root folder is
  if(inFile.is_open())
  {
    cout << "  " << "Name   " << '\t' << "Atk" << '\t' << "Gold" << endl;
    while(i<10)
    {
      for(i=0; i < 10; i++)
      {
      inFile >> wID[i] >> weps >> wAtk >> wGold;
      cout << wID[i] << " " << weps  << '\t' << wAtk << '\t' << wGold << endl;
      }
    }
  inFile.close();
  }

  else 
    cout << "Unable to open file";

}

void World::weaponList(int x)
{
  string weps;
  int wID[9];
  int wAtk;
  int wGold;
  char spacer;
  int i = 0;

  ifstream inFile;
  inFile.open("core/databank/weapons.txt");
  //system("pwd");  test to see what root folder is
  if(inFile.is_open())
  {
    while(i<10)
    {
      for(i=0; i < 10; i++)
      {
      inFile >> wID[i] >> weps >> wAtk >> wGold;
        if(x == wID[i])
        {
          int reqGold = wGold;
           if(goldCheck(reqGold) == true)
              cout << "Lets buy it!";
           else
              cout <<"Error! Not enough gold";
        }
      }
    }
  inFile.close();
  }
  else
    cout << "Error! Unable to open file" << endl;
}

void World::itemList()
{
  string items;

  ifstream inFile;
  inFile.open("core/databank/itemlist.txt");
  if(inFile.is_open())
  {
    while(getline(inFile,items))
    {
      cout << items << '\n';
    }
  inFile.close();
  }
  
  else
    cout << "Error! Unable to open file" << endl;
}

bool World::goldCheck(int x)
{
  if(c->getGold() >= x)
    return true;
  else
  return false;
}
