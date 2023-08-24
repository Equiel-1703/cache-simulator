cmake_minimum_required(VERSION 3.10)
project(cache_simulator)

# All header files
include_directories(include)

# All source files
set(SOURCES
    src/main.cpp
    src/CacheSet.cpp
    src/Cache.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
