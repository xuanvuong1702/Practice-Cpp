/**
 * @file modern_preview.cpp
 * @brief Chapter 01: A Preview of Modern C++ Features
 * 
 * This example gives a taste of modern C++ features that will be
 * covered in detail in later chapters.
 */

#include <common/utils.hpp>
#include <iostream>
#include <functional>
#include <vector>

int main() {
    mcpp::print_section("Chapter 01: Modern C++ Preview");
    
    // ========================================
    // Preview: Lambda expressions (Chapter 03)
    // ========================================
    mcpp::print_subsection("Lambda Expressions");
    
    auto greet = []() {
        std::cout << "Hello from a lambda!\n";
    };
    greet();
    
    // Lambda with capture
    int value = 42;
    auto print_value = [&value]() {
        std::cout << "Captured value: " << value << "\n";
    };
    print_value();
    
    // ========================================
    // Preview: auto keyword (Chapter 02)
    // ========================================
    mcpp::print_subsection("Auto Keyword");
    
    auto integer = 10;
    auto floating = 3.14;
    auto text = "Hello";
    
    std::cout << "auto integer: " << integer << "\n";
    std::cout << "auto floating: " << floating << "\n";
    std::cout << "auto text: " << text << "\n";
    
    // ========================================
    // Preview: Range-based for loop (Chapter 02)
    // ========================================
    mcpp::print_subsection("Range-based For Loop");
    
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    
    std::cout << "Numbers: ";
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";
    
    // ========================================
    // Preview: std::ref (from the book's example)
    // ========================================
    mcpp::print_subsection("std::ref Example (from book)");
    
    // This recreates the example from the book
    [out = std::ref(std::cout << "Result: " << (10 + 20))]() {
        out.get() << " (using std::ref)\n";
    }();
    
    mcpp::print_line();
    std::cout << "These features will be covered in detail in upcoming chapters!\n";
    
    return 0;
}
