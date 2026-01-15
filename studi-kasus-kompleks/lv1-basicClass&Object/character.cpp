#include "character.h"
#include <iostream>

// constructor
Character::Character(const string& name) :
    name(name),
    level(1),
    hp(100),
    strength(10),
    agility(10),
    intelligence(10)
{
    cout << "Character Created!" << endl;
}

// methods
void Character::showStatus(){
    cout << "Name  : " << name << endl;
    cout << "Level : " << level << endl;
    cout << "Hp    : " << hp << endl;
    cout << "STR   : " << strength << endl;
    cout << "AGI   : " << agility << endl;
    cout << "INT   : " << intelligence << endl;
    cout << "\n";
}

void Character::levelUp(){
    level++;
    hp += 20;
    strength += 5;
    agility += 5;
    intelligence += 5;

    cout << "Level up!" << endl;
}

void Character::takeDamage(int damage){
    hp -= damage;
    if (hp < 0){
        hp = 0;
    }

    cout << this->name << " takes " << damage << " damage!" << endl;
}