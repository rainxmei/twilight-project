#include <iostream>
#include <string> 

using namespace std;

class Mahasiswa{
    public:
        string nama;
        string NIM;
        string jurusan;
        double IPK;

        //ini adalah constructor yang dipanggil pertama kali saat object dibuat
        // Mahasiswa(){
        //     cout << "ini adalah constructor" << endl;
        // }

        //constructor dengan parameter
        Mahasiswa(string inputNama, string inputNIM, string inputJurusan, double inputIPK){
            Mahasiswa::nama = inputNama;
            Mahasiswa::NIM = inputNIM;
            Mahasiswa::jurusan = inputJurusan;
            Mahasiswa::IPK = inputIPK;

            cout << Mahasiswa::nama << endl;
            cout << Mahasiswa::NIM << endl;
            cout << Mahasiswa::jurusan << endl;
            cout << Mahasiswa::IPK << endl;
        }

};

int main(int argc, char const *argv[])
{
    Mahasiswa mahasiswa1 = Mahasiswa("abyan","2425600075","teknologi rekayasa internet",4.0);
    Mahasiswa mahasiswa2 = Mahasiswa("bagas","2425600060","teknologi rekayasa internet",3.5);

    return 0;
}