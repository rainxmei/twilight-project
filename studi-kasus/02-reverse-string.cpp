#include <iostream>
#include <string>

using namespace std;

namespace reverse {
    string reverse_string(const string &text) {
        string result;

        for (int i = text.size() - 1; i >= 0; i--) {
            result += text[i];
        }

        return result;
    }
}

int main() {
    string text;
    cin >> text;

    cout << reverse::reverse_string(text) << endl;
    return 0;
}