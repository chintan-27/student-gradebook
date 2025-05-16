cmake_minimum_required(VERSION 3.15)
project(StudentGradebook)

# Use C++20 standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable all warnings and address sanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2 -g -fsanitize=address -fno-omit-frame-pointer")

# Add the executable and source files
add_executable(gradebook
    src/main.cpp
    src/student.cpp
    src/csv_utils.cpp
)

# Optional: Organize in folders in IDEs like CLion
source_group("Header Files" FILES src/student.hpp src/csv_utils.hpp)
source_group("Source Files" FILES src/main.cpp src/student.cpp src/csv_utils.cpp)