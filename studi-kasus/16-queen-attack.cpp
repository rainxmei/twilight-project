#include <iostream>
#include <cmath>

struct Queen{
    int col;
    int row;
};

bool can_attack(Queen a, Queen b){
    if (a.col == b.col) return true;
    if (a.row == b.row) return true;
    if (std::abs(a.col - b.col) == std::abs(a.row - b.row)) return true;
    return false;
}

int main(int argc, char const *argv[])
{
    Queen white{2, 3};
    Queen black{5, 6};

    std::cout << can_attack(white, black);
    return 0;
}
