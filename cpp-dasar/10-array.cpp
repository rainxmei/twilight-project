#include <iostream>
using namespace std;

int main(){
    // membuat array
    int nilai[6];
    nilai[0] = 1;
    nilai[1] = 2;
    nilai[2] = 3;
    nilai[3] = 4;
    nilai[4] = 5;

    cout << &nilai[0] << " nilainya adalah: "<< nilai[0] << endl;
    cout << &nilai[1] << " nilainya adalah: "<< nilai[1] << endl;
    cout << &nilai[2] << " nilainya adalah: "<< nilai[2] << endl;
    cout << &nilai[3] << " nilainya adalah: "<< nilai[3] << endl;
    cout << &nilai[4] << " nilainya adalah: "<< nilai[4] << endl;

    int *ptr = nilai;
    *(ptr + 2) = 6;

    nilai[3] = 7;

    cout << endl;
    cout << &nilai[0] << " nilainya adalah: "<< nilai[0] << endl;
    cout << &nilai[1] << " nilainya adalah: "<< nilai[1] << endl;
    cout << &nilai[2] << " nilainya adalah: "<< nilai[2] << endl;
    cout << &nilai[3] << " nilainya adalah: "<< nilai[3] << endl;
    cout << &nilai[4] << " nilainya adalah: "<< nilai[4] << endl;

    cout << endl;
    cout << "ukuran array = " << sizeof(nilai) << " byte" << endl;
    cout << "jumlah member array = " << sizeof(nilai) / sizeof(int) << endl;

    return 0;
}