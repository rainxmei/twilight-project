#include <iostream>
using namespace std;

// overloading = menimpa

// basic function
int luas_kotak(int panjang, int lebar){
    int luas = panjang * lebar;
    return luas;
}

// overloading function 
int luas_kotak(int sisi){
    int luas = sisi * sisi;
    return luas;
}

double luas_kotak(double sisi){
    return sisi * sisi;
}

int main(){
    cout << "Luas kotak 2x3 : " << luas_kotak(2,3) << endl;
    cout << "Luas kotak 2x2 : " << luas_kotak(2) << endl;
    cout << "Luas kotak 2.5x2.5 : " << luas_kotak(2.5) << endl;
    return 0;
}