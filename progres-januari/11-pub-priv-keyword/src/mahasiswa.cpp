#include <iostream>

#include "mahasiswa.h"

Mahasiswa::Mahasiswa(const char* name){
    this->namePublic = name;
    this->namePrivate = name;
}

void Mahasiswa::show(){
    cout << "Nama mahasiswa : " << this->namePrivate << endl;
}

void Mahasiswa::showPrivate(){
    cout << "Nama mahasiswa : " << this->namePrivate << endl;
}