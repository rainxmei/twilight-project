#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character {
protected:
    std::string name;
    int hp;

public:
    Character(const std::string& name)
        : name(name), hp(100) {}

    // pure virtual function
    virtual void attack() = 0;

    void showStatus() const {
        std::cout << "Name: " << name << " | HP: " << hp << std::endl;
    }

    // virtual destructor
    virtual ~Character() {}
};

#endif

