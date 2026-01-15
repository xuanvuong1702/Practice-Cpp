add_chapter_executable(
    NAME run_sample
    CHAPTER 01
    SOURCES src/run_sample.cpp
)

# Link library vào executable
target_link_libraries(ch01_run_sample PRIVATE source common)