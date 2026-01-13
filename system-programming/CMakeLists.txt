cmake_minimum_required(VERSION 3.16)
project(system_programming LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wpedantic)

include_directories(${PROJECT_SOURCE_DIR}/include)

# ===== Library chứa toàn bộ code theo chương =====
file(GLOB_RECURSE BOOK_SOURCES
    src/**/*.c
)

add_library(book STATIC ${BOOK_SOURCES})

# ===== Auto-generate executables for all chapters =====
file(GLOB_RECURSE CHAPTER_RUN_SOURCES
    chapters/**/*.c
)

foreach(chapter_src ${CHAPTER_RUN_SOURCES})
    get_filename_component(chapter_name ${chapter_src} NAME_WE)

    add_executable(${chapter_name} ${chapter_src})
    target_link_libraries(${chapter_name} PRIVATE book)
endforeach()
