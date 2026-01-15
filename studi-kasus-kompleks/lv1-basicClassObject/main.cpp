#include "character.h"
#include <iostream>

int main(){
    Character hero("knight");

    hero.showStatus();
    hero.levelUp();
    hero.showStatus();

    hero.takeDamage(50);
    hero.showStatus();

    cout << "Memory address karakter adalah: " << &hero << endl;
}