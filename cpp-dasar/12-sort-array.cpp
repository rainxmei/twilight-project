#include <iostream>
#include <array>
#include <algorithm>

const size_t arraySize = 10;

void printArray(std::array <int, arraySize> &angka){
    std::cout << "Array ";
    for(int &a : angka){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void printArray(std::array <char, arraySize> &angka){
    std::cout << "Array: ";
    for(char &a : angka){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::array <int, arraySize> angka = {9,5,6,7,4,2,1,8,3,0};
    std::array <char, arraySize> huruf = {'g','e','b','a','d','f','c','h','g','z'};

    printArray(angka);
    printArray(huruf);

    std::cout << std::endl;

    std::sort(angka.begin(), angka.end());
    printArray(angka);

    std::sort(huruf.begin(), huruf.end());
    printArray(huruf);

    return 0;
}