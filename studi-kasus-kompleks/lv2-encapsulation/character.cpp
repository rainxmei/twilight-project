#include "character.h"
#include <iostream>

// constructor
Character::Character(const string& name) :
    name(name),
    level(1),
    maxHp(100),
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
    cout << "Hp    : " << hp << " / " << maxHp << endl;
    cout << "STR   : " << strength << endl;
    cout << "AGI   : " << agility << endl;
    cout << "INT   : " << intelligence << endl;
    cout << "\n";
}

void Character::levelUp(){
    level++;
    maxHp += 20;
    strength += 5;
    agility += 5;
    intelligence += 5;
    hp = maxHp;

    cout << "Level up!" << endl;
}

void Character::takeDamage(int damage){
    hp -= damage;
    if (hp < 0){
        hp = 0;
        cout << "Character is dead\n" << endl;
    }

    if (hp > maxHp){
        hp = maxHp;
    }

    cout << name << " takes " << damage << " damage!" << endl;
    cout << "Current HP: " << hp << " / " << maxHp << endl;
    cout << "\n";
}

void Character::heal(int heal){
    hp += heal;
    cout << name << " heals " << heal << " HP!" << endl;
    cout << "Current HP: " << hp << " / " << maxHp << endl;
    cout << "\n";
}