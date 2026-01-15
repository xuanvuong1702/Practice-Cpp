/**
 * @file utils.c
 * @brief Implementation of common utilities
 */

#include "utils.h"

/* ============================================================================
 * Console Helpers
 * ============================================================================ */

void print_header(const char *title)
{
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════╗\n");
    printf("║  %-58s║\n", title);
    printf("╚════════════════════════════════════════════════════════════╝\n");
    printf("\n");
}

void print_separator(void)
{
    printf("────────────────────────────────────────────────────────────────\n");
}

void print_test_result(const char *test_name, bool passed)
{
    if (passed) {
        printf("  [PASS] %s\n", test_name);
    } else {
        printf("  [FAIL] %s\n", test_name);
    }
}

/* ============================================================================
 * Memory Helpers
 * ============================================================================ */

void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: malloc failed for size %zu\n", size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void *safe_calloc(size_t count, size_t size)
{
    void *ptr = calloc(count, size);
    if (ptr == NULL) {
        fprintf(stderr, "Error: calloc failed for %zu x %zu\n", count, size);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/* ============================================================================
 * String Helpers
 * ============================================================================ */

char *safe_strdup(const char *str)
{
    if (str == NULL) {
        return NULL;
    }
    
    char *dup = strdup(str);
    if (dup == NULL) {
        fprintf(stderr, "Error: strdup failed\n");
        exit(EXIT_FAILURE);
    }
    return dup;
}

/* ============================================================================
 * Array Helpers
 * ============================================================================ */

void print_int_array(const int *arr, size_t size)
{
    printf("[");
    for (size_t i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void print_hex_dump(const void *data, size_t size)
{
    const unsigned char *bytes = (const unsigned char *)data;
    
    for (size_t i = 0; i < size; i++) {
        if (i > 0 && i % 16 == 0) {
            printf("\n");
        }
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}
