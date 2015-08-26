
set(TEST_SOURCE
        main.cpp
        Case00_FeatureTest.hpp
        JsonParserInstance.cpp
        JsonParserInstance.h
        JsonTestFixture.cpp
        JsonTestFixture.h
)

include_directories(${EXTRA_DIR}/gtest-1.7.0/include)
link_directories(${EXTRA_DIR}/gtest-1.7.0/lib)


# Targets
add_executable(cldeparser-apptest ${TEST_SOURCE})
target_link_libraries(cldeparser-apptest gtest cldeparser-static)