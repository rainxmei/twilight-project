#include <iostream>
#include <set>
#include <stdexcept>
#include <vector>

namespace som
{
    std::set<int> point(int level, std::vector<int> &item)
    {
        std::set<int> result;
        for (auto &base : item)
        {
            for (int i = 0; i < level; i++)
            {
                if (i % base == 0)
                {
                    result.insert(i);
                }
            }
        }

        return result;
    }
}

int main(int argc, char const *argv[])
{
    int sum = 0;
    std::vector<int> magical{3, 5};
    auto player = som::point(20, magical);
    for (auto &c : player)
    {
        sum += c;
    }
    std::cout << sum;
    return 0;
}
