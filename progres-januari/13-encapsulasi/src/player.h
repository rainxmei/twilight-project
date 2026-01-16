#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "weapon.h"

using namespace std;

class Player{
    private:
        string name;
        Weapon* weapon;

    public:
        Player(const char*);
        void display();
        // setter
        void equipWeapon(Weapon*);
};

#endif