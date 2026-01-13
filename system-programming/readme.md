
# C Book Practice Project (C + CMake)

## 1. Mục tiêu dự án

Dự án này được thiết kế để:

- Học và thực hành ngôn ngữ **C một cách có hệ thống**
- Bám sát cấu trúc **các chương trong sách C**
- Tuân theo **best practices trong industry**
- Build và run được trên **Linux và Windows**
- Tránh over-engineering, tập trung vào **bản chất C**

Dự án **không phải** là một application hoàn chỉnh, mà là một **learning project có cấu trúc chuẩn**.

---

## 2. Tổng quan cấu trúc thư mục

```text
c-book-project/
├── CMakeLists.txt          # CMake cấu hình chính
├── README.md               # Tài liệu hướng dẫn (file này)
│
├── include/                # Header files (public interface)
│   ├── ch01_basics/
│   ├── ch02_functions/
│   ├── ch03_pointers/
│   ├── ch04_strings/
│   ├── ch05_io/
│   └── common/
│
├── src/                    # Source code (implementation)
│   ├── ch01_basics/
│   ├── ch02_functions/
│   ├── ch03_pointers/
│   ├── ch04_strings/
│   ├── ch05_io/
│   └── main.c
│
├── chapters/               # Executable theo từng chương
│   ├── ch01.c
│   ├── ch02.c
│   ├── ch03.c
│   ├── ch04.c
│   └── ch05.c
│
└── build/                  # Thư mục build (auto-generated)
````

---

## 3. Nguyên tắc tổ chức code

### 3.1 Chia theo chương của sách

* Mỗi **chương trong sách** tương ứng với:

  * 1 thư mục trong `include/`
  * 1 thư mục trong `src/`
  * 1 file chạy minh hoạ trong `chapters/`

Ví dụ:

* Chương 3 (Pointers & Memory):

  * `include/ch03_pointers/`
  * `src/ch03_pointers/`
  * `chapters/ch03.c`

---

### 3.2 Quy ước Header (`.h`)

* Header chỉ chứa:

  * Khai báo hàm
  * Macro / typedef cần thiết
* **Không viết logic trong header**
* Luôn dùng include guard

Ví dụ:

```c
#ifndef MEMORY_H
#define MEMORY_H

void demo_malloc(void);

#endif
```

---

### 3.3 Quy ước Source (`.c`)

* Mỗi `.c` phải include **header của chính nó**
* Logic cài đặt đặt hoàn toàn trong `.c`
* Không include file `.c` khác

Ví dụ:

```c
#include "ch03_pointers/memory.h"
#include <stdlib.h>
#include <stdio.h>

void demo_malloc(void) {
    int *p = malloc(sizeof(int));
    if (!p) {
        return;
    }

    *p = 42;
    printf("value = %d\n", *p);
    free(p);
}
```

---

### 3.4 File `chapters/chXX.c`

* Mỗi file trong `chapters/` là **entry point** cho 1 chương
* Chỉ gọi các hàm demo của chương đó
* Không chứa logic phức tạp

Ví dụ:

```c
#include "ch03_pointers/memory.h"

int main(void) {
    demo_malloc();
    return 0;
}
```

---

## 4. Cách thêm code cho chương mới

Giả sử thêm **Chương 6**:

1. Tạo thư mục:

```text
include/ch06_error/
src/ch06_error/
```

2. Thêm header:

```text
include/ch06_error/error.h
```

3. Thêm source:

```text
src/ch06_error/error.c
```

4. Thêm file chạy:

```text
chapters/ch06.c
```

5. Thêm `ch06` vào danh sách executable trong `CMakeLists.txt`

---

## 5. Cấu trúc CMake

### 5.1 Vai trò của CMake

* Quản lý build cho toàn bộ project
* Tạo executable cho **từng chương**
* Hoạt động trên:

  * Linux (gcc / clang)
  * Windows (MSVC / MinGW / Ninja)

---

### 5.2 Build thư viện chung

Toàn bộ code trong `src/` được build thành một static library:

* Mỗi chương link vào cùng một library
* Tránh duplicate code
* Phản ánh đúng cách tổ chức project trong industry

---

## 6. Build & Run

### 6.1 Build project

Từ thư mục gốc:

```bash
cmake -S . -B build
cmake --build build
```

---

### 6.2 Chạy từng chương

Linux / macOS:

```bash
./build/ch03
```

Windows:

```bat
build\ch03.exe
```

---

### 6.3 Clean build

Xoá toàn bộ file build:

```bash
rm -rf build
```

---

## 7. Compiler & tiêu chuẩn

* Ngôn ngữ: **C99**
* Compiler warnings:

  * `-Wall`
  * `-Wextra`
  * `-Wpedantic`
* Không dùng compiler extension đặc thù

Mục tiêu là viết code **portable, predictable, đúng chuẩn C**.

---

## 8. Định hướng mở rộng

Sau khi học xong sách, cấu trúc này có thể được mở rộng để:

* Viết CLI tool
* Viết system utility
* Viết embedded host tool
* Tái sử dụng module sang project khác

Chỉ cần thay `chapters/` bằng `app/`, phần còn lại giữ nguyên.

---
