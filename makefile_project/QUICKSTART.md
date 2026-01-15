# Quick Start Guide

## Bắt đầu nhanh trong 3 bước

### 1. Clone/Download project
```bash
cd c-learning
```

### 2. Build project
```bash
make
```

### 3. Chạy chương trình
```bash
make run
```

## Các lệnh thường dùng

| Lệnh | Mô tả |
|------|-------|
| `make` | Build toàn bộ project |
| `make run` | Build và chạy chapter_03 |
| `make clean` | Xóa tất cả build files |
| `make rebuild` | Clean và build lại từ đầu |
| `make help` | Hiển thị các lệnh có sẵn |

## Thêm chapter mới

### Cách 1: Sử dụng template (recommend)
```bash
# Tạo chapter mới từ template chapter_03
cp -r chapter_03 chapter_04

# Edit chapter_04/Makefile, thay đổi TARGET name:
# TARGET = $(BIN_DIR)/chapter_04

# Edit chapter_04/src/main.c để viết code mới
```

### Cách 2: Tạo thủ công
```bash
mkdir -p chapter_04/{include,src}
touch chapter_04/src/main.c
# Copy Makefile từ chapter_03 và điều chỉnh
```

### Đăng ký chapter mới
Thêm vào root Makefile:
```makefile
MODULES = common source chapter_03 chapter_04
```

## Cấu trúc code mẫu

### Sử dụng common library
```c
#include "utils.h"

int numbers[] = {1, 2, 3, 4, 5};
print_array(numbers, 5);
int sum = array_sum(numbers, 5);
```

### Sử dụng source library
```c
#include "basics.h"

pointer_example();
string_example();
int result = factorial(5);
```

## Debugging

### Sử dụng lldb
```bash
make
lldb build/bin/chapter_03
(lldb) breakpoint set -n main
(lldb) run
(lldb) next
(lldb) print variable_name
(lldb) quit
```

### Memory debugging với AddressSanitizer
Uncomment trong Makefile.config:
```makefile
CFLAGS += -fsanitize=address
LDFLAGS += -fsanitize=address
```

Sau đó rebuild:
```bash
make rebuild
make run
```

## Tips & Tricks

### Build nhanh hơn với parallel jobs
```bash
make -j4  # Build với 4 parallel jobs
```

### Chỉ build một module
```bash
make common       # Chỉ build common library
make chapter_03   # Chỉ build chapter_03
```

### Xem các dependencies
```bash
make -n  # Dry run - xem commands sẽ được chạy
```

### Format code (nếu có clang-format)
```bash
find . -name "*.c" -o -name "*.h" | xargs clang-format -i
```

## Common Issues

### Issue: "make: command not found"
**Solution:** Cài đặt Xcode Command Line Tools
```bash
xcode-select --install
```

### Issue: Libraries không tìm thấy
**Solution:** Build lại từ đầu
```bash
make clean
make
```

### Issue: Thay đổi header file không trigger rebuild
**Solution:** Make không track header dependencies. Rebuild manually:
```bash
make clean
make
```

Hoặc thêm dependency tracking (advanced).
