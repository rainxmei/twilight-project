#include "weapon.h"
#include <iostream>
#include <string>

using namespace std;

Weapon::Weapon(const char* name, double attackPower){
    this->name = name;
    this->attackPower = attackPower;
}

void Weapon::display(){
    cout << "Weapon ini adalah "<< this->name << " power = ";
    cout << this->attackPower << endl;
}

string Weapon::getName(){
    return this->name;
}