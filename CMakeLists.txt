cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Common)

set(SOURCE_FILES main.cpp)
add_executable(cldeparser ${SOURCE_FILES})
target_link_libraries(cldeparser common parser)