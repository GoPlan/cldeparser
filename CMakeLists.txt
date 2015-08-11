cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_subdirectory(Exceptions)
add_subdirectory(Scanning)
add_subdirectory(Parsing/Json)
add_subdirectory(Parsing/SimpleMath)


add_library(foundation STATIC
    Core/IPrintable.h
    Core/IPrintFormatter.h
    Core/IComparable.h
    Token.cpp
    Token.h
    Tokenizer.cpp
    Tokenizer.h
    Scanner.cpp
    Scanner.h
    Parser.cpp
    Parser.h
    Derivative.cpp
    Derivative.h
    SyntaxNode.cpp
    SyntaxNode.h
    SyntaxTree.cpp
    SyntaxTree.h)


set(SOURCE_FILES main.cpp CldeParser.h)
add_executable(cldeparser ${SOURCE_FILES})
target_link_libraries(cldeparser foundation scanner parser-json exceptions)


add_executable(example01 Examples/example01.cpp)
target_link_libraries(example01 foundation scanner exceptions)