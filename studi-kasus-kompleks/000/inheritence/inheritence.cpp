#include <iostream>
#include <string>

using namespace std;

class Character {
    protected:
        string name;
        int hp;
        int level;

    public:
        Character(const string& name) 
            : name(name), hp(100), level(1) {}
        
        void showStatus(){
            cout << name << hp << level << endl;
        }
};

class Player : public Character{
    public:
        Player(const string& name)
            : Character(name) {}
};

int main(int argc, char const *argv[])
{
    Player hero("knight");
    hero.showStatus();
    return 0;
}

