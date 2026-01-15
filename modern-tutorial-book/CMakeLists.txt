cmake_minimum_required(VERSION 3.16)
project(ModernCppLearning
    VERSION 1.0.0
    DESCRIPTION "Learning Modern C++ (C++11/14/17/20)"
    LANGUAGES CXX
)

# ============================================================================
# Global Settings
# ============================================================================
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Export compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# ============================================================================
# Include CMake Modules
# ============================================================================
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(CompilerSettings)

# ============================================================================
# Common Library (shared utilities across chapters)
# ============================================================================
add_subdirectory(common)
add_subdirectory(source)

# ============================================================================
# Chapters - Enable/Disable as needed
# ============================================================================
option(BUILD_CHAPTER01 "Build Chapter 01: Towards Modern C++" ON)

if(BUILD_CHAPTER01)
    add_subdirectory(chapter01)
endif()


# ============================================================================
# Print Configuration Summary
# ============================================================================
message(STATUS "")
message(STATUS "========== Modern C++ Learning Project ==========")
message(STATUS "CMake version:    ${CMAKE_VERSION}")
message(STATUS "C++ Standard:     ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler:         ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "Build type:       ${CMAKE_BUILD_TYPE}")
message(STATUS "Output directory: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")
message(STATUS "=================================================")
message(STATUS "")
