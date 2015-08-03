cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(json STATIC
    Tokenizers/String.cpp
    Tokenizers/String.h
    TokenType.h
    Tokenizers/Number.cpp Tokenizers/Number.h)