cmake_minimum_required(VERSION 3.9)

project(async LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(async SHARED async.cpp async.h bulk.cpp bulk.h logger.cpp logger.h)

add_executable(async_cli main.cpp)

target_link_libraries(async_cli async)
