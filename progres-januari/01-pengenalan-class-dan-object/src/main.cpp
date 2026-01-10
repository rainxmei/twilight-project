#include <iostream>
#include <string>

using namespace std;

class Mahasiswa{
    public:
        string nama;
        string NIM;
        string jurusan;
        double IPK;
};

int main(int argc, char const *argv[])
{
    Mahasiswa data1;
    data1.nama = "abyan";
    data1.NIM = "2425600075";
    data1.jurusan = "teknologi rekayasa internet";
    data1.IPK = 4.0;

    Mahasiswa data2;
    data2.nama = "bagas";
    data2.NIM = "2225600060";
    data2.jurusan = "teknologi rekayasa internet";
    data2.IPK = 3.5;

    cout << data1.nama << endl;
    cout << data1.NIM << endl;
    cout << data1.jurusan << endl;
    cout << data1.IPK << endl;
    cout << endl;
    cout << data2.nama << endl;
    cout << data2.NIM << endl;
    cout << data2.jurusan << endl;
    cout << data2.IPK << endl;

    return 0;
}