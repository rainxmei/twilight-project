#include <iostream>

using namespace std;

namespace leap {
    bool is_leap(int year) {
        return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
    }
}

int main() {
    int year;
    cout << "Masukkan tahun" << endl;
    cin >> year;
    
    cout << boolalpha << leap::is_leap(year);
}