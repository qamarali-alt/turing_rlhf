#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> atomic_counter(0);

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        ++atomic_counter;
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();
    
    std::cout << "Final atomic counter value: " << atomic_counter << std::endl;
    return 0;
}