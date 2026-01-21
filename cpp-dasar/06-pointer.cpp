#include <iostream>

using namespace std;

int main(){
    int a = 5;

    // pointer
    int *aptr =nullptr;
    aptr = &a;

    // int a mempunyai nilai dan address (alamat)

    cout << "nilai dari a: " << a << endl;
    cout << "alamat dari a: " << aptr << endl;

    // dereferencing, mengambil data dari sebuah pointer 
    a = 10;
    cout << "mengambil nilai dari sebuah pointer apt : " << aptr << endl;

    return 0;
}