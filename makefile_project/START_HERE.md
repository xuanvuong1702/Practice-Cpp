# 🎓 C Learning Project - Tổng Quan

## 📦 Nội dung Package

Project C Learning hoàn chỉnh với cấu trúc modular sử dụng Make build system cho macOS.

### 📂 Files và Thư mục

```
c-learning/
├── 📄 README.md                    # Documentation chính
├── 📄 PROJECT_GUIDE.md             # Hướng dẫn chi tiết về project
├── 📄 QUICKSTART.md                # Hướng dẫn nhanh để bắt đầu
├── 📄 MAKEFILE_CHEATSHEET.md       # Cheat sheet các lệnh make
├── 📄 Makefile                     # Root Makefile
├── 📄 Makefile.config              # Cấu hình compiler chung
├── 📄 .gitignore                   # Git ignore file
├── 🔧 new_chapter.sh               # Script tạo chapter mới
│
├── 📁 common/                      # ⭐ Thư viện tiện ích dùng chung
│   ├── Makefile
│   ├── include/utils.h
│   └── src/utils.c
│
├── 📁 source/                      # ⭐ Thư viện code mẫu từ sách
│   ├── Makefile
│   ├── include/basics.h
│   └── src/basics.c
│
├── 📁 chapter_03/                  # ⭐ Bài tập Chapter 3
│   ├── Makefile
│   └── src/main.c
│
└── 📁 build/                       # Build output (auto-generated)
    ├── lib/                       # Static libraries
    ├── bin/                       # Executables
    └── obj/                       # Object files
```

## 🚀 Quick Start (3 bước)

### 1. Extract và vào thư mục
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

**Kết quả mong đợi:**
```
===========================================
    C Learning - Chapter 03 Exercises     
===========================================

--- Testing Common Library ---
[DEBUG] Common library is working!
Array[5]: [ 1, 2, 3, 4, 5 ]
Sum: 15
...
===========================================
           All tests completed!           
===========================================
```

## ✨ Tính năng chính

### 🔹 Cấu trúc Modular
- **common library**: Các hàm tiện ích tái sử dụng
- **source library**: Code mẫu học từ sách
- **chapter_XX**: Bài tập thực hành cho từng chương

### 🔹 Build System
- ✅ Makefile hierarchy cho từng module
- ✅ Incremental builds (chỉ compile file thay đổi)
- ✅ Parallel build support (`make -j4`)
- ✅ Automatic dependency resolution

### 🔹 Developer Tools
- ✅ Script tạo chapter mới tự động
- ✅ Debug support (lldb, AddressSanitizer)
- ✅ Comprehensive documentation

## 📚 Documentation

| File | Mô tả |
|------|-------|
| `README.md` | Tổng quan về project |
| `QUICKSTART.md` | Hướng dẫn nhanh cho người mới |
| `PROJECT_GUIDE.md` | Hướng dẫn chi tiết, best practices |
| `MAKEFILE_CHEATSHEET.md` | Tham khảo nhanh các lệnh make |

## 🛠️ Các lệnh thường dùng

```bash
# Build
make                    # Build toàn bộ project
make clean              # Xóa build artifacts
make rebuild            # Clean và build lại

# Run
make run                # Build và chạy chapter_03

# Build từng module
make common             # Build common library
make source             # Build source library
make chapter_03         # Build chapter_03

# Tạo chapter mới
./new_chapter.sh 04     # Tạo chapter_04

# Help
make help               # Xem tất cả lệnh available
```

## 📖 Code Examples

### Using Common Library
```c
#include "utils.h"

int numbers[] = {1, 2, 3, 4, 5};
print_array(numbers, 5);        // In mảng
int sum = array_sum(numbers, 5); // Tính tổng
debug_print("Hello!");           // Debug message
```

### Using Source Library
```c
#include "basics.h"

pointer_example();              // Demo pointers
string_example();               // Demo strings
int fact = factorial(5);        // Tính 5!
int prime = is_prime(17);       // Kiểm tra số nguyên tố
```

## 🎯 Workflow Học Tập

1. **Đọc tài liệu/sách** về một topic
2. **Ghi code mẫu** vào `source/` library
3. **Tạo chapter mới** cho bài tập:
   ```bash
   ./new_chapter.sh 04
   ```
