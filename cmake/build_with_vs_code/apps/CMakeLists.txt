# Yêu cầu CMake phiên bản 3.11 trở lên để cài đặt GoogleTest sau này
# vì vậy hãy yêu cầu nó ngay bây giờ.
cmake_minimum_required(VERSION 3.11-3.18)

project(main)

add_executable(main main.cpp)
# Chúng ta cần hello.h và thư viện hello
target_link_libraries(main
    PRIVATE hello)

# Yêu cầu trình biên dịch C++ sử dụng các tính năng C++20. 
# Chúng ta không thực sự sử dụng bất kỳ tính năng nào trong số chúng.
target_compile_features(main PUBLIC cxx_std_20)