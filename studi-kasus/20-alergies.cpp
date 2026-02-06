#include <iostream>
#include <string>
#include <vector>

namespace alergies
{

    std::vector<std::string> alergi_check(int val)
    {
        std::vector<std::string> result;

        if (val & 1)
            result.push_back("eggs");
        if (val & 2)
            result.push_back("peanut");
        if (val & 4)
            result.push_back("shellfish");
        if (val & 8)
            result.push_back("strawberries");
        if (val & 16)
            result.push_back("tomatoes");
        if (val & 32)
            result.push_back("chocolate");
        if (val & 64)
            result.push_back("pollen");
        if (val & 128)
            result.push_back("cats");

        return result;
    }
}

int main(int argc, char const *argv[])
{
    auto alergi = alergies::alergi_check(34);
    for (auto &c : alergi){
        std::cout << c << " ";
    }
        return 0;
}
