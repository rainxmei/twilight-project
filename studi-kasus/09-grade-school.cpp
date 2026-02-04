#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdexcept>

namespace School
{
    std::map<int, std::vector<std::string>> student;

    void add(const std::string &name, int grade)
    {
        auto &students = student[grade];

        for (const auto &[x, students] : student)
        {
            if (std::find(students.begin(), students.end(), name) != students.end())
            {
                throw std::runtime_error("Student sudah ada");
            }
        }

        students.push_back(name);
        std::sort(students.begin(), students.end());
    }

    std::vector<std::string> roster_all()
    {
        std::vector<std::string> result;

        for (const auto &[x, students] : student)
        {
            result.insert(result.end(), students.begin(), students.end());
        }

        return result;
    }
};

int main()
{
    School::add("Jim", 2);
    School::add("Anna", 1);
    School::add("Barb", 1);
    School::add("Charlie", 1);
    School::add("Alex", 2);
    School::add("Peter", 2);
    School::add("Zoe", 2);
    // School::add("Jim", 5);

    for (auto name : School::roster_all())
    {
        std::cout << name << " ";
    }
}