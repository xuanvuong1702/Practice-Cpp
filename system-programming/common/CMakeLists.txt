# Common utilities library - dùng chung cho tất cả chapters

add_library(common STATIC
    src/utils.c
)

target_include_directories(common
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Alias để sử dụng dễ dàng hơn: common::common
add_library(common::common ALIAS common)
