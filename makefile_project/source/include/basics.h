#ifndef SOURCE_BASICS_H
#define SOURCE_BASICS_H

#include <stddef.h>

/**
 * Ví dụ về pointers và arrays
 */
void pointer_example(void);

/**
 * Ví dụ về strings
 */
void string_example(void);

/**
 * Tính giai thừa (factorial)
 */
int factorial(int n);

/**
 * Kiểm tra số nguyên tố
 */
int is_prime(int n);

/**
 * Tìm số lớn nhất trong mảng
 */
int find_max(const int *arr, size_t size);

#endif /* SOURCE_BASICS_H */
