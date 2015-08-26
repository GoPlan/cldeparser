cmake_minimum_required(VERSION 3.2)
project(cldeparser)


set(VERSION 0.9.0)
set(EXTRA_DIR "${CMAKE_SOURCE_DIR}/Extra")
set(INSTALL_DIR "${EXTRA_DIR}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR}/${CMAKE_PROJECT_NAME}-${VERSION})

# Note: Extra folder (containing supporting libraries such as gtest, gmock, valgrind ... Extra folder is not tracked)


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
target_link_libraries(cldeparser-static scanner parser parser-json exceptions)
target_link_libraries(cldeparser scanner parser parser-json exceptions)
set_target_properties(cldeparser cldeparser-static PROPERTIES VERSION ${VERSION} SOVERSION ${VERSION})

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
install(FILES LICENSE.txt README.md DESTINATION ./)
install(DIRECTORY Source/ DESTINATION include/${CMAKE_PROJECT_NAME} FILES_MATCHING PATTERN "*.h")
install(TARGETS cldeparser-static cldeparser
        LIBRARY DESTINATION ./
        ARCHIVE DESTINATION ./)

