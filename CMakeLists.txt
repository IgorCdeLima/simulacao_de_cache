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
    ./src/reader_arquive/ReaderArquive.cpp
    ./src/tools/Tools.cpp
    ./src/substituition_policy/PolicyLRU.cpp
    ./src/substituition_policy/PolicyRandom.cpp
    ./src/write_policy/WriteBack.cpp
    ./src/write_policy/WriteThrough.cpp
)

target_include_directories(
    simula_cache
    PRIVATE
        ./include/command_line
        ./include/cache_memory
        ./include/reader_arquive
        ./include/tools
        ./include/default_structs
        ./include/interfaces
        ./include/substituition_policy
        ./include/write_policy
)