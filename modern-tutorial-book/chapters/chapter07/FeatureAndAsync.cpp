#include <future>
#include <iostream>
#include <mutex>
#include <thread>

int main() {

    std::packaged_task<int()> task([]() { return 100; });

    auto result = task.get_future();

    std::thread(std::move(task)).detach();

    result.wait();

    std::cout << "result:" << result.get() << std::endl;
}