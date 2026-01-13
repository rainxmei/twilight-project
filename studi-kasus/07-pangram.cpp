#include <iostream>
#include <string>

using namespace std;

namespace pangram {
    bool pangram_check(const string &text) {
        for (char letter = 'a'; letter <= 'z'; letter++) {
            bool found = false;

            for (char c : text) {
                if (tolower(c) == letter) {
                    found = true;
                    break;
                }

            if (!found) {
                return false;
            }
            }
        }
        return true;
    }
}

int main() {
    string text;
    getline(cin, text);
    cout << boolalpha << pangram::pangram_check(text);
}