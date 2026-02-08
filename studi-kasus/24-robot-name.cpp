#include <iostream>
#include <random>
#include <set>
#include <string>

class Robot
{
private:
    std::string name;

    static std::set<std::string> used_names;

    static std::string generate_unique_name()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());

        std::uniform_int_distribution<int> letter('A', 'Z');
        std::uniform_int_distribution<int> digit(0, 9);

        std::string n;
        do
        {
            n.clear();
            n += char(letter(gen));
            n += char(letter(gen));
            n += std::to_string(digit(gen));
            n += std::to_string(digit(gen));
            n += std::to_string(digit(gen));
        } while (used_names.count(n));

        used_names.insert(n);
        return n;
    }

public:
    std::string get_name()
    {
        if (name.empty())
            name = generate_unique_name();
        return name;
    }

    void reset()
    {
        name.clear();
    }
};

std::set<std::string> Robot::used_names;

int main(int argc, char const *argv[])
{
    Robot r1, r2;

    std::cout << r1.get_name() << "\n";
    std::cout << r2.get_name() << "\n";

    r1.reset();
    std::cout << r1.get_name() << "\n";
    return 0;
}
