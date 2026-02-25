#include <iostream>
#include <fstream>

using namespace std;

int main(){
    
    ofstream myFile;

    // ios::out = default, operasi output;
    // ios::app = menuliskan pada akhir baris;
    // ios::trunc = default, membuat file jika tidak ada dan menghapus jika ada

    myFile.open("data3.txt", ios::app); // append
    myFile << "\nmenuliskan baris baru pada data3";
    myFile.close();

    myFile.open("data1.txt", ios::out);
    myFile << "\nmenuliskan baris baru pada data1";
    myFile.close();

    myFile.open("data2.txt", ios::trunc);
    myFile << "\nmenuliskan baris baru pada data2";
    myFile.close();

    return 0;
    // tes
}