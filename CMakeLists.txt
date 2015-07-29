cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Foundation)
add_subdirectory(Scanner)
add_subdirectory(Parser)

set(SOURCE_FILES main.cpp)
add_executable(cldeparser ${SOURCE_FILES}
    Scanner.cpp
    Scanner.h
    Word.cpp
    Word.h)

target_link_libraries(cldeparser)