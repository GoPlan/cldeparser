

# gtest
include_directories(${EXTRA_DIR}/gtest-1.7.0/include)
link_directories(${EXTRA_DIR}/gtest-1.7.0/build)

# cldeparser-apptest
add_executable(cldeparser-apptest
        ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/JsonParserInstance.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/JsonTestFixture.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Case00_FeatureTest.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Case01_ActualExamples.cpp)

target_link_libraries(cldeparser-apptest gtest cldeparser-static cldeparser-json-static)

# copy testing examples
add_custom_command(
        TARGET cldeparser-apptest POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/test/JsonExamples
        $<TARGET_FILE_DIR:cldeparser-apptest>/JsonExamples)

# Valgrind
enable_testing()
add_test(
        NAME cldeparser-valgrind
        COMMAND valgrind -v --leak-check=summary --show-leak-kinds=all --track-origins=yes ./cldeparser-apptest)