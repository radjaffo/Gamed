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

        // Setup Map
        bool createMap();
        void displayMap();
        // Return player and mob positions
        void placeCharacters();
        void createHero();
        string getHero();
        string getMob();

        void randomMoveBoth();
        

        void fight(Monster *m);          
        void looper();             // Run game loop until quit

        void firstFight();
        void displayCharBox(Monster *m);
        void displayHps(Monster *m);


        void town();
        void inn();
        void weaponShop();
        void itemShop();
        /* Future

        // Game Loop Definitions

        int calculateChanges();   // Calculate differences in
        void display();           // Display changes to player
        void input();             // Collect player input

        

        // Player Input
        void randomMoveBoth();  // Move Player and Mob randomly around board
        void resetPlayerPosition();
        */
};
#endif