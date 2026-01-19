#include <iostream>
#include <string> 

using namespace std;

// data member
class ClassType{
    public:
        string dataStr;
        double dataDouble;
        double m_dataDouble;

        ClassType(const char* dataStr, double dataDouble){
            // dengan menggunakan namespace dari class
            ClassType::dataStr = dataStr;

            // dengan menggunakan "this"
            cout << this << endl;
            this->dataDouble = dataDouble;

            // dengan menggunakan konversi penamaan;
            m_dataDouble = dataDouble;

        }
};
namespace tes{

    class Player{

        public:
            string name;
            double power;
            int health;

            Player(const char* name, double power){
                Player::setName(name);
                this->setPower(power);
            }

            void setName(const char* name){
                this->name = name;
            }

            void setPower(double power){
                this->power = power;
            }

            void setHealth(int);
    };
}

void tes::Player::setHealth(int health){
    this->health = health;
}

int main(int argc, char const *argv[])
{
    ClassType* object1 = new ClassType("object 1",0.05);
    cout << object1->dataStr << endl;
    cout << object1->dataDouble << endl;
    cout << object1->m_dataDouble << endl;

    tes::Player* player1 = new tes::Player("abyan",100);
    cout << player1->name << endl;
    player1->setHealth(10);
    cout << player1->health << endl;

    return 0;
}