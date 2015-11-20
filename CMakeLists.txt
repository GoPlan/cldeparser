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
        SOVERSION ${VERSION})

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

# gtest
include_directories(${EXTRA_DIR}/gtest-1.7.0/include)
link_directories(${EXTRA_DIR}/gtest-1.7.0/build)

# cldeparser-apptest
add_executable(cldeparser-apptest
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/JsonParserInstance.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/JsonTestFixture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/Case00_FeatureTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/Case01_ActualExamples.cpp)

target_link_libraries(cldeparser-apptest gtest cldeparser-static)

# copy testing examples
add_custom_command(
        TARGET cldeparser-apptest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Test/JsonExamples
        $<TARGET_FILE_DIR:cldeparser-apptest>/JsonExamples)

# Valgrind
enable_testing()
add_test(
        NAME cldeparser-valgrind
        COMMAND valgrind -v --leak-check=summary --show-leak-kinds=all --track-origins=yes ./cldeparser-apptest)

# Example - json
add_executable(example-json Examples/example-json.cpp)
target_link_libraries(example-json cldeparser-static)

# Example - math
add_executable(example-math Examples/example-math.cpp)
target_link_libraries(example-math cldeparser-static)
