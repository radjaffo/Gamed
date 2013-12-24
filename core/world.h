#include <iostream>
#include <string>
#ifndef WORLD_H
#define WORLD_H

using namespace std;

Class World()
{
    string Hero;
    string Mob;

    public:
    World();
    int calc();
    void display();
    void move();
    void run();
    void looper();

    void getHero();
    string setHero();
    void getMob();
    string setMob();

};
#endif