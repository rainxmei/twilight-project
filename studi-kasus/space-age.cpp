#include <iostream>

using namespace std;

namespace space {
    const double earth_year_seconds = 31557600;

    const double mercury = 0.2408467;
    const double venus = 0.61519726;
    const double earth = 1.0;
    const double mars = 1.8808158;
    const double jupiter = 11.862615;
    const double saturn = 29.447498;
    const double uranus = 84.016846;
    const double neptune = 164.79132;

    double age(double second, double planet) {
        return second / earth_year_seconds / planet;
    }
}

int main() {
    double second;
    cin >> second;

    cout << space::age(second, space::mercury);
}
