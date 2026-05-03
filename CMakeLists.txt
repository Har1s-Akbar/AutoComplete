cmake_minimum_required(VERSION 3.10)

project(AutocompleteEngine VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES 
    src/main.cpp 
    src/AVLTree.cpp 
    src/AutoComplete.cpp
)

add_executable(AutocompleteApp ${SOURCES})

file(COPY data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})