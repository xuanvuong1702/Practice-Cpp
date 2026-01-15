# ============================================================================
# Common Library - Shared utilities across all chapters
# ============================================================================

add_library(common STATIC
    src/utils.cpp
)

target_include_directories(common
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

set_target_properties(common PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

# Link threading library
target_link_libraries(common PUBLIC Threads::Threads)
