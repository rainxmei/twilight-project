#include <iostream>
#include <string>

using namespace std;

class Mahasiswa{
    public:
        string nama;
        double IPK;

        //constructor
        Mahasiswa(string nama, double IPK){
            Mahasiswa::nama = nama;
            Mahasiswa::IPK = IPK;
        }

        //methods tanpa parameter dan tanpa return
        void tampilkanData(){ 
            cout << nama << endl;
            cout << IPK << endl;
        }

        //method dengan parameter dan tanpa return
        void ubahNama(const char* namaBaru){
            nama = namaBaru;
        }

        //method tanpa parameter dan dengan return
        string getNama(){
            return nama;
        }

        double getIPK(){
            return IPK;
        }

        //method dengan parameter dan dengan return
        double katrolIPK(const double &tambahanNilai){
            return Mahasiswa::IPK + tambahanNilai;
        }
};

int main(int argc, char const *argv[])
{
    Mahasiswa mahasiswa1 = Mahasiswa("abyan",4.5);
    Mahasiswa mahasiswa2 = Mahasiswa("bagas",3.0);
    mahasiswa1.tampilkanData();
    mahasiswa2.tampilkanData();
    
    mahasiswa1.ubahNama("agus");
    mahasiswa1.tampilkanData();

    string dataNama = mahasiswa1.getNama();
    cout << "dataNama = " << dataNama << endl;
    cout << "dataIPK = " << mahasiswa1.getIPK() << endl;
    cout << "nilai katrol = " << mahasiswa1.katrolIPK(1.5) << endl;
    return 0;
}