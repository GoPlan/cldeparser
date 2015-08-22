cmake_minimum_required(VERSION 3.2)
project(cldeparser)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_subdirectory(Source/Exceptions)
add_subdirectory(Source/Scanning)
add_subdirectory(Source/Parsing)
add_subdirectory(Source/Parsing/Json)


set(SOURCE_FILES
        Source/Common/IPrintable.h
        Source/Common/IPrintFormatter.h
        Source/Common/IComparable.h
        Source/CldeParser.h
        Source/Token.cpp
        Source/Token.h
        Source/Tokenizer.cpp
        Source/Tokenizer.h
        Source/Scanner.cpp
        Source/Scanner.h
        Source/Parser.cpp
        Source/Parser.h
        Source/Derivative.cpp
        Source/Derivative.h
        Source/SyntaxNode.cpp
        Source/SyntaxNode.h
        Source/SyntaxModel.cpp
        Source/SyntaxModel.h
        Source/CldeParserFactory.cpp
        Source/CldeParserFactory.h
        Source/ParserSingle.cpp
        Source/ParserSingle.h
)


# Libraries - shared & static
add_library(${CMAKE_PROJECT_NAME}-static STATIC ${SOURCE_FILES})
add_library(${CMAKE_PROJECT_NAME} SHARED ${SOURCE_FILES})

if (APPLE)
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY PREFIX "lib")
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY SUFFIX "")
    set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY SOVERSION "0.7.0")
endif ()

target_link_libraries(${CMAKE_PROJECT_NAME}-static scanner parser parser-json exceptions)
target_link_libraries(${CMAKE_PROJECT_NAME} scanner parser parser-json exceptions)


# Example - json
add_executable(example-json Examples/example-json.cpp)
target_link_libraries(example-json cldeparser-static)


# Example - math
add_executable(example-math Examples/example-math.cpp)
target_link_libraries(example-math cldeparser-static)


# Install - Source directory variable has trailing dash to ommit copying itself into the destination
install(DIRECTORY Source/ DESTINATION include
        FILES_MATCHING PATTERN "*.h"
)

install(TARGETS ${CMAKE_PROJECT_NAME}-static ${CMAKE_PROJECT_NAME}
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./
)
