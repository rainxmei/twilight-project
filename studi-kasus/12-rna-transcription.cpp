#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

namespace rna_transcrip
{
    std::string transcrip(std::string &dna)
    {
        std::string rna;
        for (char c : dna)
        {
            if (c != 'G' && c != 'C' && c != 'T' && c != 'A')
            {
                throw std::runtime_error("input tidak valid");
            }

            if (c == 'G') rna += 'C';
            if (c == 'C') rna += 'G';
            if (c == 'T') rna += 'A';
            if (c == 'A') rna += 'U';
        }

        return rna;
    }
};

int main(int argc, char const *argv[])
{
    std::string val = "GCTA";
    std::cout << rna_transcrip::transcrip(val);

    return 0;
}
