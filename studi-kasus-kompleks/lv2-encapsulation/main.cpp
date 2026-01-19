#include "character.h"
#include <iostream>

int main(){
    Character hero("knight");

    hero.showStatus();
    
    hero.takeDamage(50);
    hero.heal(20);
    hero.takeDamage(200);

    if (!hero.isAlive()) {
        std::cout << "Game Over!\n";
    }


    hero.levelUp();
    hero.showStatus();

    std::cout << "Memory address karakter adalah: " << &hero << std::endl;
}