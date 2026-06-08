cmake_minimum_required(VERSION 3.16)
project(consoleApp)
set(CMAKE_CXX_STANDARD 17)
add_executable(
    simula_cache
    ./src/main.cpp
    ./src/command_line/commandLine.cpp
)
target_include_directories(
    simula_cache
    PRIVATE
        ./include/command_line
)