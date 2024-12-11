#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        ++counter;
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Final counter value: " << counter << std::endl;
    return 0;
}