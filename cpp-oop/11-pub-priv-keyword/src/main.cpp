#include <iostream>
#include <string>

#include "mahasiswa.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Mahasiswa* mahasiswa = new Mahasiswa("abyan");
    // coba akses data public dan private
    cout << mahasiswa->namePublic << endl; // karena public dapat diakses
    // cout << mahasiswa->namePrivate << endl; // karena private tidak dapat diakses

    Mahasiswa* mahasiswa2 = new Mahasiswa("udin");
    mahasiswa2->show();
    // mahasiswa2->showPrivate(); // ini tidak bisa karena private

    return 0;
}