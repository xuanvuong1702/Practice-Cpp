#include "basics.h"
#include <stdio.h>
#include <string.h>

void pointer_example(void) {
    printf("\n=== Pointer Example ===\n");
    int x = 42;
    int *ptr = &x;
    
    printf("Value of x: %d\n", x);
    printf("Address of x: %p\n", (void*)&x);
    printf("Value of ptr: %p\n", (void*)ptr);
    printf("Value pointed by ptr: %d\n", *ptr);
    
    // Thay đổi giá trị thông qua pointer
    *ptr = 100;
    printf("After *ptr = 100, x = %d\n", x);
}

void string_example(void) {
    printf("\n=== String Example ===\n");
    char str1[] = "Hello";
    char str2[] = "World";
    char result[50];
    
    // Copy và concatenate
    strcpy(result, str1);
    strcat(result, " ");
    strcat(result, str2);
    
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("Result: %s\n", result);
    printf("Length: %zu\n", strlen(result));
}

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n <= 3) {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int find_max(const int *arr, size_t size) {
    if (size == 0) {
        return 0;
    }
    
    int max = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
