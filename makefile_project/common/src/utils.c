#include "utils.h"
#include <stdio.h>

void debug_print(const char *message) {
    printf("[DEBUG] %s\n", message);
}

int array_sum(const int *arr, size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

void print_array(const int *arr, size_t size) {
    printf("Array[%zu]: [ ", size);
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");
}

void swap_int(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
