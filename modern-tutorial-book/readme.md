````markdown
## 🛠️ Hướng dẫn Build Project (Windows – CMake + Ninja + MSVC)

### 1. Yêu cầu môi trường

Đảm bảo máy đã cài các công cụ sau:

- Windows 10/11  
- Visual Studio Community 2022  
  - Chọn workload: **Desktop development with C++**
- CMake (>= 3.20)
- Ninja
- VS Code (khuyến nghị)
  - Extensions:
    - CMake Tools
    - C/C++

Kiểm tra nhanh trong terminal:

```bash
cmake --version
ninja --version
cl
````

---

### 2. Cấu trúc thư mục project

```text
modern-tutorial-book/
├── .vscode/
│   └── settings.json
├── build/                # Thư mục build (sinh ra sau)
├── chapters/
│   └── chapter01/
│       ├── sample.cpp
│       └── DeprecateFeature.cpp
├── include/
├── cmake/
├── CMakeLists.txt
└── .clang-format
```

---

### 3. Cấu hình VS Code (khuyến nghị)

File `.vscode/settings.json`:

```json
{
  "C_Cpp.default.configurationProvider": "ms-vscode.cmake-tools",
  "cmake.configureOnOpen": true,
  "editor.formatOnSave": true
}
```

---

### 4. Cấu hình project bằng CMake

Tại thư mục root của project, chạy:

```bash
cmake -B build -G Ninja ^
  -DCMAKE_BUILD_TYPE=Debug ^
  -DCMAKE_EXPORT_COMPILE_COMMANDS:BOOL=TRUE
```

Kết quả:

* Tạo thư mục `build/`
* Sinh file `compile_commands.json`
* Chuẩn bị file build cho Ninja

---

### 5. Build project

```bash
cmake --build build --config Debug
```

Hoặc build toàn bộ target:

```bash
cmake --build build --target all
```

Sau khi build thành công, file executable sẽ nằm tại:

```text
build/sample.exe
```

---

### 6. Chạy chương trình

```bash
.\build\sample.exe
```

---

### 7. Lưu ý quan trọng

* `allclear` **không phải target hợp lệ** của Ninja
  → sẽ báo lỗi:

  ```text
  ninja: error: unknown target 'allclear'
  ```

* Nếu muốn **clean build**, dùng:

  ```bash
  cmake --build build --target clean
  ```

  hoặc xóa thư mục `build/` rồi cấu hình lại.

---

### 8. Build lại từ đầu (Clean Build)

```bash
rmdir /s /q build
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

---

### 9. Ghi chú thêm

* Compiler sử dụng: MSVC (cl.exe)
* Generator: Ninja
* Phù hợp cho C++ hiện đại, embedded, automotive, UAV

```
```
