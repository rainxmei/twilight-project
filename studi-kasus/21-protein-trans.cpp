#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

namespace protein
{
    std::vector<std::string> trans(std::string val)
    {
        std::vector<std::string> result;

        if (val.size() % 3 != 0)
            throw std::runtime_error("input tidak valid");

        for (int i = 0; i < val.size(); i += 3)
        {
            std::string codon = val.substr(i, 3);

            if (codon == "AUG")
            {
                result.push_back("Methionine");
            }
            else if (codon == "UUU" || codon == "UUC")
            {
                result.push_back("Phenylalanine");
            }
            else if (codon == "UUA" || codon == "UUG")
            {
                result.push_back("Leucine");
            }
            else if (codon == "UCU" || codon == "UCC" || codon == "UCA" || codon == "UCG")
            {
                result.push_back("Serine");
            }
            else if (codon == "UAU" || codon == "UAC")
            {
                result.push_back("Tyrosine");
            }
            else if (codon == "UGU" || codon == "UGC")
            {
                result.push_back("Cysteine");
            }
            else if (codon == "UGG")
            {
                result.push_back("Tryptophan");
            }
            else if (codon == "UAA" || codon == "UAG" || codon == "UGA")
            {
                break;
            }
            else
            {
                throw std::runtime_error("invalid codon: " + codon);
            }
        }
        return result;
    }
}

int main(int argc, char const *argv[])
{
    std::string rna = "AUGUUUUCU";
    auto protein = protein::trans(rna);
    for (auto &i : protein)
    {
        std::cout << i << ", ";
    }
    return 0;
}