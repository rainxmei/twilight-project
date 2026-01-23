#include <iostream>
#include <string>
#include <bitset>

using namespace std;

void printBinary(unsigned short val, string nama){
    cout << nama << " = " << bitset<8>(val) << endl;
}

int main(){

    unsigned short a = 5;
    unsigned short b = 10;
    unsigned short c;

    cout << "\n<< = Bitwise SHR" << endl;
    c = a >> 2;
    printBinary(a,"a");
    printBinary(c,"c");
    cout << "c = " << c << endl;

    cout << "\n<< = Bitwise SHL" << endl;
    c = a << 2;
    printBinary(a,"a");
    printBinary(c,"c");
    cout << "c = " << c << endl;

    cout << "\n~ = Bitwise NOT" << endl;
    c = ~a;
    printBinary(a,"a");
    printBinary(c,"c");
    cout << "c = " << c << endl;

    cout << "\n^ = Bitwise XOR" << endl;
    c = a ^ b;
    printBinary(a,"a");
    printBinary(b,"b");
    printBinary(c,"c");
    cout << "c = " << c << endl;

    cout << "\n| = Bitwise OR" << endl;
    c = a | b;
    printBinary(a,"a");
    printBinary(b,"b");
    printBinary(c,"c");
    cout << "c = " << c << endl;

    cout << "\n& = Bitwise AND" << endl;
    c = a & b;
    printBinary(a,"a");
    printBinary(b,"b");
    printBinary(c,"c");
    cout << "c = " << c << endl;

    return 0;
}

// bitwise operator
// &    AND Bitwise AND
// |    OR Bitwise OR
// ^    XOR Bitwise exclusive OR
// ~    NOT
// <<   SHL Shift bits left
// >>   SHR Shift bits right