#include <iostream>
#include <cstdint>

using namespace std;

// link soal
// https://exercism.org/tracks/cpp/exercises/grains
namespace grains {

    uint64_t grains_in_square(int n) {
        return 1ULL << (n - 1);
    }

    uint64_t calculate_grains(int square) {
        uint64_t total_grains = 0;
        for (int i = 1; i <= square; i++) {
            total_grains += grains_in_square(i);
        }
        return total_grains;
    }
}

int main() {
    int square = 64;
    cout << grains::grains_in_square(square) << endl;
    cout << grains::calculate_grains(square) << endl;
}