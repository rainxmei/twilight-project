#include "player.h"

#include <iostream>

using namespace std;

Player::Player(const char* name){
    this->name = name;
}

void Player::display(){
    cout << "Player ini adalah " << this->name << endl;
    cout << "Menggunakan senjata: " << this->weapon->getName();
}

void Player::equipWeapon(Weapon* weapon){
    this->weapon = weapon;
}