#include <iostream>
using namespace std;

union nama{
    int int_value;
    char char_value[4];
};

int main(){
    nama haha;

    haha.int_value = 1234567;

    cout << "data int_value: " << haha.int_value << endl;
    cout << "data char_value: " << haha.char_value << endl;

    haha.char_value[0] = 'a';
    haha.char_value[1] = 'b';
    haha.char_value[2] = 'c';
    haha.char_value[3] = 'd';
    haha.char_value[4] = 'e';

    cout << "data int_value: " << haha.int_value << endl;
    cout << "data char_value: " << haha.char_value << endl;

    return 0;
}