#include <iostream>
#include <string>

using namespace std;

struct aktor{
    string nama;
    int tahun_lahir;
};

struct film{
    string judul;
    string genre;
    int tahun;
    // struct aktor
    aktor pameran_1;
    aktor pameran_2;
};

int main(){

    aktor aktor1, aktor2;
    film film1, film2;

    // buat aktor 1
    aktor1.nama = "Michael";
    aktor1.tahun_lahir = 1995;

    // buat aktor 2
    aktor2.nama = "Sandra bulog";
    aktor2.tahun_lahir = 1998;

    // buat film 
    film1.judul = "Dilan 1999";
    film1.genre = "Documenter";
    film1.tahun = 2018;
    film1.pameran_1 = aktor1;
    film1.pameran_2 = aktor2;

    cout << film1.judul << endl;
    cout << film1.pameran_1.nama << endl;
    cout << film1.pameran_2.nama << endl;

    return 0;
}