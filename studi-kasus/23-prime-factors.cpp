#include <iostream>
#include <vector>

namespace pf
{
    std::vector<int> prime_factor(int number)
    {
        std::vector<int> result;
        int divisor = 2;

        while (number > 1)
        {
            if (number % divisor == 0)
            {
                result.push_back(divisor);
                number /= divisor;
            }
            else
            {
                divisor++;
            }
        }

        return result;  
    }
}

int main(int argc, char const *argv[])
{
    auto faktor = pf::prime_factor(60);
    for (auto c : faktor)
    {
        std::cout << c << " ";
    }
    return 0;
}
