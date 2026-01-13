
#include <iostream>

void lambda_demo() {
    int value = 1;
    auto copy_value = [value]() { return value; };
    auto ref_value = [&value]() { return value; };

    value = 100;

    std::cout << "value: " << value << std::endl;
    std::cout << "copy value: " << copy_value() << std::endl;
    std::cout << "ref value: " << ref_value() << std::endl;
}

int main() {

    int value = 100;

    auto f1 = []() { return 99; };

    auto f2 = [value]() { return value; };

    auto f3 = [&value]() { return value; };

    auto f4 = [=]() { return value; };

    lambda_demo();
}
