# C Learning Project

Project để học C programming với cấu trúc modular sử dụng Make trên macOS.

## Cấu trúc Project

```
c-learning/
├── Makefile                # Root Makefile
├── common/                 # Thư viện tiện ích dùng chung
│   ├── Makefile
│   ├── include/
│   │   └── utils.h
│   └── src/
│       └── utils.c
├── source/                 # Code học từ sách (library)
│   ├── Makefile
│   ├── include/
│   │   └── basics.h
│   └── src/
│       └── basics.c
├── chapter_03/             # Bài tập thực hành
│   ├── Makefile
│   └── src/
│       └── main.c
└── build/                  # Build output (gitignored)
    ├── lib/                # Static libraries (.a)
    ├── bin/                # Executables
    └── obj/                # Object files (.o)
```

## Yêu cầu

- macOS với Xcode Command Line Tools
- GCC/Clang compiler
- Make

Cài đặt Xcode Command Line Tools:
```bash
xcode-select --install
```

## Build Instructions

### Build toàn bộ project
```bash
make
```

### Build từng module riêng lẻ
```bash
make common       # Build common library
make source       # Build source library
make chapter_03   # Build chapter_03 executable
```

### Chạy chương trình
```bash
make run          # Build và chạy chapter_03
```

### Clean project
```bash
make clean        # Xóa tất cả build artifacts
make rebuild      # Clean và build lại
```

### Hiển thị help
```bash
make help
```

## Thư viện

### Common Library (`libcommon.a`)
Chứa các hàm tiện ích dùng chung:
- `debug_print()` - In debug messages
- `array_sum()` - Tính tổng mảng
- `print_array()` - In mảng
- `swap_int()` - Swap hai số nguyên

### Source Library (`libsource.a`)
Chứa code mẫu học từ sách:
- `pointer_example()` - Ví dụ về pointers
- `string_example()` - Ví dụ về strings
- `factorial()` - Tính giai thừa
- `is_prime()` - Kiểm tra số nguyên tố
- `find_max()` - Tìm số lớn nhất

## Thêm Chapter mới

1. Tạo thư mục mới:
```bash
mkdir -p chapter_XX/{include,src}
```

2. Copy Makefile từ chapter_03 và điều chỉnh TARGET name

3. Thêm module vào root Makefile trong biến MODULES

4. Viết code trong `chapter_XX/src/main.c`

## Debugging

Build với debug symbols (đã enable mặc định):
```bash
make
lldb build/bin/chapter_03
```

## Notes

- Mọi thay đổi trong `common/` hoặc `source/` sẽ trigger rebuild cho các modules phụ thuộc
- Object files và libraries được cached trong `build/` để tăng tốc độ compile
- Sử dụng `-j4` để build song song: `make -j4`

## Tác giả

Học viên C Programming
