#include <iostream>
#include <string>

using namespace std;

namespace triangle {
    string define_triangle(int a, int b, int c) {
        if (a <= 0 || b <= 0 || c <= 0) {
            return "bukan segitiga";
        }

        if (a + b >= c && b + c >= a && c + a >= b) {

            if (a == b && b == c) {
                return "segitiga sama sisi";
            }
            else if (a == b || b == c || a == c) {
                return "segitiga sama kaki";
            }
            return "segitiga sembarang";
        }
        return "bukan segtiga";
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << triangle::define_triangle(a, b, c);
}