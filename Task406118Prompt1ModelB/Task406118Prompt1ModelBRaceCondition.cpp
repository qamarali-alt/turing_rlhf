#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> shared_counter(0);

void increment_without_sync() {
    for (int i = 0; i < 1000000; ++i) {
        ++shared_counter;
    }
}

int main() {
    std::thread thread1(increment_without_sync);
    std::thread thread2(increment_without_sync);

    thread1.join();
    thread2.join();

    std::cout << "Expected counter value: 2000000, Actual: " << shared_counter << std::endl;
    return 0;
}