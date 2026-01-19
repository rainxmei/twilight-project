#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

using namespace std;

class Player{
    public:
        string name;

        // constructor
        Player(const char*); // dalam bentuk prototype
        void display();
        string getName();
        void setName(const char*);
};

#endif