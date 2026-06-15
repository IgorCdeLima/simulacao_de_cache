cmake_minimum_required(VERSION 3.16)
project(consoleApp)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(
    simula_cache
    ./src/main.cpp
    ./src/command_line/commandLine.cpp
    ./src/cache_memory/CacheMemoryConfiguration.cpp
    ./src/cache_memory/CacheMemory.cpp
    ./src/read_file/ReadFile.cpp
    ./src/tools/Tools.cpp
)
target_include_directories(
    simula_cache
    PRIVATE
        ./include/command_line
        ./include/cache_memory
        ./include/read_file
        ./include/tools
        ./include/default_structs
)