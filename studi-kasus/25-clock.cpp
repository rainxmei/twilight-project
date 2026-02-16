#include <iostream>
#include <iomanip>
#include <string>

class Clock
{
public:
    int hour;
    int minutes;

    Clock(int hour, int minutes)
    {
        Clock::hour = hour;
        Clock::minutes = minutes;
    }

    void add(int hourVal, int minuteVal)
    {
        hour += hourVal;
        minutes += minuteVal;
    }

    void substrack(int hourVal, int minuteVal)
    {
        hour -= hourVal;
        minutes -= minuteVal;
    }

    void printClock()
    {
        int totalMinutes;

        totalMinutes = (hour * 60) + minutes;
        totalMinutes = ((totalMinutes % 1440) + 1440) % 1440;

        hour = totalMinutes / 60;
        minutes = totalMinutes % 60;

        std::cout << std::setw(2) << std::setfill('0') << hour;
        std::cout << ":";
        std::cout << std::setw(2) << std::setfill('0') << minutes;
    }   
};

int main(int argc, char const *argv[])
{
    Clock jam1(9, 5);
    jam1.add(0, 60);
    jam1.printClock();
    return 0;
}