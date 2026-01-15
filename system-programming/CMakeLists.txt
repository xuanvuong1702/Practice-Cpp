cmake_minimum_required(VERSION 3.16)
project(CLearning 
    VERSION 1.0.0
    DESCRIPTION "Learning C Programming - Practice Project"
    LANGUAGES C
)

# ============================================================================
# Compiler Settings
# ============================================================================
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Compiler warnings - giúp phát hiện lỗi sớm
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    add_compile_options(
        -Wall           # Bật hầu hết warnings
        -Wextra         # Warnings bổ sung
        -Wpedantic      # Tuân thủ chuẩn C nghiêm ngặt
        -Werror=return-type  # Lỗi nếu thiếu return
    )
endif()

# Debug build mặc định (để dễ debug với gdb)
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# ============================================================================
# Output Directories - Tổ chức file build gọn gàng
# ============================================================================
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ============================================================================
# Common Library - Code dùng chung giữa các chapters
# ============================================================================
add_subdirectory(common)
add_subdirectory(source)

# ============================================================================
# Chapters - Thêm chapter mới vào đây
# ============================================================================
add_subdirectory(chapter_03)
# add_subdirectory(chapter_04)  # Uncomment khi học chapter mới
# add_subdirectory(chapter_05)

# ============================================================================
# Print Configuration Summary
# ============================================================================
message(STATUS "")
message(STATUS "========== Build Configuration ==========")
message(STATUS "  Project:        ${PROJECT_NAME}")
message(STATUS "  Version:        ${PROJECT_VERSION}")
message(STATUS "  C Compiler:     ${CMAKE_C_COMPILER_ID} ${CMAKE_C_COMPILER_VERSION}")
message(STATUS "  Build Type:     ${CMAKE_BUILD_TYPE}")
message(STATUS "  Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "=========================================")
message(STATUS "")
