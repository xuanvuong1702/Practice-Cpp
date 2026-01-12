#include <iostream>

int main() {

    char *str = "char* is adeprecate feature!";

    const char *consStr = "this is recomment!";

    auto autoStr = "autoStr";

    std::cout << str << std::endl;
    std::cout << consStr << std::endl;
    std::cout << autoStr << std::endl;

    std::cout << "-------------------------" << std::endl;

    std::unique_ptr<int> p1 = std::make_unique<int>(10);
}