#include <iostream>
#include <string>

using namespace std;

class Hero{
    public:
        string name;

    public:
        Hero(const char* name){
            this->name = name;
        }

        // setter
        void setName(const char* name){
            this->name = name;
        }

        // getter
        string getName() const {
            return this->name;
        }

        // member function ini tidak akan bisa, karena attributenya tidak const
        // void setName(const char* name){
        //     this->name = name;
        // }

        void display() const{
            cout << "Name : " << this->name << endl;
        }
};

int main(int argc, char const *argv[])
{
    Hero hero1 = Hero("knight"); 
    const Hero hero2 = Hero("abyan"); // object konstan tidak bisa kita rubah
    hero1.display();
    hero1.name = "heru"; // ini bisa
    hero1.display();
    hero1.setName("Bagas"); // ini bisa
    hero1.display();

    hero2.display();
    // hero2.name = "heru"; // ini tidak bisa 
    hero2.display();
    // hero2.setName("Bagas"); // ini tidak bisa
    hero2.display();
    cout << hero2.getName() << endl; // karena member function const tidak merubah apapun

    // kesimpulan
    // 1. jika object nya tidak const, maka seluruh member bisa dipanggil
    // 2. jika object nya const, maka hanya member function/methods yang const yang dapat dipanggil

    return 0;
}