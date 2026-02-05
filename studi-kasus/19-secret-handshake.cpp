#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

namespace Sh
{
    std::vector<std::string> secret(int val)
    {
        std::string biner;
        std::vector<std::string> action;

        while (val > 0)
        {
            if (val % 2 == 0)
            {
                biner = "0" + biner;
            }
            else
            {
                biner = "1" + biner;
            }

            val /= 2;
        }

        while (biner.size() < 5)
        {
            biner = "0" + biner;
        }

        if (biner[4] == '1')
        {
            action.push_back("wink");
        }
        if (biner[3] == '1')
        {
            action.push_back("double blink");
        }
        if (biner[2] == '1')
        {
            action.push_back("close your eyes");
        }
        if (biner[1] == '1')
        {
            action.push_back("jump");
        }
        if (biner[0] == '1')
        {
            std::reverse(action.begin(), action.end());
        }

        return action;
    }
}

int main(int argc, char const *argv[])
{
    auto result = Sh::secret(9);
    for (const auto &s : result)
    {
        std::cout << s << " ";
    }
    return 0;
}
