#include <iostream>
#include <string>

using namespace std;

namespace twofer {
    string dialogue(string name="you") {
        return "one for " + name + " one for me.";
    }   
}

int main() {
    string name;
    cin >> name;
    cout << twofer::dialogue(name);
}