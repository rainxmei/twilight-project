#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>

using namespace std;

class Weapon{
    private:
        string name;
        double attackPower;

    public:
        Weapon(const char*, double);
        void display();
        //getter, read only
        string getName();
        
};

#endif