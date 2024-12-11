#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool done = false;

int getSharedValue()
{
    static int sharedValue = 0;
    return sharedValue;
}

void setSharedValue(int val)
{
    static int sharedValue = 0;
    sharedValue = val;
}

void worker() {
    for (int i = 0; i < 1000000; ++i) {
        mtx.lock();
        int oldValue = getSharedValue();
        ++oldValue;
        setSharedValue(oldValue);
        mtx.unlock();
    }
    done = true;
    cv.notify_one();
}

int main() {
    std::thread thread(worker);
    {
        // Main thread does work here
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return done; });
    }

    thread.join();

    int final_value = getSharedValue();
    std::cout << "Final shared value: " << final_value << std::endl;
    return 0;
}