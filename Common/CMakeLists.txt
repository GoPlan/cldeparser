cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(common STATIC
    TokenType.h
    Tokenizers/String.cpp
    Tokenizers/String.h
    Tokenizers/Number.cpp
    Tokenizers/Number.h
    Tokenizers/BraceOpen.cpp
    Tokenizers/BraceOpen.h
    Tokenizers/BraceClose.cpp
    Tokenizers/BraceClose.h
    Tokenizers/Colon.cpp
    Tokenizers/Colon.h
    Tokenizers/Comma.cpp
    Tokenizers/Comma.h
    Tokenizers/BracketOpen.cpp
    Tokenizers/BracketOpen.h
    Tokenizers/BracketClose.cpp
    Tokenizers/BracketClose.h
    Tokenizers/SemiColon.cpp
    Tokenizers/SemiColon.h
    Tokenizers/Id.cpp
    Tokenizers/Id.h
    TokenizerFactory.cpp
    TokenizerFactory.h TokenType.cpp Tokenizers/Space.cpp Tokenizers/Space.h Tokenizers/Tab.cpp Tokenizers/Tab.h Tokenizers/ParenthesesOpen.cpp Tokenizers/ParenthesesOpen.h Tokenizers/ParenthesesClose.cpp Tokenizers/ParenthesesClose.h)