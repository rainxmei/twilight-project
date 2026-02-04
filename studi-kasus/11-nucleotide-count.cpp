#include <iostream>
#include <string>
#include <stdexcept>
#include <map>

namespace Nc
{
    std::map<char, int> count(const std::string &dna)
    {
        std::map<char, int> result{
            {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}
        };

        for (char c : dna)
        {
            if (c != 'A' && c != 'C' && c != 'G' && c != 'T')
            {
                throw std::runtime_error("input tidak valid");
            }

            result[c]++;
        }
        return result;
    }
}

int main(int argc, char const *argv[])
{
    std::string in = "GATTACA";
    auto dna = Nc::count(in);
    
    for (auto [k, v] : dna){
        std::cout << k << " : " << v << "\n";
    }

    return 0;
}
