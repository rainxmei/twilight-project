#include <iostream>
#include <cmath>
#include <cstdlib>

namespace dc
{
    int selisih(int val)
    {
        int square = 0;
        int sum = 0;
        for (int i = 1; i <= val; i++)
        {
            square += i;
            sum += std::pow(i, 2);
        }
        square = std::pow(square, 2);
        return abs(square - sum);

    }
}

int main(int argc, char const *argv[])
{
    std::cout << dc::selisih(10);
    return 0;
}
