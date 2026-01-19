#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
public:
    Enemy(const std::string& name)
        : Character(name, 80, 10) {}

    void attack(Character& target) override {
        std::cout << name << " attacks!\n";
        target.takeDamage(strength);
    }
};

#endif
