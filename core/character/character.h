/* Character - Players and Mobs in the game world */
#include <iostream>
#include <string>


#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Player;
class Monster;

class Character {
    int ID;
    string Name;
    int Atk;
    int Def;
    int Hp;

public:
    Character();
    ~Character();

    int getID();
    void setID(int x);
    void generateID(int x);

    string getName();
    void setName(string name);

    int getAtk();
    void setAtk(int x);

    int getDef();
    void setDef(int x);

    int getHp();
    void setHp(int x);

};

#endif
