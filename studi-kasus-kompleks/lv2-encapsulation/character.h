#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

using namespace std;

class Character{
    private:
        string name;
        int level;
        int maxHp;
        int hp;
        int strength;
        int agility;
        int intelligence;

    public:
        // constructor
        Character(const string& name);

        // methods
        void showStatus();
        void levelUp();
        void takeDamage(int damage);
        void heal(int heal);
};

#endif