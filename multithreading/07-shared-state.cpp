#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <atomic>

struct WorldModel
{
    double ball_x = 0.0;
    double ball_y = 0.0;
    double yaw = 0.0;
};

WorldModel world;
std::mutex world_mtx;
std::atomic<bool> running{true};

void vision_thread()
{
    while (running)
    {
        {
            std::lock_guard<std::mutex> lock(world_mtx);
            world.ball_x += 0.1;
            world.ball_y += 0.05;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void imu_thread()
{
    while (running)
    {
        {
            std::lock_guard<std::mutex> lock(world_mtx);
            world.yaw += 1.0;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

void strategy_thread()
{
    while (running)
    {
        WorldModel local;
        {
            std::lock_guard<std::mutex> lock(world_mtx);
            local = world; // copy data
        }

        // pakai data tanpa mutex
        std::cout << "[STRATEGY] Ball(" << local.ball_x << ", " << local.ball_y;
        std::cout << ") " << "Yaw: " << local.yaw << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main()
{
    std::thread t1(vision_thread);
    std::thread t2(imu_thread);
    std::thread t3(strategy_thread);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    running = false;

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Program selesai dengan aman\n";
    return 0;
    // tes
}