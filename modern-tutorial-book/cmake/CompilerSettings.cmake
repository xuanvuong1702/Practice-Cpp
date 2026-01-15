# ============================================================================
# CompilerSettings.cmake
# Cross-platform compiler settings for Windows (MSVC) and macOS/Linux (Clang/GCC)
# ============================================================================

# Helper function to set up compiler warnings and flags for a target
function(set_project_warnings target_name)
    set(MSVC_WARNINGS
        /W4             # Baseline reasonable warnings
        /w14242         # 'identifier': conversion from 'type1' to 'type2', possible loss of data
        /w14254         # 'operator': conversion from 'type1' to 'type2', possible loss of data
        /w14263         # 'function': member function does not override any base class virtual function
        /w14265         # 'classname': class has virtual functions, but destructor is not virtual
        /w14287         # 'operator': unsigned/negative constant mismatch
        /we4289         # nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the for-loop scope
        /w14296         # 'operator': expression is always 'boolean_value'
        /w14311         # 'variable': pointer truncation from 'type1' to 'type2'
        /w14545         # expression before comma evaluates to a function which is missing an argument list
        /w14546         # function call before comma missing argument list
        /w14547         # 'operator': operator before comma has no effect; expected operator with side-effect
        /w14549         # 'operator': operator before comma has no effect; did you intend 'operator'?
        /w14555         # expression has no effect; expected expression with side-effect
        /w14619         # pragma warning: there is no warning number 'number'
        /w14640         # 'instance': construction of local static object is not thread-safe
        /w14826         # Conversion from 'type1' to 'type2' is sign-extended
        /w14905         # wide string literal cast to 'LPSTR'
        /w14906         # string literal cast to 'LPWSTR'
        /w14928         # illegal copy-initialization; more than one user-defined conversion has been implicitly applied
        /permissive-    # standards conformance mode
    )

    set(CLANG_WARNINGS
        -Wall
        -Wextra                 # reasonable and standard
        -Wshadow                # warn if a variable declaration shadows one from a parent context
        -Wnon-virtual-dtor      # warn if a class with virtual functions has a non-virtual destructor
        -Wold-style-cast        # warn for c-style casts
        -Wcast-align            # warn for potential performance problem casts
        -Wunused                # warn on anything being unused
        -Woverloaded-virtual    # warn if you overload (not override) a virtual function
        -Wpedantic              # warn if non-standard C++ is used
        -Wconversion            # warn on type conversions that may lose data
        -Wsign-conversion       # warn on sign conversions
        -Wnull-dereference      # warn if a null dereference is detected
        -Wdouble-promotion      # warn if float is implicit promoted to double
        -Wformat=2              # warn on security issues around functions that format output
    )

    set(GCC_WARNINGS
        ${CLANG_WARNINGS}
        -Wmisleading-indentation    # warn if indentation implies blocks where blocks do not exist
        -Wduplicated-cond           # warn if if / else chain has duplicated conditions
        -Wduplicated-branches       # warn if if / else branches have duplicated code
        -Wlogical-op                # warn about logical operations being used where bitwise were probably wanted
        -Wuseless-cast              # warn if you perform a cast to the same type
    )

    if(MSVC)
        set(PROJECT_WARNINGS ${MSVC_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
        set(PROJECT_WARNINGS ${CLANG_WARNINGS})
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        set(PROJECT_WARNINGS ${GCC_WARNINGS})
    else()
        message(AUTHOR_WARNING "No compiler warnings set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
    endif()

    target_compile_options(${target_name} PRIVATE ${PROJECT_WARNINGS})
endfunction()

# ============================================================================
# Platform-specific settings
# ============================================================================

# Enable threading support
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# macOS specific
if(APPLE)
    # Use libc++ on macOS
    add_compile_options(-stdlib=libc++)
    add_link_options(-stdlib=libc++)
endif()

# Windows specific  
if(WIN32)
    # Prevent Windows.h from defining min/max macros
    add_definitions(-DNOMINMAX)
    # Use Unicode
    add_definitions(-DUNICODE -D_UNICODE)
    # Disable warnings about "unsafe" functions
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

# ============================================================================
# Helper function to create chapter executables easily
# ============================================================================
function(add_chapter_executable)
    set(options "")
    set(oneValueArgs NAME CHAPTER)
    set(multiValueArgs SOURCES LIBS)
    cmake_parse_arguments(ARG "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})
    
    # Create executable name: ch01_example_name
    set(EXEC_NAME "ch${ARG_CHAPTER}_${ARG_NAME}")
    
    add_executable(${EXEC_NAME} ${ARG_SOURCES})
    
    # Apply compiler warnings
    set_project_warnings(${EXEC_NAME})
    
    # Link common library by default
    target_link_libraries(${EXEC_NAME} PRIVATE common)
    
    # Link additional libraries if specified
    if(ARG_LIBS)
        target_link_libraries(${EXEC_NAME} PRIVATE ${ARG_LIBS})
    endif()
    
    # Set target properties
    set_target_properties(${EXEC_NAME} PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED ON
    )
endfunction()
