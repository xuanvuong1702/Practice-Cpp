/**
 * @file utils.h
 * @brief Common utilities for C learning exercises
 * 
 * Các hàm tiện ích dùng chung cho tất cả chapters.
 */

#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* ============================================================================
 * Console Helpers - In ấn đẹp hơn
 * ============================================================================ */

/**
 * @brief In tiêu đề cho mỗi exercise
 * @param title Tên exercise
 */
void print_header(const char *title);

/**
 * @brief In đường kẻ phân cách
 */
void print_separator(void);

/**
 * @brief In kết quả pass/fail cho test
 * @param test_name Tên test
 * @param passed Kết quả test
 */
void print_test_result(const char *test_name, bool passed);

/* ============================================================================
 * Memory Helpers - Hỗ trợ quản lý bộ nhớ
 * ============================================================================ */

/**
 * @brief Cấp phát bộ nhớ với kiểm tra lỗi
 * @param size Kích thước cần cấp phát
 * @return Con trỏ đến vùng nhớ, exit nếu thất bại
 */
void *safe_malloc(size_t size);

/**
 * @brief Cấp phát và khởi tạo về 0
 * @param count Số phần tử
 * @param size Kích thước mỗi phần tử
 * @return Con trỏ đến vùng nhớ, exit nếu thất bại
 */
void *safe_calloc(size_t count, size_t size);

/* ============================================================================
 * String Helpers
 * ============================================================================ */

/**
 * @brief Duplicate string với kiểm tra lỗi
 * @param str Chuỗi nguồn
 * @return Chuỗi mới được cấp phát
 */
char *safe_strdup(const char *str);

/* ============================================================================
 * Array Helpers
 * ============================================================================ */

/**
 * @brief In mảng int
 * @param arr Mảng cần in
 * @param size Kích thước mảng
 */
void print_int_array(const int *arr, size_t size);

/**
 * @brief In mảng dưới dạng hex
 * @param data Con trỏ đến data
 * @param size Số bytes
 */
void print_hex_dump(const void *data, size_t size);

#endif /* UTILS_H */
