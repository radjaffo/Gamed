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


bool World::createMap()
{
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

void World::clearMap()    //temporary measure
{
  for(int i = 0; i < 5; i++){
    for(int j=0; j < 5; j++){
      Map[i][j] = '_';      
    }
  }
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


  clearMap();

  int x = rand()%5;
  srand(time(NULL)%50);
  int y = rand()%5;

  //cout << "[" << x << "," << y << "]" << endl;
  Map[x][y] = Hero;
  srand(time(NULL)%50);
  int a = rand()%5;
  srand(time(NULL)%10);
  int b = rand()%5;
  Map[a][b] = Mob;
  //cout << "[" << a << "," << b << "]" << endl;

  if (Map[x][y] == Map[a][b])
  {
    
    cout << "Monster encountered!! Time to fight!" << endl;
    if(c->getLevel() < 2)
    int g = rand()%4;
    else
    int g = rand()%8;
    loadMonster(a);
    fight(d);
  }
}

void World::characterMove(Player *c)
{
  string mChoice;
  int mCounter = 1;
  int cC, x, y;
  int charMover;
  cout << "Where would you like to move?" << endl << "east, west, north, or south?" << endl;
  do
  {
    cin >> mChoice;
    if(mChoice == "east" || mChoice == "e")
    {
      mChoice = "e";
      charMover = 1;
      //illegalMove(east)
    }
    else if(mChoice == "west" || mChoice == "w")
    {
      mChoice = "w";
      charMover = -1;
      //illegalMove(west)
    }
    else if(mChoice == "south" || mChoice == "s")
    {
      mChoice = "s";
      charMover = 1;
      //illegalMove(south)
    }
    else if(mChoice == "north" || mChoice == "n")
    {
      mChoice = "n";
      charMover = -1;
      //illegalMove(north)
    }
    else
      cout <<"Error incorrect entry, please try again" << endl;


      for(int i=0; i < 5; i++) 
      {
        for(int j=0; j< 5; j++)
        {
          if(Map[i][j] == Hero)
          {
            x = i;
            y = j;
          }   
        }
      }
  Map[x][y] = "_";
  cout << "mChoice is " << mChoice << endl;  testing purposes
    if(mChoice == "e" || mChoice == "w")
    {
      y = y+charMover;
      cout <<"Moving y to " << x << endl;
    }
    else
    {
      x = x+charMover;
      cout <<"Moving x to " << y << endl;
    }
    Map[x][y] = Hero;
  displayMap();
  }while(mCounter == 1);
}

/*bool World::illegalMove(Player *c, string name)
{

}
*/

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
 srand(time(NULL));
 displayMap();
 characterMove(c);

 //cout << "You walk into the dark forest, a few paths lay before you. What do you do?" << endl << endl;
 
 do
 {
   if(c->getHp() <= 0)
    {
      mc = 2;
      break;
    }
  cout << endl << endl << c->getName() << " : " << c->getHp() << endl << endl;
  cout << "1. Search" << endl << "2. Town" << endl << "3. Stats" << endl << "4. Quit"<< endl;
  cin >> choice;
 

  if(choice == "1" || choice == "search")
  {
    randomMoveBoth();
  }

  else if (choice == "2" || choice == "town")
  {
    cout << endl <<"Returning to town" << endl << endl << endl;
    town();
  }

  else if(choice == "3" || choice == "stats")
    {
    cout << string(15, '\n');
    playerStats(c);
    }

  else if (choice == "4" || choice == "quit")
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
    pExp = pExp+mExp;
    pGold = pGold+mGold;
    c->setExp(pExp);
    c->setGold(pGold);
    cout << "Total Exp: " << c->getExp() << endl;
    cout << "Total Gold: " << c->getGold() << endl << endl;
    //checkLevelUp(c);
    if(checkLevelUp(c) == true)
    {
      int cLvl = c->getLevel();
      levelUp(c, cLvl);
    }
    m->setHp(25);
  }
  else
    cout << "Returning to the forest" <<endl;
}

