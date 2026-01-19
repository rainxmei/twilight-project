#include <iostream>
#include <string>

using namespace std;

// belajar tentang friend class
// akses friend class hanya satu arah, tidak berlaku sebaliknya
// friend class akan memberikan akses dari class yang mendeklarasikan friend
class PersegiPanjang;

class Persegi{
    // memberikan akses seluruh atribut dan method kepada clasa PersegiPanjang 
    friend class PersegiPanjang;
    private:
        double sisi;

    public:
        Persegi(double sisi){
            this->sisi = sisi;
        }

        double luas(){
            return this->sisi*this->sisi;
        }

        bool isLebihPanjang(const PersegiPanjang &obj){
            bool isTrue = this->sisi > obj.panjang;
            return isTrue;
        }

};

class PersegiPanjang{
    friend class Persegi;
    private:
        double panjang;
        double lebar;

    public:
        PersegiPanjang(double panjang,double lebar){
            this->panjang = panjang;
            this->lebar = lebar;
        }

        double luas(){
            return this->lebar*this->panjang;
        }

        bool isLebihPanjang(const Persegi &obj){
            bool isTrue = this->panjang > obj.sisi;
            return isTrue;
        }
};

int main(int argc, char const *argv[])
{
    // buat object
    Persegi persegi = Persegi(5);
    PersegiPanjang kotak = PersegiPanjang(5,10);

    cout << "Luas Persegi = " << persegi.luas() << endl;
    cout << "Luas Kotak = " << kotak.luas() << endl;

    bool logika = kotak.isLebihPanjang(persegi);

    return 0;
}