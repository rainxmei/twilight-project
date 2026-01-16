#include <iostream>
#include <string>

#include "player.h"
#include "weapon.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Player* player1 = new Player("Knight");
    Weapon* weapon1 = new Weapon("senapan",50);

    // implementasi setter unutk equip weapon 
    player1->equipWeapon(weapon1);

    player1->display();

    return 0;
}