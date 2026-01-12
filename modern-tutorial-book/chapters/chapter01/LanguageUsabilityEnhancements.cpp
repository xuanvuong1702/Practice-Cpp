#include <iostream>

void foo(char *s) { std::cout << "String: " << s << std::endl; }

void foo(int x) { std::cout << "Integer: " << x << std::endl; }

int main() {
    std::cout << "C++ Language Usability Enhancements" << std::endl;

    foo("Hello, World!"); // Calls foo(char*)
    foo(42);              // Calls foo(int)
    foo(nullptr);         // Calls foo(char*)
    foo(NULL);

    auto ptr = std::make_unique<int>(10);

    std::cout << "Finished." << std::endl;

    return 0;
}