#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int shared_resource = 0;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        std::scoped_lock lock(mtx);
        shared_resource++;
    }
}

int main() {
    std::thread thread1(increment);
    std::thread thread2(increment);

    thread1.join();
    thread2.join();

    std::cout << "Final shared resource value: " << shared_resource << std::endl;
    return 0;
}