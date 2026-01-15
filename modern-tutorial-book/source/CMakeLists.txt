add_library(source STATIC
    src/sample.cpp
    # src/another    # thêm file mới ở đây
)

target_include_directories(source
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(source::source ALIAS source)