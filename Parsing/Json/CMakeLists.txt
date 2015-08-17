cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(parser-json STATIC
      Json.h
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
      JsonArray.cpp
      JsonArray.h
      JsonException.cpp
      JsonException.h
      JsonSyntaxNode.cpp
      JsonSyntaxNode.h
      JsonSyntaxModel.cpp
      JsonSyntaxModel.h
      JsonSyntaxModelHelper.cpp
      JsonSyntaxModelHelper.h JsonValueFactory.cpp JsonValueFactory.h)