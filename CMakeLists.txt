cmake_minimum_required(VERSION 3.10)

project(elfdump)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_SOURCE_DIR})

set(SOURCE_FILES
    "main.cpp"
    "ElfHeader.cpp")

add_executable(elfdump ${SOURCE_FILES})
