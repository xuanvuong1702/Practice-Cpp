# C Learning Project

Dự án thực hành C theo sách "Systems Programming" - Được tổ chức theo từng chapter.

## 📁 Cấu trúc dự án

```
c-learning/
├── CMakeLists.txt          # Root CMake configuration
├── common/                 # Shared utilities
│   ├── CMakeLists.txt
│   ├── include/
│   └── src/
├── source/                 # Code học từ sách (library)
│   ├── CMakeLists.txt
│   ├── include/
│   └── src/
├── chapter_03/             # Exercises cho từng chapter
│   └── CMakeLists.txt
└── build/                  # Build output (gitignored)
```

---

## 🐧 Build trên Linux/macOS

### Cài đặt

```bash
# Ubuntu/Debian
sudo apt update
sudo apt install build-essential cmake

# macOS
xcode-select --install
brew install cmake
```

### Build và chạy

```bash
cd c-learning
mkdir -p build && cd build
cmake ..
make -j$(nproc)

# Chạy
./bin/ch03_01_hello_world
```

---

## 🪟 Build trên Windows

### Cách 1: MinGW-w64 (Khuyên dùng - giống Linux nhất)

#### Cài đặt

1. **Cài MSYS2** (bao gồm MinGW-w64):
   - Tải từ: https://www.msys2.org/
   - Chạy installer, cài vào `C:\msys64`

2. **Mở MSYS2 UCRT64** từ Start Menu, chạy:
   ```bash
   pacman -Syu
   pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-make
   ```

3. **Thêm vào PATH** (System Environment Variables):
   ```
   C:\msys64\ucrt64\bin
   ```

4. **Khởi động lại** terminal/PowerShell

#### Build

```powershell
cd c-learning
mkdir build
cd build
cmake -G "MinGW Makefiles" ..
mingw32-make

# Chạy
.\bin\ch03_01_hello_world.exe
```

---

### Cách 2: Visual Studio

#### Cài đặt

1. Tải **Visual Studio 2022 Community** (miễn phí):
   https://visualstudio.microsoft.com/

2. Trong installer, chọn:
   - ✅ **Desktop development with C++**
   - ✅ **C++ CMake tools for Windows**

#### Build bằng Command Line

```powershell
# Mở "Developer PowerShell for VS 2022" từ Start Menu
cd c-learning
mkdir build
cd build
cmake ..
cmake --build .

# Chạy
.\bin\Debug\ch03_01_hello_world.exe
```

#### Build bằng Visual Studio IDE

1. Mở Visual Studio
2. **File → Open → CMake...** → chọn thư mục `c-learning`
3. Chờ CMake configure xong
4. **Build → Build All** (hoặc Ctrl+Shift+B)
5. Chọn target và nhấn F5 để chạy

---

### Cách 3: WSL (Windows Subsystem for Linux)

Chạy Linux thật trong Windows - không cần config gì thêm.

#### Cài đặt

```powershell
# PowerShell (Admin)
wsl --install
# Khởi động lại máy, setup Ubuntu user/password
```

#### Build

```bash
# Trong WSL terminal
sudo apt update
sudo apt install build-essential cmake

cd /mnt/c/Users/YourName/c-learning
mkdir -p build && cd build
cmake ..
make

./bin/ch03_01_hello_world
```

---

## 🛠️ Tổng hợp lệnh build

| Hệ điều hành | Generator | Lệnh build |
|--------------|-----------|------------|
| Linux/macOS | Make | `cmake .. && make` |
| Windows MinGW | MinGW Makefiles | `cmake -G "MinGW Makefiles" .. && mingw32-make` |
| Windows MSVC | Visual Studio | `cmake .. && cmake --build .` |
| Windows Ninja | Ninja | `cmake -G Ninja .. && ninja` |

---

## 📝 Thêm Exercise Mới

1. Tạo file `.c` trong thư mục chapter:
   ```
   chapter_03/10_my_exercise.c
   ```

2. Thêm vào `chapter_03/CMakeLists.txt`:
   ```cmake
   set(CHAPTER03_EXERCISES
       # ...
       10_my_exercise
   )
   ```

3. Rebuild:
   ```bash
   # Linux/macOS
   cd build && make
   
   # Windows MinGW
   cd build && mingw32-make
   
   # Windows MSVC
   cd build && cmake --build .
   ```

---

## 🐛 Debug

### Linux - GDB
```bash
gdb ./bin/ch03_01_hello_world
(gdb) break main
(gdb) run
(gdb) next
(gdb) print var
(gdb) quit
```

### Windows - Visual Studio
1. Mở project trong VS
2. Đặt breakpoint (click vào lề trái)
3. Nhấn F5 để debug

### Windows - GDB (MinGW)
```powershell
gdb .\bin\ch03_01_hello_world.exe
```

---

## 🧹 Clean Build

```bash
# Linux/macOS
rm -rf build/*

# Windows PowerShell
Remove-Item -Recurse -Force build\*

# Hoặc đơn giản xóa thư mục build và tạo lại
```

---

## ⚠️ Lưu ý Windows

1. **Line endings**: Git có thể đổi `LF` thành `CRLF`. Thêm vào `.gitattributes`:
   ```
   * text=auto
   *.c text eol=lf
   *.h text eol=lf
   ```

2. **Path quá dài**: Nếu gặp lỗi path, bật long paths:
   ```powershell
   # PowerShell (Admin)
   git config --system core.longpaths true
   ```

3. **Antivirus**: Có thể chậm khi build. Thêm thư mục project vào exclusion list.

---

## 📖 Tài liệu tham khảo

- [CMake Documentation](https://cmake.org/documentation/)
- [MSYS2 Packages](https://packages.msys2.org/)
- [Visual Studio C++ Docs](https://docs.microsoft.com/en-us/cpp/)

Happy coding! 🎉