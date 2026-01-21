#include <iostream>
#include <thread>

void tugas(){
    std::cout << "Halo, ini dari thread lain\n";
}

int main(){
    std::cout << "Main mulai\n";

    std::thread t1(tugas); // buat thread

    t1.join(); // tunggu thread selesai

    std::cout << "Main selesai\n";
}