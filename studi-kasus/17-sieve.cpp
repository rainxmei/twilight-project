#include <iostream>
#include <string>

namespace prime
{
    void prime_check()
    {
        std::string angka;
        std::string value;

        for (int i = 2; i <= 10; i++)
        {
            bool isPrime = true;
            angka += std::to_string(i);
            
            for (int j = 2; j * j <= i; j++)
            {
                if(i % j == 0){
                    isPrime = false;
                    break;
                }
            }

            if (isPrime){
                value += 'T';
            }else{
                value += 'F';
            }
            angka += " ";
            value += " ";
        }

        std::cout << angka << "\n";
        std::cout << value << "\n";
    }
}

int main(int argc, char const *argv[])
{
    prime::prime_check();
    return 0;
}
