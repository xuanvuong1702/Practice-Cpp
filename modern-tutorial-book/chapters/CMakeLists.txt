# Tự động thêm tất cả các chapter
file(GLOB CHAPTER_DIRS "chapter*")

foreach(chapter_dir ${CHAPTER_DIRS})
    if(IS_DIRECTORY ${chapter_dir})
        get_filename_component(chapter_name ${chapter_dir} NAME)
        add_subdirectory(${chapter_name})
    endif()
endforeach()