
# Example - json
add_executable(example-json example-json.cpp)
target_link_libraries(example-json cldeparser-static cldeparser-json-static)

# Example - math
add_executable(example-math example-math.cpp)
target_link_libraries(example-math cldeparser-static cldeparser-json-static)