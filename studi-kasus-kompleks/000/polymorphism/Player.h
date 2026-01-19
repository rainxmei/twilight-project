#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Player(const std::string& name)
        : Character(name, 100, 20) {}

    void attack(Character& target) override {
        std::cout << name << " attacks with sword!\n";
        target.takeDamage(strength * 2);
    }
};

#endif
