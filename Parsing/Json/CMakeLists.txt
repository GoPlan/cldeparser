cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(parser-json STATIC
      JsonDerivative.cpp
      JsonDerivative.h
      JsonEntity.cpp
      JsonEntity.h
      JsonObject.cpp
      JsonObject.h
      JsonValue.cpp
      JsonValue.h
      JsonFactory.cpp
      JsonFactory.h
      JsonDocument.cpp
      JsonDocument.h
      JsonArray.cpp
      JsonArray.h Json.h)