void World::createHero()
{
  string name, statAdjuster, vet;
  cout << string(25, '\n');
  displayBird();  
  cout << endl << endl;
  cout <<"Welcome to the world, what should we call you?" << endl;
  cin >> name;
  c->setName(name);
  cout << "Alright, " << name << " welcome to Gamed" << endl << endl;
  cout << "Are you new to Gamed? (type no to load)" << endl;
  cin >> vet;
  if(vet == "no")
    {
    loadHero(name);
    cout << "You wake up in a field next to town feeling refreshed, welcome back " << c->getName();
    int tempHP = c->getmaxHp();
    c->setHp(tempHP);
    return;
    }
  else
  {
    cout << endl;
    cout << "You have 3 stat points to spend, choose wisely" << endl << endl;
    int stats = 3;
      do
      {
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
f->setExp(50);
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
  cout << "4. Item shop" << endl;
  cout << "5. Stats" << endl;
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
      cout << "You enter the items shop!" << endl;
      itemShop();
    }
    else if(tChoice == "5" || tChoice == "stats")
    {
    cout << string(15, '\n');
    playerStats(c);
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
    saveHero(c);
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
      int wC;
      cout << endl << "Weapons" << endl;
      weaponList();
      cout << "What would you like to buy?" << endl;
      cin >> wC;
      weaponList(wC);
    }
    else if (wChoice == "2" || wChoice == "armor")
    {
      int aC;
      cout << endl << "Armor" << endl;
      armorList();
      cout << "What would you like to buy?" << endl;
      cin >> aC;
      armorList(aC);
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
  int i = 0;

  cout << string(7, '\n');
  cout << "You are fighting with a " << c->getwName() << "!" << endl;
  cout << "Gold: " << c->getGold() << endl << endl;
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
  string wchoice;

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
          int wepValue = c->getwGold();
          int reqGold = wGold - wepValue;
           if(goldCheck(reqGold) == true)
              {
              cout << "Vendor" << endl;
              cout << "Are you sure you want to buy a " << weps << "?" << endl <<"Only weirdos buy those... the vendor mutters to himself" << endl << endl;
              cout <<"Press 1 to buy, 2 if you dont want that thing afterall" << endl;
              cin >> wchoice;
                if(wchoice == "1")
                {
                  cout << "Alright, selling your " << c->getwName() << " for " << c->getwGold() << " gold " << endl << endl;
                  cout << "Vendor" << endl;
                  cout << "Now gimme " << wGold << " gold for this awesome looking " << weps  << "!" << endl;
                  int newGold = c->getGold() - reqGold;
                  c->setGold(newGold);
                  c->setwName(weps);
                  c->setwAtk(wAtk);
                  cout << "Changing gear..." << endl;
                  cin >> spacer;
                  cout << "You swing your new " << c->getwName() << " a few times, it feels like a perfect fit for you!" << endl << endl;
                }
                else
                  {
                  cout << endl << "Vendor" << endl;
                  cout << "Not buying? Then get out!" << endl;
                  cout << "Returning to town" << endl;
                  }
              }
           else
              cout <<"Error! Not enough gold" << endl;
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

void World::playerStats(Player *c)
{
  int i = c->getAtk();
  int x = c->getwAtk();
  i = x+i;
  int j = c->getDef();
  int k = c->getaDef();
  j = j+k;
  cout << endl << endl;
  cout << " Stats" << endl;
  cout << " Hero   Lv:" << c->getLevel() << endl;
  cout << " " << c->getName()<< endl;
  cout << " Hp: " << c->getHp() << "/" << c->getmaxHp() << endl;
  cout << " Weapon: " << c->getwName() << endl;
  cout << " Armor: " << c->getaName() << endl;
  cout << " Atk: " << i << endl;
  cout << " Def: " << j << endl;
  cout << " Gold: " << c->getGold() << endl;
  cout << " Exp: " << c->getExp() << endl;
}

void World::displayBird()
{
  string bird;

  ifstream inFile;
  inFile.open("assets/birds.txt");
  if(inFile.is_open())
  {
    while(getline(inFile,bird))
    {
      cout << bird << '\n';
    }
  inFile.close();
  }
  
  else
    cout << "Error! Unable to open file" << endl;

}


void World::armorList()
{
  string armor;
  ifstream inFile;

  cout << string(7, '\n');
  cout << "You are wearing: " << c->getaName() << endl;
  cout << "Gold: " << c->getGold() << endl;
  cout << "  " << "Name   " << '\t' << "Def" << '\t' << "Gold" << endl;
  inFile.open("core/databank/armor.txt");
  if(inFile.is_open())
  {
    while(getline(inFile,armor))
    {
      cout << armor << '\n';
    }
  inFile.close();
  }

  else
    cout << "Error! Unable to open file" << endl;
}

void World::armorList(int x)
{
  string armor;
  int aID[5];
  int aDef;
  int aGold;
  string aChoice;
  char spacer;
  ifstream inFile;

  inFile.open("core/databank/armor.txt");
  if(inFile.is_open())
  {
    for(int i = 0; i < 6; i++)
    {
      inFile >> aID[i] >> armor >> aDef >> aGold;
      if (x == aID[i])
      {
        int armorValue = c->getaGold();
        int reqGold = aGold - armorValue;
        if(goldCheck(reqGold) == true)
        {
          cout << "Vendor" << endl;
          cout << "Theres no way you want this raggedy old " << armor << " is there?" << endl;
          cout <<"Press 1 to buy, 2 if you dont want that thing afterall" << endl;
          cin >> aChoice;
            if(aChoice == "1")
            {
              cout << "Alright, selling your " << c->getaName() << " for " << c->getaGold() << " gold " << endl << endl;
              cout << "Vendor" << endl;
              cout << "Now gimme " << aGold << " gold for this terrible looking " << armor  << "!" << endl;
              int newGold = c->getGold() - reqGold;
              c->setGold(newGold);
              c->setaName(armor);
              c->setaDef(aDef);
              cout << "Changing gear..." << endl;
              cin >> spacer;
              cout << "You don your new " << armor << " and dust off the cobwebs" << endl;
              cout << "The armor is a little large but it'll do!" << endl;
            }
            else
              { 
              cout << endl << "Vendor" << endl;
              cout << "Not buying? Then get out!" << endl;
              cout << "Returning to town" << endl;
              }
        }
        else
          cout << "Error! Not enough gold" << endl;
      }
    }
  inFile.close();
  }
  else
  cout << "Error! Unable to open file" << endl;

}

void World::saveHero(Player *c)
{
  string saver = c->getName();
  string txt = ".txt";
  saver = saver + txt;
  string name = c->getName();
  int atk = c->getAtk();
  int def = c->getDef();
  int hp = c->getHp();
  int maxhp = c->getmaxHp();
  int experience = c->getExp();
  int level = c->getLevel();
  int nextlevel = c->getNextLevel();
  int gold = c->getGold();
  string wname = c->getwName();
  int watk = c->getwAtk();
  int wgold = c->getwGold();
  string aname = c->getaName();
  int adef = c->getaDef();
  int agold = c->getaGold();


  ofstream outFile;
  outFile.open (saver.c_str());
  outFile << name << endl << atk  << endl << hp  << endl << maxhp << endl;
  outFile << experience << endl << level << endl << nextlevel << endl << gold << endl;
  outFile << wname << endl << watk << endl << wgold << endl << aname << endl << adef << endl << agold << endl;
  cout << "Saving your hero!" << endl;
  //cout << saver;
  outFile.close();
}

void World::loadHero(string name)
{
  c->setName(name);
  string saver= c->getName();
  string txt = ".txt";
  saver = saver + txt;
  string nline;
  int atk;
  int def;
  int hp;
  int maxhp;
  int experience;
  int level;
  int nextlevel;
  int gold;
  string wname;
  int watk;
  int wgold;
  string aname;
  int adef;
  int agold;

  cout << "Loading " << name << endl;
  ifstream inFile;
  inFile.open(saver.c_str());
  inFile >> name >> atk >> hp >> maxhp >> experience >> level >> nextlevel >> gold >> wname;
  inFile >> watk >> wgold >> aname >> adef >> agold;
  c->setAtk(atk);
  c->setHp(hp);
  c->setmaxHp(maxhp);
  c->setExp(experience);
  c->setLevel(level);
  c->setNextLevel(nextlevel);
  c->setGold(gold);
  c->setwName(wname);
  c->setwAtk(watk);
  c->setwGold(wgold);
  c->setaName(aname);
  c->setaDef(adef);
  c->setaGold(agold);
  inFile.close();
}

void World::loadMonster(int x)
{
  int mID[13];
  string name;
  int atk;
  int def;
  int hp;
  int experience;
  int gold;

  ifstream inFile;
  inFile.open("core/databank/monsters.txt");

  if(inFile.is_open())
  {
    for(int i=0; i < 13; i++)
    {
      inFile >> mID[i] >> name >> atk >> def >> hp >> gold >> experience;
      if(x == mID[i])
      {
        cout << "A hungry lookin " << name << " charges you!" << endl;
        cout << x << endl;
        d->setName(name);
        d->setAtk(atk);
        d->setDef(def);
        d->setHp(hp);
        d->setGold(gold);
        d->setExp(experience);
      }
    }
  inFile.close();
  }
  else
    cout <<"Error opening file" << endl;
}

bool World::checkLevelUp(Player *c)
{
  if (c->getExp() >= c->getNextLevel())
    {
      cout << "Level Up!!" << endl;
       //play moozak
      return true;
    }
  return false;
}

void World::levelUp(Player *c, int x)
{
  int lID[9];   //do i even need an array here?
  x++;
  int current, next, atk, def, hp, cAtk, cDef, cMaxHP;
  ifstream inFile;
  inFile.open("core/databank/experience.txt");
  if(inFile.is_open())
  {
    for(int i=0; i < 10; i++)
    {
      inFile >> lID[i] >> current >> next >> atk >> def >> hp;
      if(x == lID[i])
      {
        c->setLevel(x);
        cout << "Level is now " << x << endl;
        c->setNextLevel(next);
        cAtk = c->getAtk();
        cDef = c->getDef();
        cout << "Attack raised by " << cAtk << endl << "Defense raised by " << cDef << endl << "HP raised by " << hp << endl;
        cout << "Experience to next level is " << next << endl;
        cMaxHP = c->getmaxHp();
        cAtk = cAtk + atk;
        c->setAtk(cAtk);
        cDef = cDef + def;
        c->setDef(cDef);
        cMaxHP = cMaxHP + hp;
        c->setmaxHp(cMaxHP);
        return;
       }
    }
  }
  else cout <<"Error opening file" << endl;
}


