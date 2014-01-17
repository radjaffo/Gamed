/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#ifndef WORLD_H
#define WORLD_H

using namespace std;

class Player;
class Monster;
class Weapon;


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
        void displayMap();
        void placeCharacters();
        void createHero();
        string getHero();
        string getMob();

        void randomMoveBoth();
        

        
        void fight(Monster *m);          

        //Intro functions
        void firstFight();         
        void displayCharBox(Monster *m); //displays fight menu
        void displayHps(Monster *m);

        //Town functions
        void town();
        void inn();
        void weaponShop();
        void itemShop();
        void weaponList();
        void itemList();
        /* Future

        // Game Loop Definitions

        int calculateChanges();   // Calculate differences in
        void display();           // Display changes to player
        void input();             // Collect player input
        */
};
#endif