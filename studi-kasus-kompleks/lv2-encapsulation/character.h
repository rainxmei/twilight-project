#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character{
    private:
        std::string name;
        int level;
        int maxHp;
        int hp;
        int strength;
        int agility;
        int intelligence;

    public:
        // constructor
        Character(const std::string& name);

        // getter
        std::string getName() const;
        int getHp() const;
        int getMaxHp() const;
        int getLevel() const;

        // methods
        void showStatus() const;
        void levelUp();
        void takeDamage(int damage);
        void heal(int heal);
        bool isAlive() const;
};

#endif