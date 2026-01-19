#include <iostream>
#include <string>

using namespace std;

class Hero{
    private:
        string name;
        double health;

    public:
        // dengan default assignment
        Hero(const char* name = "Player", double health = 100){
            this->name = name;
            this->health = health;
        }

        void display(){
            cout << "\nPlayer name = " << this->name << endl;
            cout << "Health = " << this->health << endl;
        }
};

int main(int argc, char const *argv[])
{
    Hero* hero1 = new Hero("knight",125); // Heap
    hero1->display();

    Hero hero2 = Hero(); // Stack
    hero2.display();

    Hero* hero3 = new Hero("bagas");
    hero3->display();

    return 0;
}