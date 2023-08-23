cmake_minimum_required(VERSION 3.10)
project(cache_simulator)

# All source files
set(SOURCES
    src/main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
