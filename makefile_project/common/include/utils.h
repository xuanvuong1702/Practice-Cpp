#ifndef COMMON_UTILS_H
#define COMMON_UTILS_H

#include <stdio.h>

/**
 * In ra thông điệp debug với prefix
 */
void debug_print(const char *message);

/**
 * Tính tổng của mảng số nguyên
 */
int array_sum(const int *arr, size_t size);

/**
 * In ra thông tin về mảng
 */
void print_array(const int *arr, size_t size);

/**
 * Swap hai số nguyên
 */
void swap_int(int *a, int *b);

#endif /* COMMON_UTILS_H */
