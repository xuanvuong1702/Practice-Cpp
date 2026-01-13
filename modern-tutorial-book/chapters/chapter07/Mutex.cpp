#include <iostream>
#include <mutex>
#include <thread>

int shared_Value = 0;

std::mutex mtx;

void increment() {
    for (int i = 0; i < 1000; i++) {
        mtx.lock();

        shared_Value++;

        mtx.unlock();
    }
}

int main() {
    std::thread t([]() { std::cout << "hello thread" << std::endl; });

    t.join();

    std::cout << "shared value: " << shared_Value << std::endl;

    increment();

    std::cout << "shared value after: " << shared_Value << std::endl;
}