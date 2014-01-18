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
    int nextLevel;
    int Gold;
    //Weapon variables
    int wID;
    string wName;
    int wAtk;
    int wGold;
    //Armor variables
    int aID;
    string aName;
    int aDef;
    int aGold;



public:
    Character();
    //~Character();

    //Hero functions
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

    int getnextLevel();
    void setnextLevel(int x);

    int getGold();
    void setGold(int x);

    //Weapon functions
    int getwID();
    void setwID(int x);

    string getwName();
    void setwName(string wname);

    int getwAtk();
    void setwAtk(int x);

    int getwGold();
    void setwGold(int x);

    //Armor functions
    int getaID();
    void setaID(int x);

    string getaName();
    void setaName(string name);

    int getaDef();
    void setaDef(int x);

    int getaGold();
    void setaGold(int x);
    

};

#endif
