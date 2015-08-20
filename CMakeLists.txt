cmake_minimum_required(VERSION 3.2)
project(cldeparser)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_subdirectory(Exceptions)
add_subdirectory(Scanning)
add_subdirectory(Parsing)
add_subdirectory(Parsing/Json)


set(SOURCE_FILES
        Common/IPrintable.h
        Common/IPrintFormatter.h
        Common/IComparable.h
        CldeParser.h
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
        SyntaxModel.cpp
        SyntaxModel.h
        CldeParserFactory.cpp
        CldeParserFactory.h
        ParserSingle.cpp
        ParserSingle.h
)


# Libraries - shared & static
add_library(${CMAKE_PROJECT_NAME}-static STATIC ${SOURCE_FILES})
add_library(${CMAKE_PROJECT_NAME}-shared SHARED ${SOURCE_FILES})

if (APPLE)
    set_property(TARGET ${CMAKE_PROJECT_NAME}-shared PROPERTY PREFIX "lib")
    set_property(TARGET ${CMAKE_PROJECT_NAME}-shared PROPERTY OUTPUT_NAME "${CMAKE_PROJECT_NAME}.so")
    set_property(TARGET ${CMAKE_PROJECT_NAME}-shared PROPERTY SUFFIX "")
    set_property(TARGET ${CMAKE_PROJECT_NAME}-shared PROPERTY SOVERSION "0.7.0")
endif ()

target_link_libraries(${CMAKE_PROJECT_NAME}-static scanner parser parser-json exceptions)
target_link_libraries(${CMAKE_PROJECT_NAME}-shared scanner parser parser-json exceptions)


# Example - json
add_executable(example-json Examples/example-json.cpp)
target_link_libraries(example-json cldeparser-static)

# Example - math
add_executable(example-math Examples/example-math.cpp)
target_link_libraries(example-math cldeparser-static)