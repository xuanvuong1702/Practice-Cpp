#pragma once

/**
 * @file utils.hpp
 * @brief Common utilities for Modern C++ Learning project
 * 
 * This header provides helper functions and macros that are useful
 * across different chapters of the book.
 */

#include <iostream>
#include <string>
#include <chrono>
#include <type_traits>

namespace mcpp {  // modern cpp

// ============================================================================
// Print Utilities
// ============================================================================

/**
 * @brief Print a section header for better output organization
 */
inline void print_section(const std::string& title) {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "  " << title << "\n";
    std::cout << "========================================\n";
}

/**
 * @brief Print a subsection header
 */
inline void print_subsection(const std::string& title) {
    std::cout << "\n--- " << title << " ---\n";
}

/**
 * @brief Print a separator line
 */
inline void print_line() {
    std::cout << "----------------------------------------\n";
}

// ============================================================================
// Type Information Utilities (useful for learning type deduction)
// ============================================================================

/**
 * @brief Get the type name as string (simplified)
 * Useful for understanding auto, decltype, template deduction
 */
template<typename T>
constexpr std::string_view type_name() {
    #if defined(__clang__)
        std::string_view name = __PRETTY_FUNCTION__;
        std::string_view prefix = "std::string_view mcpp::type_name() [T = ";
        std::string_view suffix = "]";
    #elif defined(__GNUC__)
        std::string_view name = __PRETTY_FUNCTION__;
        std::string_view prefix = "constexpr std::string_view mcpp::type_name() [with T = ";
        std::string_view suffix = "; std::string_view = std::basic_string_view<char>]";
    #elif defined(_MSC_VER)
        std::string_view name = __FUNCSIG__;
        std::string_view prefix = "class std::basic_string_view<char,struct std::char_traits<char> > __cdecl mcpp::type_name<";
        std::string_view suffix = ">(void)";
    #else
        std::string_view name = "Unknown";
        std::string_view prefix = "";
        std::string_view suffix = "";
    #endif
    
    name.remove_prefix(prefix.size());
    name.remove_suffix(suffix.size());
    return name;
}

/**
 * @brief Print type information for a variable
 */
template<typename T>
void print_type(const std::string& var_name, [[maybe_unused]] T&& value) {
    std::cout << var_name << " has type: " << type_name<T>() << "\n";
}

// ============================================================================
// Timing Utilities (useful for Chapter 07 - Concurrency)
// ============================================================================

/**
 * @brief Simple RAII timer for measuring execution time
 */
class ScopedTimer {
public:
    explicit ScopedTimer(const std::string& name = "Operation")
        : name_(name)
        , start_(std::chrono::high_resolution_clock::now()) 
    {}
    
    ~ScopedTimer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start_);
        std::cout << name_ << " took " << duration.count() << " microseconds\n";
    }

    // Non-copyable
    ScopedTimer(const ScopedTimer&) = delete;
    ScopedTimer& operator=(const ScopedTimer&) = delete;

private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
};

// ============================================================================
// Compile-time Utilities
// ============================================================================

/**
 * @brief Check if two types are the same (wrapper for std::is_same_v)
 */
template<typename T, typename U>
constexpr bool is_same_type = std::is_same_v<std::decay_t<T>, std::decay_t<U>>;

}  // namespace mcpp

// ============================================================================
// Convenience Macros
// ============================================================================

/**
 * @brief Print variable name and its value
 * Usage: PRINT_VAR(x) -> "x = 42"
 */
#define PRINT_VAR(var) std::cout << #var << " = " << (var) << std::endl

/**
 * @brief Print variable name, type and value
 */
#define PRINT_VAR_TYPE(var) \
    std::cout << #var << " (type: " << mcpp::type_name<decltype(var)>() << ") = " << (var) << std::endl
