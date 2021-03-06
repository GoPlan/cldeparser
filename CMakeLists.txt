cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(STORAGE /Volumes/External-SSD)
set(EXTRA_DIR "${STORAGE}/Extra")
set(VERSION 1.0.0)
# Note: Extra folder containing supporting libraries such as gtest, gmock, valgrind ... Extra folder is not tracked

set(SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/IDefines.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/IPrintable.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/IPrintFormatter.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Common/IComparable.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exceptions/Exception.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exceptions/Exception.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exceptions/ScannerException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exceptions/ScannerException.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exceptions/ParserException.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Exceptions/ParserException.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/CldeParser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Token.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Token.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Tokenizer.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Tokenizer.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Scanner.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Scanner.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Parser.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Parser.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Derivative.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Derivative.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/SyntaxNode.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/SyntaxNode.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/SyntaxModel.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/SyntaxModel.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ParserSingle.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/ParserSingle.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Version.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Source/Version.cpp
)

file(GLOB_RECURSE SCANNING_SOURCE Source/Scanning/*.cpp Source/Scanning/*.h)
file(GLOB_RECURSE PARSING_SOURCE Source/Parsing/*.cpp Source/Parsing/*.h)

set(COMPLETE_SOURCE
        ${SOURCE_FILES}
        ${SCANNING_SOURCE}
        ${PARSING_SOURCE}
)


# Libraries - shared & static
add_library(cldeparser-static STATIC ${COMPLETE_SOURCE})
add_library(cldeparser SHARED ${COMPLETE_SOURCE})
set_target_properties(cldeparser cldeparser-static PROPERTIES
        VERSION ${VERSION}
        SOVERSION ${VERSION}
        POSITION_INDEPENDENT_CODE True
)

if (APPLE)
    set_property(TARGET cldeparser PROPERTY PREFIX "lib")
    set_property(TARGET cldeparser PROPERTY SUFFIX ".so")
endif ()


# Example - json
add_executable(example-json Examples/example-json.cpp)
target_link_libraries(example-json cldeparser-static)

# Example - math
add_executable(example-math Examples/example-math.cpp)
target_link_libraries(example-math cldeparser-static)


# Installation - Source directory variable has trailing dash to ommit copying itself into the destination
set(INSTALL_DIR "${EXTRA_DIR}")
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR}/${CMAKE_PROJECT_NAME}-${VERSION})

install(FILES LICENSE.txt README.md DESTINATION ./)
install(DIRECTORY Source/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
install(TARGETS cldeparser-static cldeparser
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./
)

# gtest
include_directories(${EXTRA_DIR}/gtest-1.7.0/include)
link_directories(${EXTRA_DIR}/gtest-1.7.0/build)

# AppTest
add_library(apptest-lib STATIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/Case00_FeatureTest.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/Case01_ActualExamples.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/JsonParserInstance.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/JsonParserInstance.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/JsonTestFixture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Test/JsonTestFixture.h
)

# find cldeparser-static
add_executable(cldeparser-apptest Test/main.cpp)
target_link_libraries(cldeparser-apptest gtest apptest-lib cldeparser-static)

# copy testing examples
add_custom_command(
        TARGET cldeparser-apptest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Test/JsonExamples
        $<TARGET_FILE_DIR:cldeparser-apptest>/JsonExamples
)

# Enable Valgrind
enable_testing()
add_test(
        NAME cldeparser-valgrind
        COMMAND valgrind -v --leak-check=summary --show-leak-kinds=all --track-origins=yes ./cldeparser-apptest
)

