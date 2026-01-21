// ketika menggunakan while tapi tanpa sleep cpu bisa 
// 100% jadi thread lain akan kelaparan cpu
#include <iostream>
#include <thread>
#include <chrono>

void kamera() {
    while (true) {
        std::cout << "[KAMERA]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void imu() {
    while (true) {
        std::cout << "[IMU]\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

int main() {
    std::thread t1(kamera);
    std::thread t2(imu);

    t1.join();
    t2.join();
}
