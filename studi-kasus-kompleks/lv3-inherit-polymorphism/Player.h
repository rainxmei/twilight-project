#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include <iostream>
#include <string>

class Player : public Character{
    public:
        Player(const std::string& name);
        void attack(Character& target);
};

#endif