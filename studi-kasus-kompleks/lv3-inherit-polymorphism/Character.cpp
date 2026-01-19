#include <iostream>
#include <string>
#include "Character.h"

// constructor
Character::Character(const std::string& name) :
    name(name),
    level(1)

    {
        std::cout << "Character Created!" << std::endl;
    }