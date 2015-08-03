cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp )
add_executable(cldejson ${SOURCE_FILES} main.cpp
    Object.cpp
    Object.h
    Value.cpp
    Value.h
    Array.cpp
    Array.h
    ValueType.h
    Tokens/StringToken.cpp
    Tokens/StringToken.h)