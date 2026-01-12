#include <iostream>

using namespace std;

class Kosong {
    public:
        int data(){
            return 1;
        }
};

class Isi {
    public:
        int dataInt1; // int = 4 byte
        int dataInt2; // int = 4 byte
        double dataDouble; // double = 8 byte
        string dataStr; // str = 24 byte
};

class Mahasiswa {
    public:
        string nama;

        Mahasiswa(const char* nama) {
            Mahasiswa::nama = nama;
        }
};



int main(int argc, char const *argv[])
{
    // besaran memory untuk sebuah object
    // menampilkan besar dari sebuah class kosong
    cout << "Alokasi class Kosong adalah : " << sizeof(Kosong) << " byte" << endl;
    cout << "Alokasi class Isi adalah : " << sizeof(Isi) << " byte" << endl;

    // address
    string a;
    string b;
    Mahasiswa object1 = Mahasiswa("abyan");
    string c;
    string d;
    cout << "\nAddress stack" << endl;
    cout << &a << endl;
    cout << &b << endl;
    cout << &object1 << endl;
    cout << &c << endl;
    cout << &d << endl;

    cout << "\nAddress heap" << endl;
    string a;
    string b;
    Mahasiswa* object2 = new Mahasiswa("budi");
    string c;
    string d;

    return 0;
}