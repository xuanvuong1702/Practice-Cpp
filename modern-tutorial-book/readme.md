# Modern C++ Learning Project

📚 **Based on**: [Modern C++ Tutorial: C++11/14/17/20 On the Fly](https://github.com/changkun/modern-cpp-tutorial)

A CMake project structure for learning Modern C++ features by following along with the book.

## 📁 Project Structure

```
modern-cpp-learning/
├── CMakeLists.txt              # Root CMake configuration
├── cmake/
│   └── CompilerSettings.cmake  # Cross-platform compiler settings
├── common/                     # Shared utilities
│   ├── include/common/
│   │   └── utils.hpp
│   └── src/
├── chapter01/                  # Chapter 01: Towards Modern C++
├── source/                     #source code
    └── include
    └── src 
```

## 🛠️ Build Instructions

### Prerequisites

- CMake 3.16 or higher
- C++20 compatible compiler:
  - **macOS**: Xcode 12+ or Clang 10+
  - **Windows**: Visual Studio 2019+ or MSVC 19.29+
  - **Linux**: GCC 10+ or Clang 10+

### macOS / Linux

```bash
# Create build directory
mkdir build && cd build

# Configure (Release build)
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build all chapters
cmake --build .

# Or build specific chapter
cmake --build . --target ch01_modern_preview
```

### Windows (Visual Studio)

```powershell
# Create build directory
mkdir build
cd build

# Configure (generates Visual Studio solution)
cmake ..

# Build using Visual Studio or command line
cmake --build . --config Release

# Or open the .sln file in Visual Studio
```

### Windows (MinGW/MSYS2)

```bash
mkdir build && cd build
cmake .. -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release
cmake --build .
```

## 🚀 Running Examples

After building, executables are located in `build/bin/`:

```bash
# Run examples
./build/bin/ch01_modern_preview
./build/bin/ch02_type_inference
./build/bin/ch03_lambda
# ... etc
```

## 📖 Chapter Contents

| Chapter | Topic | Executables |
|---------|-------|-------------|
| 01 | Towards Modern C++ | `ch01_c_cpp_interop`, `ch01_modern_preview` |
| 02 | Language Usability | `ch02_constants`, `ch02_type_inference`, `ch02_variables_init`, `ch02_control_flow`, `ch02_templates`, `ch02_oop_enhancements` |
| 03 | Runtime Enhancements | `ch03_lambda`, `ch03_function_wrapper`, `ch03_move_semantics`, `ch03_perfect_forwarding` |
| 04 | Containers | `ch04_array_forward_list`, `ch04_unordered_containers`, `ch04_tuples` |
| 05 | Smart Pointers | `ch05_smart_pointers` |
| 06 | Regular Expressions | `ch06_regex` |
| 07 | Concurrency | `ch07_threads_mutex`, `ch07_future_async`, `ch07_condition_variable`, `ch07_atomic_memory_model` |
| 08 | File System | `ch08_filesystem` |
| 09 | Minor Features | `ch09_minor_features` |
| 10 | C++20 Preview | `ch10_cpp20_features` |

## 🎯 How to Use

1. **Read a chapter** from the book
2. **Find the corresponding example** in `chapterXX/src/`
3. **Add your code** following the book's examples
4. **Build and run** to test your understanding
5. **Experiment** with variations!

## 💡 Tips

- Use `PRINT_VAR(x)` macro to print variable name and value
- Use `PRINT_VAR_TYPE(x)` to see the deduced type
- Use `mcpp::print_section()` and `mcpp::print_subsection()` for organized output
- Use `mcpp::ScopedTimer` to measure execution time

## 🔧 Customization

### Build Only Specific Chapters

```bash
cmake .. -DBUILD_CHAPTER01=ON -DBUILD_CHAPTER02=ON -DBUILD_CHAPTER03=OFF ...
```

### Change C++ Standard

Edit `CMakeLists.txt` and change:
```cmake
set(CMAKE_CXX_STANDARD 20)  # Change to 17, 14, or 11
```

## 📝 License

This project structure is for educational purposes.
The book "Modern C++ Tutorial" is licensed under CC BY-NC-ND 4.0.
