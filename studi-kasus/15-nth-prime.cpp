#include <iostream>
#include <stdexcept>
#include <cmath>

namespace prime
{
    int nth_prime(int val)
    {
        int count = 0;
        int angka = 2;

        if (val <= 0)
        {
            throw std::invalid_argument(" harus positif");
        }

        while (count != val)
        {
            bool isPrime = true;

            if (angka % 2 == 0 && angka != 2)
            {
                angka++;
                continue;
            }

            for (int i = 2; i * i <= angka; i++)
            {
                if (angka % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                count++;
            }
            angka++;
        }
        return angka - 1;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << prime::nth_prime(3);
    return 0;
}
