cmake_minimum_required(VERSION 3.2)
project(cldeparser)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


add_subdirectory(Source/Exceptions)
add_subdirectory(Source/Scanning)
add_subdirectory(Source/Parsing)
add_subdirectory(Source/Parsing/Json)
add_subdirectory(Test)


set(SOURCE_FILES
        Source/Common/IDefines.h
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
        Source/ParserSingle.cpp
        Source/ParserSingle.h
)


# Libraries - shared & static
add_library(cldeparser-static STATIC ${SOURCE_FILES})
add_library(cldeparser SHARED ${SOURCE_FILES})

if (APPLE)
    set_property(TARGET cldeparser PROPERTY PREFIX "lib")
    set_property(TARGET cldeparser PROPERTY SUFFIX ".so")
    set_property(TARGET cldeparser PROPERTY SOVERSION "0.7.0")
endif ()

target_link_libraries(cldeparser-static scanner parser parser-json exceptions)
target_link_libraries(cldeparser scanner parser parser-json exceptions)


# Example - json
add_executable(example-json Examples/example-json.cpp)
target_link_libraries(example-json cldeparser-static)

# Example - math
add_executable(example-math Examples/example-math.cpp)
target_link_libraries(example-math cldeparser-static)


# Install - Source directory variable has trailing dash to ommit copying itself into the destination
install(FILES LICENSE.txt README.md DESTINATION ./)
install(DIRECTORY Source/ DESTINATION include FILES_MATCHING PATTERN "*.h")
install(TARGETS cldeparser-static cldeparser
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./)


# Extra folder (containing supporting libraries such as gtest, gmock, valgrind ... Extra folder is not tracked)
set(EXTRA_DIR "Extra")
set(TEST_SOURCE
        Test/main.cpp
        Test/Case00_FeatureTest.hpp
        Test/JsonParserInstance.cpp
        Test/JsonParserInstance.h
        Test/JsonTestFixture.cpp
        Test/JsonTestFixture.h
)

include_directories(${EXTRA_DIR}/gtest-1.7.0/include)
LINK_DIRECTORIES(${EXTRA_DIR}/gtest-1.7.0/lib)

# Targets
add_executable(cldeparser-apptest ${TEST_SOURCE})
target_link_libraries(cldeparser-apptest gtest cldeparser-static)