cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(STORAGE /Volumes/External-SSD)
set(EXTRA_DIR "${STORAGE}/Extra")
set(VERSION 1.0.0)
# Note: Extra folder containing supporting libraries such as gtest, gmock, valgrind ... Extra folder is not tracked

# cldeparser public include
include_directories(${CMAKE_SOURCE_DIR})

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Exceptions/ScannerException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Exceptions/ParserException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Exception.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Token.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Tokenizer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/TokenHelper.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/TokenizerFactory.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/TokenType.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Scanner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Parser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/Derivative.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/SyntaxNode.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/SyntaxModel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/cldeparser/ParserSingle.cpp)

file(GLOB_RECURSE SCANNING_SOURCE cldeparser/Scanning/*.cpp)
file(GLOB_RECURSE PARSING_SOURCE cldeparser/Parsing/*.cpp)

set(COMPLETE_SOURCE
        ${SOURCE_FILES}
        ${SCANNING_SOURCE}
        ${PARSING_SOURCE})

# Libraries - shared & static
add_library(cldeparser-static STATIC ${COMPLETE_SOURCE})
add_library(cldeparser SHARED ${COMPLETE_SOURCE})
set_target_properties(cldeparser cldeparser-static PROPERTIES
        VERSION ${VERSION}
        SOVERSION ${VERSION}
)

if (APPLE)
    set_property(TARGET cldeparser PROPERTY PREFIX "lib")
    set_property(TARGET cldeparser PROPERTY SUFFIX ".so")
endif ()

# Installation - cldeparser directory variable has trailing dash to ommit copying itself into the destination
set(INSTALL_DIR "${EXTRA_DIR}")
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR}/${CMAKE_PROJECT_NAME}-${VERSION})

install(FILES LICENSE.txt README.md DESTINATION ./)
install(DIRECTORY cldeparser/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
install(TARGETS cldeparser-static cldeparser
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./)

# cldeparser-json
add_subdirectory(cldeparser-json)

# Libraries - cldeparser-json - shared & static
add_library(cldeparser-json ${CLDEPARSER_JSON_SOURCE_FILES})
add_library(cldeparser-json-static STATIC ${CLDEPARSER_JSON_SOURCE_FILES})
target_link_libraries(cldeparser-json cldeparser-static)
target_link_libraries(cldeparser-json-static cldeparser-static)

# cldeparser-apptest
add_subdirectory(test)
add_subdirectory(examples)
