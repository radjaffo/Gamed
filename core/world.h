/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#ifndef WORLD_H
#define WORLD_H

using namespace std;

class Player;
class Monster;



class World {
    private:
        string Hero;
        string Mob;
        string Map[5][5];
        Player *c;
        Monster *d;
        Monster *f;

    public:
        World();                // Constructor - Create new World
        //~World();               // Destructor - Destroy World

        //Main Game function
        void looper();             

        // Setup Map
        bool createMap();
        void clearMap();
        void displayMap();
        void placeCharacters();
        string getHero();
        string getMob();
        void characterMove(Player *c, Monster *m);
        bool illegalMove(Player *c, string name);
        void randomMoveBoth();
        
        //Intro functions

        void displayBird();
        void createHero();
        void firstFight();         
        void displayCharBox(Monster *m); //displays fight menu
        void displayHps(Monster *m);
        void playerStats(Player *c);
        void loadHero(string name);
        void itemList(Player *c);

        //Town functions
        void town();
        void inn();
        void weaponShop();
        void itemShop();
        void weaponList();
        void weaponList(int x);
        void itemList();
        bool goldCheck(int x);
        void armorList();
        void armorList(int x);
        void saveHero(Player *c);

        //Forest functions
        void fight(Monster *m);  
        void loadMonster(int x);
        bool checkLevelUp(Player *c);
        void levelUp(Player *c, int x);




        /* Future

        // Game Loop Definitions

        int calculateChanges();   // Calculate differences in
        void display();           // Display changes to player
        void input();             // Collect player input
        */
};
#endif