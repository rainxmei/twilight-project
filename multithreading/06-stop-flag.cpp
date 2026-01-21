// cara menghentikan thread dengan aman
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

class Kamera {
public:
    // bool running = true; // tidak bisa pakai bool biasa 
    // karena bisa race condition, thread tidak sadar flag 
    // berubah
    std::atomic<bool> running{true}; // jadi menggunakan atomic

    void run() {
        while (running) {
            std::cout << "[KAMERA] jalan\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        std::cout << "[KAMERA] berhenti\n";
    }

    void stop() {
        running = false;
    }
};

int main() {
    Kamera cam;

    std::thread t(&Kamera::run, &cam);

    std::this_thread::sleep_for(std::chrono::seconds(3));
    cam.stop();   // sinyal berhenti

    t.join();
    return 0;
}