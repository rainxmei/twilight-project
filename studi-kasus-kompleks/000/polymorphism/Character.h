#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int hp;
    int strength;

public:
    Character(const std::string& name, int hp, int strength)
        : name(name), hp(hp), strength(strength) {}

    virtual void attack(Character& target) = 0;

    virtual void takeDamage(int damage) {
        hp -= damage;
        if (hp < 0) hp = 0;
    }

    virtual void showStatus() const {
        std::cout << name << " | HP: " << hp << std::endl;
    }

    virtual ~Character() {}
};

#endif
