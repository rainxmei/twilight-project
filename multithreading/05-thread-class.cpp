// cara menjalankan thread pada class
#include <iostream>
#include <thread>
#include <chrono>

class Kamera {
public:
    void run() {
        while (true) {
            std::cout << "[KAMERA] Baca frame\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
};

int main() {
    Kamera cam;

    std::thread t1(&Kamera::run, &cam);

    t1.join();
    return 0;
}
