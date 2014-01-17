/* Character - Players and Mobs in the game world */
#include <iostream>
#include <string>

#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;


class Character {
protected:
    //hero variables
    int ID;
    string Name;
    int Atk;
    int Def;
    int Hp;
    int maxHp;
    int Exp;
    int Level;
    //Weapon variables
    int wID;
    string wName;



public:
    Character();
    //~Character();

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

    int getmaxHp();
    void setmaxHp(int x);

    int getExp();
    void setExp(int x);

    int getLevel();
    void setLevel(int x);

    string getwName();
    void setwName(string wname);

    int getwID();
    void setwID(int x);
    
};

#endif
