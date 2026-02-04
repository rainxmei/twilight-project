#include <iostream>
#include <string>
#include <stdexcept>

namespace Hamming
{
    int hammingCount(std::string& dna1, std::string& dna2)
    {
        if (dna1.size() != dna2.size())
        {
            throw std::runtime_error("dna tidak valid");
        }

        int count = 0;

        for (int i = 0; i < dna1.size(); i++)
        {
            if (dna1[i] == dna2[i])
            {
                count++;
            }
        }

        return count;
    }
};

int main(int argc, char const *argv[])
{
    std::string dna1 = "GAGCCTACTAACGGGAT";
    std::string dna2 = "CATCGTAATGACGGCCT";

    std::cout << Hamming::hammingCount(dna1, dna2);
    return 0;
}
