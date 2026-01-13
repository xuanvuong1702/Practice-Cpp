# Tự động build tất cả file .cpp trong chapter này
file(GLOB CPP_FILES "*.cpp")

foreach(cpp_file ${CPP_FILES})
    # Lấy tên file
    get_filename_component(exe_name ${cpp_file} NAME_WE)
    
    # Tạo executable
    add_executable(${exe_name} ${cpp_file})
    
    # Link thư viện common vào TẤT CẢ executable
    target_link_libraries(${exe_name} PRIVATE common_lib)
endforeach()