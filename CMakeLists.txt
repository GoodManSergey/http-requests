cmake_minimum_required(VERSION 3.8)

project(http_requests)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*/*.cpp src/*/*/*.cpp)
add_executable(http_requests ${SOURCE_FILES})
target_compile_options(http_requests PUBLIC -std=c++17)
