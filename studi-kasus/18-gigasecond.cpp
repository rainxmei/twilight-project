#include <iostream>
#include <chrono>
#include <ctime>

int main(int argc, char const *argv[])
{
    std::tm t = {};
    t.tm_year = 2015 - 1900;
    t.tm_mon = 0;
    t.tm_mday = 24;

    t.tm_hour = 22;
    t.tm_min = 0;
    t.tm_sec = 0;

    std::time_t start_time = std::mktime(&t); // convert tm to time_t
    auto start = std::chrono::system_clock::from_time_t(start_time); // convert time_t to time_point

    auto giga = std::chrono::seconds(1'000'000'000);
    auto result = start + giga;

    std::time_t result_time = std::chrono::system_clock::to_time_t(result); // convert time_point to time_t

    std::cout << std::ctime(&result_time); // print the result
    return 0;
}
