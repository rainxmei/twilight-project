#include <iostream>
#include <string>

namespace cc
{
    std::string collatz(int val)
    {
        std::string result = std::to_string(val);

        while (val != 1)
        {
            result += ',';
            if (val % 2 == 0)
            {
                val /= 2;
                result += std::to_string(val);
            }
            else
            {
                val = val * 3 + 1;
                result += std::to_string(val);
            }
        }
        return result;
    }
}

int main(int argc, char const *argv[])
{
    std::cout << cc::collatz(12);
    return 0;
}
