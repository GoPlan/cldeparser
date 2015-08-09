cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Exceptions)
add_subdirectory(Common)

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
    Parser.h Derivative.cpp Derivative.h)


set(SOURCE_FILES main.cpp CldeParser.h)
add_executable(cldeparser ${SOURCE_FILES} Parser/Derivatives/JsonDerivative.cpp Parser/Derivatives/JsonDerivative.h Parser/JsonEntity.cpp Parser/JsonEntity.h Parser/JsonObject.cpp Parser/JsonObject.h Parser/JsonValue.cpp Parser/JsonValue.h Parser/JsonFactory.cpp Parser/JsonFactory.h)
target_link_libraries(cldeparser foundation common exceptions)