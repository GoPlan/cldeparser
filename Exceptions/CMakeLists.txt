cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(exceptions STATIC
      ScannerException.cpp
      ScannerException.h
      ParserException.cpp
      ParserException.h
      Exception.cpp
      Exception.h)