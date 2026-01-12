cmake_minimum_required(VERSION 3.20)

project(modern_cpp_book
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#include(cmake/common.cmake)

# Auto build all cpp files under chapters/
file(GLOB_RECURSE CPP_SOURCES
    CONFIGURE_DEPENDS
    chapters/*.cpp
)

foreach(source_file ${CPP_SOURCES})
    get_filename_component(target_name ${source_file} NAME_WE)

    add_executable(${target_name} ${source_file})
    target_compile_options(${target_name} PRIVATE ${PROJECT_WARNINGS})
endforeach()
