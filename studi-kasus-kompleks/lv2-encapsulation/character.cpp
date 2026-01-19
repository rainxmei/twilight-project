#include "character.h"
#include <iostream>
#include <stdexcept>

// constructor
Character::Character(const std::string& name) :
    name(name),
    level(1),
    maxHp(100),
    hp(100),
    strength(10),
    agility(10),
    intelligence(10)
{
    std::cout << "Character Created!" << std::endl;
}

// getter
std::string Character::getName() const {
    return this->name;
}

int Character::getHp() const{
    return this->hp;
}

int Character::getMaxHp() const{
    return this->maxHp;
}

int Character::getLevel() const{
    return this->level;
}

// methods
void Character::showStatus() const{
    std::cout << "Name  : " << name << std::endl;
    std::cout << "Level : " << level << std::endl;
    std::cout << "Hp    : " << hp << " / " << maxHp << std::endl;
    std::cout << "STR   : " << strength << std::endl;
    std::cout << "AGI   : " << agility << std::endl;
    std::cout << "INT   : " << intelligence << std::endl;
    std::cout << "\n";
}

void Character::levelUp(){
    level++;
    maxHp += 20;
    strength += 5;
    agility += 5;
    intelligence += 5;
    hp = maxHp;

    std::cout << "Level up!" << std::endl;
}

bool Character::isAlive() const {
    return hp > 0;
}

void Character::takeDamage(int damage){
    if (damage <= 0) return;
    
    hp -= damage;
    if (hp < 0) hp = 0;

    std::cout << name << " takes " << damage << " damage!" << std::endl;

    if (!isAlive()) {
        std::cout << "Character is dead\n" << std::endl;
    }

    std::cout << "Current HP: " << hp << " / " << maxHp << std::endl;
    std::cout << "\n";
}

void Character::heal(int heal){
    if (heal <= 0 || !isAlive()) return;
    hp += heal;
    if (hp > maxHp){
        hp = maxHp;
    }
    std::cout << name << " heals " << heal << " HP!" << std::endl;
    std::cout << "Current HP: " << hp << " / " << maxHp << std::endl;
    std::cout << "\n";
}