/**
 * @file c_cpp_interop.cpp
 * @brief Chapter 01: C and C++ Interoperability
 * 
 * This example demonstrates how to properly use C code in C++ projects.
 * Key concepts:
 * - extern "C" usage
 * - Header guards for C/C++ compatibility
 */

#include <common/utils.hpp>
#include <iostream>

// Simulating a C-style function (in real projects, this would be in a .c file)
// The extern "C" prevents C++ name mangling
extern "C" {
    int c_add(int x, int y) {
        return x + y;
    }
    
    int c_multiply(int x, int y) {
        return x * y;
    }
}

int main() {
    mcpp::print_section("Chapter 01: C/C++ Interoperability");
    
    // Using C functions from C++
    mcpp::print_subsection("Calling C functions from C++");
    
    int result_add = c_add(10, 20);
    int result_mul = c_multiply(5, 6);
    
    std::cout << "c_add(10, 20) = " << result_add << "\n";
    std::cout << "c_multiply(5, 6) = " << result_mul << "\n";
    
    mcpp::print_subsection("Key Points");
    std::cout << "1. Use extern \"C\" to prevent name mangling\n";
    std::cout << "2. C++ is NOT a superset of C\n";
    std::cout << "3. Avoid void* implicit conversions in C++\n";
    std::cout << "4. Prefer modern C++ features over C-style code\n";
    
    return 0;
}
