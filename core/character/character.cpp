/* Character - Players and Mobs in the game world */

#include <iostream>
#include <string>

#include "character.h"

Character::Character() {
    ID = 0;
    Name = "";
    Atk = 0;
    Def = 0;
    Hp = 0;
}

int Character::getID(){
    return ID;
}

void Character::setID(int x){
    ID = x;
}
void Character::generateID(int x){
    x = x+1;
    ID = x;
}

string Character::getName(){
    return Name;
}

void Character::setName(string name){
    Name = name;
}

int Character::getAtk(){
    return Atk;
}

void Character::setAtk(int x){
    Atk = x;
}

int Character::getDef(){
    return Def;
}

void Character::setDef(int x){
    Def = x;
}

int Character::getHp(){
    return Hp;
}

void Character::setHp(int x){
    Hp = x;
}

int Character::getmaxHp(){
    return maxHp;
}

void Character::setmaxHp(int x){
    maxHp = x;
}

int Character::getExp(){
    return Exp;
}

void Character::setExp(int x){
    Exp = x;
}

int Character::getLevel(){
    return Level;
}

void Character::setLevel(int x){
    Level = x;
}

