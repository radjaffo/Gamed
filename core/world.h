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
        string Map[5][5];

    public:
        World();                // Constructur - Create new World
        ~World();               // Destructor - Destroy World

        // Setup Map
        bool createMap();
        void displayMap();
        // Return player and mob positions
        void placeCharacters();
        string getHero();
        string getMob();

        void randomMoveBoth();
        

        void fight();          // Run game loop until quit
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