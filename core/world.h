/* World - Creates and maintains the game world where players/mobs inhabit */

#include <iostream>
#include <string>
#ifndef WORLD_H
#define WORLD_H

using namespace std;

class World {
    private:
        string Hero;
        string Mob;

    public:
        World();                // Constructur - Create new World
        ~World();               // Destructor - Destroy World

        // Return player and mob positions
        string getHero();
        string getMob();

        /* Future 

        // Game Loop Initi
        void looper();          // Run game loop until quit

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