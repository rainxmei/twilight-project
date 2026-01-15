#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character{
    public:
        string name;
        int level;
        int hp;
        int strength;
        int agility;
        int intellegent;

        // constructor
        Character(string name);

        // methods
        void showStatus();
        void levelUp();
        void takeDamage(int damage);
};

#endif