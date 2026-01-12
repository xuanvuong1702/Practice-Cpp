cmake_minimum_required(VERSION 3.20)

project(modern_cpp_book LANGUAGES CXX C)

# Cấu hình C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Tạo thư viện common từ code trong include/
add_library(common_lib STATIC
    include/CompatibilityWithC.c
    # Thêm các file .cpp/.c khác trong include/ nếu có
)

# Set include directory cho library
target_include_directories(common_lib PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
)

# Add chapters
add_subdirectory(chapters)