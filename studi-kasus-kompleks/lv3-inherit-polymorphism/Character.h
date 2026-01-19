#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>

class Character{
    protected:
        std::string name;
        int level;
        int maxHp;
        int hp;
        int strength;
        int agility;
        int intelligence;

    public:
        // contructor
        Character(const std::string& name);

        // methods
        virtual void showStatus() const;
        virtual void attack(Character& target) = 0;
        virtual void takeDamage(int damage);
        virtual void levelUp();
        virtual void heal(int amount);
        virtual ~Character();
};

#endif