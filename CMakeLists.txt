# 1. Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# 2. Project name and version
project(AutocompleteEngine VERSION 1.0)

# 3. Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 4. Include the directory where your .hpp files live
include_directories(include)

# 5. Gather all your source files
# This tells CMake which files need to be compiled together
set(SOURCES 
    src/main.cpp 
    src/AVLTree.cpp 
    src/AutoComplete.cpp
)

# 6. Create the executable
add_executable(AutocompleteApp ${SOURCES})

# 7. Optional: Copy the data folder to the build directory 
# This ensures your program can find "words.txt" easily
file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})