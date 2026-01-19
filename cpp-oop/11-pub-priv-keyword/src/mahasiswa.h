#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <iostream>
#include <string>

#include "mahasiswa.h"

using namespace std;

class Mahasiswa{
    public: // ini dapat diakses oleh siapa pun
        string namePublic;

    private: // ini hanya dapat diakses oleh class itu sendiri
        string namePrivate;

    // methods dan constructor
    public:
        // constructor selalu public
        Mahasiswa(const char* name);
        void show();
    
    private:
        void showPrivate();
};

#endif