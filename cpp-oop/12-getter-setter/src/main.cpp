#include <iostream>
#include <string>

using namespace std;

class Player{
    private:
        string name;
        double attackPower;
        int level;
        int exp;

    public:
        Player(const char* name){
            this->name = name;
            this->level = 1;
            this->exp = 0;
            this->attackPower = 100;
        }

        // getter, ini artinya kita akan membuat attribute menjadi read only
        string getName(){
            return this->name;
        }

        // setter, ini untuk write data ke class
        void addExperience(int expValue){
            int maxExp = 100;
            cout << "Mendapatkan exp = " << expValue << endl;
            this->exp += expValue;
            if(this->exp >= maxExp){
                // maka dia level up
                this->level++;
                this->attackPower += 100;
                cout << "LEVEL UP" << endl;
                this->exp = 0;
            }
        }

        void display(){
            cout << "Name\t: " << this->name << endl;
            cout << "Level\t: " << this->level <<", Exp : " << this->exp << endl;
            cout << "Attack\t: " << this->attackPower    << endl;
        }
};

int main(int argc, char const *argv[])
{
    Player player1 = Player("Knight"); // ini distack
    player1.display();

    // implementasi dari getter
    cout << player1.getName() << endl; // read
    // player1.name = "kirito"; // tidak bisa write

    // kegiatan bertarung
    player1.addExperience(50); //setter
    player1.addExperience(50);
    player1.addExperience(50);
    player1.addExperience(50);

    player1.display();


    return 0;
}