4. **Viết code thực hành** trong `chapter_04/src/main.c`
5. **Build và test**:
   ```bash
   make chapter_04
   make run
   ```
6. **Debug nếu cần** với lldb hoặc AddressSanitizer

## 🔧 Requirements

- **macOS** (tested on macOS 12+)
- **Xcode Command Line Tools**
  ```bash
  xcode-select --install
  ```
- **GCC/Clang** (included with Xcode CLT)
- **Make** (included with Xcode CLT)

## 🎓 Learning Path

### Week 1-2: Fundamentals
- Variables, types, operators
- Control flow (if, loops)
- Functions
- **Practice:** `chapter_01`, `chapter_02`

### Week 3-4: Arrays & Pointers
- Arrays và pointer arithmetic
- Dynamic memory allocation
- Strings
- **Practice:** `chapter_03`, `chapter_04`

### Week 5-6: Data Structures
- Structs và unions
- Linked lists
- Stacks, queues
- **Practice:** `chapter_05`, `chapter_06`

### Week 7-8: Advanced
- File I/O
- Multi-file projects
- Debugging techniques
- **Practice:** `chapter_07`, `chapter_08`

## 🐛 Debugging

### Compile-time Debugging
```bash
make 2>&1 | less        # Đọc error messages
```

### Runtime Debugging với lldb
```bash
lldb build/bin/chapter_03
(lldb) b main           # Set breakpoint
(lldb) run              # Run program
(lldb) next             # Next line
(lldb) print var        # Print variable
```

### Memory Debugging
Uncomment trong `Makefile.config`:
```makefile
CFLAGS += -fsanitize=address
LDFLAGS += -fsanitize=address
```

Sau đó:
```bash
make rebuild
make run
```

## 📝 Best Practices

### Code Style
- Sử dụng meaningful variable names
- Comment các function phức tạp
- Keep functions small và focused
- Error handling với proper return codes

### Project Organization
- Common code → `common/`
- Learning examples → `source/`
- Exercises → `chapter_XX/`
- Không commit `build/` directory

### Build System
- Luôn chạy `make clean` sau khi sửa header files
- Sử dụng `make -j4` để build nhanh hơn
- Kiểm tra errors cẩn thận

## 🤝 Extending the Project

### Thêm Library Mới
1. Tạo thư mục: `mkdir -p mylib/{include,src}`
2. Copy Makefile từ `common/`
3. Viết code
4. Thêm vào root Makefile dependencies

### Thêm Chapter Mới
```bash
./new_chapter.sh XX     # XX = chapter number
# Edit root Makefile
# Add to MODULES
```

### Custom Compiler Flags
Edit `Makefile.config`:
```makefile
CFLAGS += -DMY_DEBUG_FLAG
CFLAGS += -O2           # Optimization
```

## 🎉 Project Highlights

✅ **Production-ready** build system  
✅ **Well-documented** với 4 tài liệu hướng dẫn  
✅ **Modular design** dễ mở rộng  
✅ **Working examples** ngay từ đầu  
✅ **Developer-friendly** với automation scripts  
✅ **Educational focus** với clear learning path  

## 💡 Tips

- **Build nhanh hơn**: `make -j4`
- **Incremental builds**: Chỉ sửa → chỉ rebuild file đó
- **Clean builds**: Khi có lỗi lạ → `make clean && make`
- **Parallel development**: Nhiều chapters cùng lúc OK
- **Version control**: Git-ready với `.gitignore`

## 🔗 Next Steps

1. ✅ Đọc `QUICKSTART.md` để bắt đầu
2. ✅ Run `make run` để xem demo
3. ✅ Đọc `PROJECT_GUIDE.md` để hiểu sâu hơn
4. ✅ Tạo chapter mới và bắt đầu code!

---

## 📧 Support

Nếu gặp vấn đề:
1. Check `PROJECT_GUIDE.md` → Troubleshooting section
2. Check `MAKEFILE_CHEATSHEET.md` → Common commands
3. Run `make help` để xem available commands

---

**Happy Coding! 🚀**

*Made with ❤️ for C learners on macOS*
