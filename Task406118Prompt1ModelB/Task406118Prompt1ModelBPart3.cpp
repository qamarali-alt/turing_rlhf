
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <atomic>

std::shared_mutex mtx;
std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        std::unique_lock<std::shared_mutex> lock(mtx, std::unique_lock_type::exclusive);
        ++counter;
    }
}

int read_count() {
    std::shared_lock<std::shared_mutex> lock(mtx);
    return counter;
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Final counter value: " << read_count() << std::endl;
    return 0;
}