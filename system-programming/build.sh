#!/bin/bash
# build.sh - Script build tiện lợi cho C Learning Project

set -e  # Exit on error

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Project root directory
PROJECT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
BUILD_DIR="${PROJECT_DIR}/build"

# Functions
print_header() {
    echo -e "${GREEN}===================================${NC}"
    echo -e "${GREEN}  $1${NC}"
    echo -e "${GREEN}===================================${NC}"
}

print_info() {
    echo -e "${YELLOW}[INFO]${NC} $1"
}

print_error() {
    echo -e "${RED}[ERROR]${NC} $1"
}

# Show help
show_help() {
    echo "Usage: ./build.sh [command]"
    echo ""
    echo "Commands:"
    echo "  build       Build the project (default)"
    echo "  clean       Remove build directory"
    echo "  rebuild     Clean and build"
    echo "  debug       Build with debug symbols"
    echo "  release     Build with optimizations"
    echo "  run NAME    Run a specific exercise (e.g., run ch03_01_hello_world)"
    echo "  list        List all available exercises"
    echo "  help        Show this help"
    echo ""
}

# Build project
do_build() {
    local build_type="${1:-Debug}"
    
    print_header "Building C Learning Project"
    print_info "Build type: $build_type"
    
    mkdir -p "$BUILD_DIR"
    cd "$BUILD_DIR"
    
    cmake -DCMAKE_BUILD_TYPE="$build_type" ..
    make -j$(nproc 2>/dev/null || echo 4)
    
    print_info "Build complete! Executables in: ${BUILD_DIR}/bin/"
}

# Clean build
do_clean() {
    print_header "Cleaning Build"
    
    if [ -d "$BUILD_DIR" ]; then
        rm -rf "$BUILD_DIR"
        print_info "Build directory removed"
    else
        print_info "Nothing to clean"
    fi
}

# Run exercise
do_run() {
    local exercise="$1"
    local exe_path="${BUILD_DIR}/bin/${exercise}"
    
    if [ -z "$exercise" ]; then
        print_error "Please specify exercise name"
        echo "Usage: ./build.sh run ch03_01_hello_world"
        exit 1
    fi
    
    if [ ! -f "$exe_path" ]; then
        print_error "Exercise not found: $exercise"
        print_info "Run './build.sh list' to see available exercises"
        exit 1
    fi
    
    print_header "Running: $exercise"
    echo ""
    "$exe_path"
}

# List exercises
do_list() {
    print_header "Available Exercises"
    
    if [ -d "${BUILD_DIR}/bin" ]; then
        for exe in "${BUILD_DIR}/bin"/*; do
            if [ -x "$exe" ]; then
                echo "  $(basename "$exe")"
            fi
        done
    else
        print_info "Project not built yet. Run './build.sh build' first."
    fi
}

# Main
case "${1:-build}" in
    build)
        do_build "Debug"
        ;;
    debug)
        do_build "Debug"
        ;;
    release)
        do_build "Release"
        ;;
    clean)
        do_clean
        ;;
    rebuild)
        do_clean
        do_build "Debug"
        ;;
    run)
        do_run "$2"
        ;;
    list)
        do_list
        ;;
    help|--help|-h)
        show_help
        ;;
    *)
        print_error "Unknown command: $1"
        show_help
        exit 1
        ;;
esac
