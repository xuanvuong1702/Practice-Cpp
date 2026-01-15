# C Learning Project - Hướng dẫn Chi tiết

## 📁 Cấu trúc Project

```
c-learning/
├── Makefile                    # Root Makefile - build toàn bộ project
├── Makefile.config             # Config chung cho compiler flags
├── README.md                   # Documentation chính
├── QUICKSTART.md               # Hướng dẫn nhanh
├── .gitignore                  # Git ignore file
├── new_chapter.sh              # Script tạo chapter mới tự động
│
├── common/                     # Thư viện tiện ích dùng chung
│   ├── Makefile               # Build libcommon.a
│   ├── include/
│   │   └── utils.h            # Header file
│   └── src/
│       └── utils.c            # Implementation
│
├── source/                     # Thư viện code mẫu từ sách
│   ├── Makefile               # Build libsource.a
│   ├── include/
│   │   └── basics.h           # Header file
│   └── src/
│       └── basics.c           # Implementation
│
├── chapter_03/                 # Bài tập Chapter 3
│   ├── Makefile               # Build executable
│   └── src/
│       └── main.c             # Main program
│
└── build/                      # Build output (auto-generated)
    ├── lib/                   # Static libraries (.a files)
    │   ├── libcommon.a
    │   └── libsource.a
    ├── bin/                   # Executables
    │   └── chapter_03
    └── obj/                   # Object files (.o files)
        ├── common/
        ├── source/
        └── chapter_03/
```

## 🔧 Cách hoạt động của Make Build System

### 1. Build Flow

```
Root Makefile
    │
    ├──> common/Makefile ──> libcommon.a
    │
    ├──> source/Makefile ──> libsource.a
    │
    └──> chapter_03/Makefile ──> chapter_03 (executable)
                                   ↑
                                   │ links với
                                   ├── libcommon.a
                                   └── libsource.a
```

### 2. Dependencies

- `chapter_03` phụ thuộc vào `common` và `source`
- `source` phụ thuộc vào `common`
- Build system tự động build dependencies trước

### 3. Incremental Builds

Make chỉ rebuild những file đã thay đổi:
- Nếu chỉ sửa `main.c` → chỉ recompile main.c và relink
- Nếu sửa `utils.h` → rebuild toàn bộ (vì nhiều files depend on it)

## 📚 Libraries

### Common Library (`libcommon.a`)

**Mục đích:** Các hàm tiện ích dùng chung cho toàn project

**Functions:**
```c
void debug_print(const char *message);
int array_sum(const int *arr, size_t size);
void print_array(const int *arr, size_t size);
void swap_int(int *a, int *b);
```

**Sử dụng:**
```c
#include "utils.h"

int arr[] = {1, 2, 3, 4, 5};
print_array(arr, 5);
int sum = array_sum(arr, 5);
```

### Source Library (`libsource.a`)

**Mục đích:** Code mẫu học từ sách/tài liệu

**Functions:**
```c
void pointer_example(void);
void string_example(void);
int factorial(int n);
int is_prime(int n);
int find_max(const int *arr, size_t size);
```

**Sử dụng:**
```c
#include "basics.h"

pointer_example();      // Demo về pointers
int fact = factorial(5); // Tính 5!
```

## 🎯 Tạo Chapter Mới

### Cách 1: Sử dụng script (Khuyến nghị)

```bash
./new_chapter.sh 04
```

Script sẽ tự động:
1. Tạo thư mục `chapter_04/`
2. Tạo Makefile với config đúng
3. Tạo template `main.c`

Sau đó:
1. Thêm `chapter_04` vào `MODULES` trong root Makefile
2. Viết code trong `chapter_04/src/main.c`
3. Build: `make chapter_04`

### Cách 2: Thủ công

```bash
# 1. Copy từ chapter_03
cp -r chapter_03 chapter_04

# 2. Sửa Makefile
# Thay đổi TARGET = $(BIN_DIR)/chapter_04

# 3. Sửa main.c theo ý muốn

# 4. Thêm vào root Makefile
# MODULES = common source chapter_03 chapter_04
```

## 🛠️ Compiler Flags

Trong `Makefile.config`:

