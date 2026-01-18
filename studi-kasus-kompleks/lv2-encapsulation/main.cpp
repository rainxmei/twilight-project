#include "character.h"
#include <iostream>

int main(){
    Character hero("knight");

    hero.showStatus();
    
    hero.takeDamage(50);
    hero.heal(20);
    hero.takeDamage(200);

    if (!hero.isAlive){
        cout << "Game Over!\n" << endl;
    }

    hero.levelUp();
    hero.showStatus();

    cout << "Memory address karakter adalah: " << &hero << endl;
}