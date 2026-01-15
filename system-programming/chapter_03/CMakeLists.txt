# Chapter 03: The C Programming Language
# Mỗi file .c sẽ tạo ra một executable riêng

# Danh sách các exercises trong chapter này
set(CHAPTER03_EXERCISES
    01_hello_world
)

# Tạo executable cho mỗi exercise
foreach(exercise ${CHAPTER03_EXERCISES})
    # Chỉ tạo nếu file tồn tại
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${exercise}.c")
        add_executable(ch03_${exercise} ${exercise}.c)
        
        # Link với common library
        target_link_libraries(ch03_${exercise} 
            PRIVATE 
                common::common
                source::source    # thêm dòng này
        )
        
        # Thêm math library nếu cần (Linux)
        if(UNIX AND NOT APPLE)
            target_link_libraries(ch03_${exercise} PRIVATE m)
        endif()
    endif()
endforeach()

# ============================================================================
# Custom target để chạy tất cả exercises trong chapter
# Usage: make run_chapter03
# ============================================================================
add_custom_target(run_chapter03
    COMMENT "Running all Chapter 03 exercises..."
)
