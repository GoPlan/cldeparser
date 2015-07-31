cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Common)
add_subdirectory(Scanner)
add_subdirectory(Parser)
add_subdirectory(Json)

add_library(foundation STATIC
    Common/IPrintable.h
    Common/IPrintFormatter.h
    Scanner.cpp
    Scanner.h
    Token.cpp
    Token.h
    State.cpp
    State.h)


set(SOURCE_FILES main.cpp CldeParser.h)
add_executable(cldeparser ${SOURCE_FILES} Common/IComparable.h)
target_link_libraries(cldeparser foundation)