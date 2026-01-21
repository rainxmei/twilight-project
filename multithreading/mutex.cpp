// solusi race condition dengan mutex
// mutex = kunci
// jadi thread lain gabisa masuk
#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;
std::mutex mtx;

void tambah() {
    for (int i = 0; i < 1000; i++) {
        mtx.lock();
        counter++;
        mtx.unlock();
    }
}

int main() {
    std::thread t1(tambah);
    std::thread t2(tambah);

    t1.join();
    t2.join();

    std::cout << "Counter = " << counter << std::endl;
    return 0;
    // jadi kalo tanpa mutex hasilnya akan 
    // acak tidak selalu pas 2000
}