```makefile
CFLAGS = -Wall -Wextra -std=c11 -g
```

- `-Wall`: Enable all warnings
- `-Wextra`: Extra warnings
- `-std=c11`: Sử dụng C11 standard
- `-g`: Include debug symbols

### Tùy chỉnh cho Apple Silicon

Uncomment trong `Makefile.config`:
```makefile
CFLAGS += -arch arm64
```

### Enable Optimizations

```makefile
CFLAGS += -O2    # Level 2 optimization
```

### Memory Debugging

```makefile
CFLAGS += -fsanitize=address
LDFLAGS += -fsanitize=address
```

## 📖 Workflow Học Tập Đề Xuất

### 1. Đọc sách/tài liệu
- Ghi chép code mẫu vào `source/`

### 2. Thực hành
- Tạo chapter mới cho mỗi chương
- Viết bài tập vào `chapter_XX/src/main.c`

### 3. Test và Debug
```bash
make chapter_XX
make run
```

### 4. Tái sử dụng code
- Code hay → thêm vào `common/`
- Code mẫu → thêm vào `source/`

## 🔍 Debugging Tips

### 1. Compile Errors
```bash
make 2>&1 | less  # Xem full error log
```

### 2. Runtime Debugging với lldb
```bash
lldb build/bin/chapter_03
(lldb) b main              # Breakpoint tại main
(lldb) r                   # Run
(lldb) n                   # Next line
(lldb) p variable_name     # Print variable
(lldb) bt                  # Backtrace
```

### 3. Memory Leaks
```bash
# Enable AddressSanitizer trong Makefile.config
make rebuild
make run
# Sẽ tự động báo memory leaks
```

### 4. Valgrind (nếu cài đặt)
```bash
valgrind --leak-check=full ./build/bin/chapter_03
```

## 📝 Best Practices

### 1. Code Organization
- Một function = một việc
- Header files chứa declarations
- Source files chứa implementations

### 2. Naming Conventions
- Functions: `lowercase_with_underscores()`
- Macros: `UPPERCASE_WITH_UNDERSCORES`
- Types: `CamelCase` hoặc `snake_case_t`

### 3. Comments
```c
/**
 * Function description
 * @param arr Input array
 * @param size Array size
 * @return Sum of array elements
 */
int array_sum(const int *arr, size_t size);
```

### 4. Error Handling
```c
if (ptr == NULL) {
    fprintf(stderr, "Error: NULL pointer\n");
    return -1;
}
```

## 🚀 Advanced Features

### 1. Parallel Build
```bash
make -j4  # 4 parallel jobs
make -j   # Auto-detect CPU cores
```

### 2. Conditional Compilation
```c
#ifdef DEBUG
    printf("Debug: x = %d\n", x);
#endif
```

Trong Makefile:
```makefile
CFLAGS += -DDEBUG
```

### 3. Header Dependencies
Make không tự động track header dependencies. Solutions:

**Option 1:** Manual clean
```bash
make clean && make
```

**Option 2:** Auto-dependency generation (advanced)
```makefile
DEPS = $(OBJECTS:.o=.d)
-include $(DEPS)
```

## 🎓 Learning Path

1. **Week 1-2:** Basics
   - Variables, types, operators
   - Control flow (if, loops)
   - Functions

2. **Week 3-4:** Arrays & Pointers
   - Arrays
   - Pointers
   - Dynamic memory

3. **Week 5-6:** Data Structures
   - Structs
   - Linked lists
   - Trees

4. **Week 7-8:** Advanced Topics
   - File I/O
   - Multi-file projects
   - Debugging techniques

## 📞 Troubleshooting

### "make: command not found"
```bash
xcode-select --install
```

### "ld: library not found"
```bash
make clean
make
```

### Thay đổi header không có effect
```bash
make clean
make
```

### Program crashes
1. Compile với `-g`
2. Run với lldb
3. Enable AddressSanitizer

## 🎉 Conclusion

Project này cung cấp:
- ✅ Cấu trúc modular, dễ mở rộng
- ✅ Build system tự động với Make
- ✅ Libraries tái sử dụng
- ✅ Template cho bài tập mới
- ✅ Tools để debugging

Happy coding! 🚀
