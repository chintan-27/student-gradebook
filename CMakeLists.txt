cmake_minimum_required(VERSION 3.15)
project(StudentGradebook)

# C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/student.cpp
    src/csv_utils.cpp
)

# Create executable
add_executable(gradebook ${SOURCES})

# Platform/compiler-specific flags
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(gradebook PRIVATE
        -Wall
        -Wextra
        -g
        -O2
        -fsanitize=address
        -fno-omit-frame-pointer
    )
    target_link_options(gradebook PRIVATE
        -fsanitize=address
    )
elseif (MSVC)
    target_compile_options(gradebook PRIVATE /W4 /Zi)
endif()

# Optional: Enable compile_commands.json for tooling
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
