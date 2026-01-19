#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"
#include <iostream>
#include <string>

class Enemy : public Character{
    public:
        Enemy(const std::string& name);
        void attack(Character& target);
};

#endif