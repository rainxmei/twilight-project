#include <iostream>
#include <thread>

void sensor(int id) {
    std::cout << "Sensor " << id << " aktif\n";
}

int main() {
    std::thread t1(sensor, 1); // buat thread
    std::thread t2(sensor, 2);

    t1.join(); // nunggu thread selesai
    t2.join();

    return 0;
}
