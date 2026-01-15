#include <stdio.h>
#include "utils.h"      // từ common library
#include "basics.h"     // từ source library

void test_common_library(void);
void test_source_library(void);
void test_exercises(void);

int main(void) {
    printf("===========================================\n");
    printf("    C Learning - Chapter 03 Exercises     \n");
    printf("===========================================\n");
    
    test_common_library();
    test_source_library();
    test_exercises();
    
    printf("\n===========================================\n");
    printf("           All tests completed!           \n");
    printf("===========================================\n");
    
    return 0;
}

void test_common_library(void) {
    printf("\n--- Testing Common Library ---\n");
    
    debug_print("Common library is working!");
    
    int numbers[] = {1, 2, 3, 4, 5};
    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    
    print_array(numbers, size);
    printf("Sum: %d\n", array_sum(numbers, size));
    
    int a = 10, b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap_int(&a, &b);
    printf("After swap: a = %d, b = %d\n", a, b);
}

void test_source_library(void) {
    printf("\n--- Testing Source Library ---\n");
    
    // Test pointer và string examples
    pointer_example();
    string_example();
    
    // Test factorial
    printf("\n=== Factorial Example ===\n");
    for (int i = 0; i <= 5; i++) {
        printf("factorial(%d) = %d\n", i, factorial(i));
    }
    
    // Test prime number
    printf("\n=== Prime Number Example ===\n");
    int test_primes[] = {2, 3, 4, 5, 10, 17, 20, 23};
    for (size_t i = 0; i < sizeof(test_primes)/sizeof(test_primes[0]); i++) {
        int n = test_primes[i];
        printf("%d is %s\n", n, is_prime(n) ? "prime" : "not prime");
    }
    
    // Test find max
    printf("\n=== Find Max Example ===\n");
    int arr[] = {3, 7, 2, 9, 1, 5};
    printf("Max in array: %d\n", find_max(arr, sizeof(arr)/sizeof(arr[0])));
}

void test_exercises(void) {
    printf("\n--- Chapter 03 Exercises ---\n");
    
    // Exercise 1: Tính tổng số chẵn từ 1 đến 100
    int sum_even = 0;
    for (int i = 2; i <= 100; i += 2) {
        sum_even += i;
    }
    printf("Exercise 1: Sum of even numbers (1-100) = %d\n", sum_even);
    
    // Exercise 2: In bảng cửu chương của 7
    printf("\nExercise 2: Multiplication table for 7:\n");
    for (int i = 1; i <= 10; i++) {
        printf("7 x %2d = %2d\n", i, 7 * i);
    }
    
    // Exercise 3: Đảo ngược mảng
    printf("\nExercise 3: Reverse array:\n");
    int original[] = {1, 2, 3, 4, 5};
    size_t len = sizeof(original) / sizeof(original[0]);
    
    printf("Original: ");
    print_array(original, len);
    
    // Đảo ngược
    for (size_t i = 0; i < len / 2; i++) {
        swap_int(&original[i], &original[len - 1 - i]);
    }
    
    printf("Reversed: ");
    print_array(original, len);
}
