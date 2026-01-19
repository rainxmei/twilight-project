#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character {
public:
    Player(const std::string& name)
        : Character(name) {}

    void attack() override {
        std::cout << name << " attacks with sword!" << std::endl;
    }
};

#endif
