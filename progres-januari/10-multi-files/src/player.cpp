#include <iostream>
#include "player.h"

using namespace std;

Player::Player(const char* name){
    this->name = name;
}

void Player::display(){
    cout << "Nama player: " << this->name << endl;
}

string Player::getName(){
    return this->name;
}

void Player::setName(const char* name){
    this->name = name;
}