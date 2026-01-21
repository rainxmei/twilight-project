#include <iostream>
#include <string>
using namespace std;

struct buah{
    string warna;
    float berat;
    int harga;
    string rasa;
};

int main(){
    buah apel;
    buah jeruk;

    apel.warna = "merah";
    apel.berat = 250.50;
    apel.harga = 5000;
    apel.rasa = "manis";

    cout <<  "apel" << endl;
    cout << apel.warna << endl;
    cout << apel.berat << endl;
    cout << apel.harga << endl;
    cout << apel.rasa << endl;

    return 0;
}