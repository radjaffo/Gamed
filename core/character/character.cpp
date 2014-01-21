/* Character - Players and Mobs in the game world */

#include <iostream>
#include <string>

#include "character.h"

Character::Character() {
    ID = 0;
    Name = "";
    Atk = 0;
    Def = 0;
    maxHp = 0;
    Hp = 0;
    Exp = 0;
    Level = 0;
    nextLevel = 0;
    Gold = 0;
    wID = 0;
    wName = "";
    wAtk = 0;
    wGold = 0;
    aID = 0;
    aName = "";
    aDef = 0;
    aGold = 0;

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

int Character::getNextLevel(){
    return nextLevel;
}

void Character::setNextLevel(int x){
    nextLevel = x;
}

int Character::getGold(){
    return Gold;
}

void Character::setGold(int x){
    Gold = x;
}

string Character::getwName(){
    return wName;
}

void Character::setwName(string name){
    wName = name;
}

int Character::getwID(){
    return wID;
}

void Character::setwID(int x){
    wID = x;
}

int Character::getwAtk(){
    return wAtk;
}

void Character::setwAtk(int x){
    wAtk = x;
}

int Character::getwGold(){
    return wGold;
}

void Character::setwGold(int x){
    wGold = x;
}

int Character::getaID(){
    return aID;
}

void Character::setaID(int x){
    aID = x;
}

string Character::getaName(){
    return aName;
}

void Character::setaName(string name){
    aName = name;
}

int Character::getaDef(){
    return aDef;
}

void Character::setaDef(int x){
    aDef = x;
}

int Character::getaGold(){
    return aGold;
}

void Character::setaGold(int x){
    aGold = x;
}

