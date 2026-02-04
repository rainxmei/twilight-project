#include <iostream>
#include <string>
#include <stdexcept>

namespace Nc
{
    int count_a = 0;
    int count_c = 0;
    int count_g = 0;
    int count_t = 0;

    std::string ncCheck(std::string in)
    {
        for (int i = 0; i < in.size(); i++)
        {
            if (in[i] != 'A' || in[i] != 'C' || in[i] != 'G' || in[i] != 'T')
            {
                throw std::runtime_error("input tidak valid");
            }

            if (in[i] == 'A')
            {
                count_a++;
            }
            else if (in[i] == 'C')
            {
                count_c++;
            }
            else if (in[i] == 'G')
            {
                count_g++;
            }
            else if (in[i] == 'T')
            {
                count_t++;
            }
        }

        std::cout << "A = " << count_a 
    }
}

int main(int argc, char const *argv[])
{
    std::string in = "GATTACA";
    std::cout << Nc::ncCheck(in);

    return 0;
}
