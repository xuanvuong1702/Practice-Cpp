# Makefile Commands Cheat Sheet

## 🚀 Build Commands

### Basic Build
```bash
make                  # Build toàn bộ project
make all              # Tương tự 'make'
make -j4              # Build với 4 parallel jobs (nhanh hơn)
make -j               # Auto-detect số cores và build parallel
```

### Build Specific Modules
```bash
make common           # Chỉ build common library
make source           # Chỉ build source library  
make chapter_03       # Chỉ build chapter_03 executable
```

### Clean & Rebuild
```bash
make clean            # Xóa tất cả build outputs
make rebuild          # Clean và build lại từ đầu
```

### Run Programs
```bash
make run              # Build và chạy chapter_03
./build/bin/chapter_03   # Chạy trực tiếp (nếu đã build)
```

## 🔍 Debugging & Info

### Verbose Build
```bash
make -n               # Dry run - chỉ show commands, không thực thi
make -d               # Debug mode - show chi tiết quá trình build
make --trace          # Trace dependencies
```

### Check What Would Be Built
```bash
make -q               # Quiet check - exit code 0 nếu không cần build
                      # exit code non-zero nếu cần rebuild
```

### Makefile Syntax Check
```bash
make -p               # Print database - show tất cả rules và variables
```

## 📁 Working with Modules

### Add New Chapter
```bash
./new_chapter.sh 04   # Tạo chapter_04 tự động
```

Sau đó edit root Makefile:
```makefile
MODULES = common source chapter_03 chapter_04
```

Build chapter mới:
```bash
make chapter_04
```

## 🛠️ Advanced Usage

### Force Rebuild
```bash
make -B               # Rebuild mọi thứ, ignore timestamps
make -B chapter_03    # Force rebuild chapter_03
```

### Ignore Errors
```bash
make -k               # Keep going - tiếp tục build dù có errors
make -i               # Ignore errors
```

### Set Variables
```bash
make CC=clang         # Dùng clang thay vì gcc
make CFLAGS="-O3"     # Override compiler flags
make DEBUG=1          # Custom variable
```

### Multiple Targets
```bash
make common source    # Build nhiều targets cùng lúc
```

## 📊 Makefile Structure

### Typical Makefile Targets
```makefile
all:        # Default target
clean:      # Remove build artifacts
install:    # Install (if needed)
run:        # Run program
test:       # Run tests
help:       # Show help
```

### Phony Targets
Targets không phải là file thực:
```makefile
.PHONY: all clean run help
```

## 🎯 Common Patterns

### Build Only If Changed
```bash
make              # Tự động chỉ build file đã thay đổi
```

### Full Rebuild
```bash
make clean        # Xóa cũ
make              # Build mới
# Hoặc:
make rebuild      # Một lệnh
```

### Build và Test
```bash
make && make run  # Build, nếu thành công thì run
```

### Continuous Development
```bash
# Terminal 1: Watch và auto-rebuild
while true; do make; sleep 2; done

# Terminal 2: Run program
```

## 🐛 Troubleshooting Commands

### When Build Fails
```bash
make clean        # Xóa build artifacts
make -j1          # Build single-threaded để dễ đọc errors
make 2>&1 | less  # Pipe errors to pager
```

### Check Dependencies
```bash
make -n           # Xem sẽ build gì
make --trace      # Trace dependency chain
```

### Find Missing Headers
```bash
gcc -M src/main.c -I./include    # Show dependencies
```

## 💡 Tips & Tricks

### Speed Up Builds
```bash
# 1. Parallel build
make -j4

# 2. Use ccache (if installed)
make CC="ccache gcc"

# 3. Incremental builds
make  # chỉ build những gì cần
```

### Quiet Output
```bash
make -s           # Silent mode - ít output hơn
make -s clean     # Clean quietly
```

### Multiple Makefiles
```bash
make -C common    # Run Makefile trong thư mục common
make -f MyMake    # Dùng Makefile khác (thay vì 'Makefile')
```

### Custom Build Directory
```bash
make BUILD_DIR=/tmp/build
```

## 📝 Useful Aliases

Thêm vào `~/.bashrc` hoặc `~/.zshrc`:

```bash
# Build shortcuts
alias mb='make'
alias mc='make clean'
alias mr='make rebuild'
alias mrun='make run'
alias mj='make -j4'

# Build và run
alias mbr='make && make run'

# Clean và rebuild
alias mrr='make clean && make'
```

## 🔧 Environment Variables

```bash
export CC=clang           # Dùng clang
export CFLAGS="-O3 -g"    # Custom flags
export MAKEFLAGS="-j4"    # Luôn build parallel

make  # Sẽ dùng các biến trên
```

## 📖 Reading Makefile Output

### Normal Build Output
```
Building common library...
gcc -Wall -Wextra -std=c11 -g -I./include -c src/utils.c -o ../build/obj/common/utils.o
ar rcs ../build/lib/libcommon.a ../build/obj/common/utils.o
Created library: ../build/lib/libcommon.a
```

### Understanding Each Line
1. `gcc -Wall ...`: Compile command
2. `ar rcs ...`: Create static library
3. `Created library: ...`: Success message

### Error Messages
```
src/main.c:10:5: error: use of undeclared identifier 'x'
    printf("%d", x);
    ^
```
- File: `src/main.c`
- Line: `10`
- Column: `5`
- Problem: `use of undeclared identifier 'x'`

## 🎓 Learning Resources

### Makefile Tutorial
```bash
man make          # Manual page
info make         # Info documentation
```

### Common Make Variables
```makefile
$@    # Target name
$<    # First prerequisite
$^    # All prerequisites
$?    # Prerequisites newer than target
```

### Example Usage
```makefile
%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@
    # $< = source.c
    # $@ = source.o
```

## 🎯 Project-Specific Commands

### C Learning Project
```bash
make              # Build all
make run          # Build and run chapter_03
make clean        # Clean all
make help         # Show help

# Build specific parts
make common       # Just common lib
make source       # Just source lib
make chapter_03   # Just chapter_03

# Development
./new_chapter.sh 04   # Create new chapter
make chapter_04       # Build new chapter
```

## ✅ Cheatsheet Summary

| Command | Action |
|---------|--------|
| `make` | Build project |
| `make clean` | Remove builds |
| `make rebuild` | Clean + build |
| `make run` | Build + run |
| `make -j4` | Parallel build |
| `make -n` | Dry run |
| `make help` | Show help |
| `./new_chapter.sh XX` | New chapter |

---

**Pro Tip:** Thêm `make help` vào project để show các commands available!
