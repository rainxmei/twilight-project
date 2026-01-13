#include <iostream>
#include <string>

using namespace std;

namespace rain_drops {
    
    string raindrop_sounds(int number) {
        string sounds;
        if (number % 3 == 0) {
            sounds += "Pling";
        }
        if (number % 5 == 0) {
            sounds += "Plang";
        }
        if (number % 7 == 0) {
            sounds += "Plong";
        }
        if (sounds.empty()) {
            sounds = to_string(number);
        }
        return sounds;
    }
}

int main() {
    int number;
    cin >> number;
    cout << rain_drops::raindrop_sounds(number) << endl;
}