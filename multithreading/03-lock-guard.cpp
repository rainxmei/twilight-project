// dengan lock guard program bisa otomatis unlock 
// ketika keluar dari scope
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void tambah() {
    for (int i = 0; i < 1000; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        counter++;
    }
}

int main() {
    std::thread t1(tambah);
    std::thread t2(tambah);

    t1.join();
    t2.join();

    std::cout << "Counter = " << counter << std::endl;
    return 0;
}