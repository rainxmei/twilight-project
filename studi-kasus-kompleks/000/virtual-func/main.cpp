#include <iostream>
#include <string>

using namespace std;

class Character {
public:
    virtual void attack() {
        std::cout << "Character attacks\n";
    }
};

class Player : public Character {
public:
    void attack() override {
        std::cout << "Player attacks with sword\n";
    }
};

int main() {
    Character* c = new Player();
    c->attack();  // ❗

    delete c;
    // kalo semisal tanpa virtual outputnya akan tergantung tipe pointernya
    // sedangkan ketika menggunakan virtual akan memanggiil object aslinya
}
