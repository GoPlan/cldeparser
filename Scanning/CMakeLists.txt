cmake_minimum_required(VERSION 3.2)
project(cldeparser)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_library(scanner STATIC
    TokenType.h
    TokenType.cpp
    TokenizerFactory.cpp
    TokenizerFactory.h
    Tokenizers/String.cpp
    Tokenizers/String.h
    Tokenizers/Number.cpp
    Tokenizers/Number.h
    Tokenizers/CurlyBraceOpen.cpp
    Tokenizers/CurlyBraceOpen.h
    Tokenizers/CurlyBraceClosing.cpp
    Tokenizers/CurlyBraceClosing.h
    Tokenizers/Colon.cpp
    Tokenizers/Colon.h
    Tokenizers/Comma.cpp
    Tokenizers/Comma.h
    Tokenizers/BracketOpen.cpp
    Tokenizers/BracketOpen.h
    Tokenizers/BracketClosing.cpp
    Tokenizers/BracketClosing.h
    Tokenizers/SemiColon.cpp
    Tokenizers/SemiColon.h
    Tokenizers/Id.cpp
    Tokenizers/Id.h
    Tokenizers/Space.cpp
    Tokenizers/Space.h
    Tokenizers/Tab.cpp
    Tokenizers/Tab.h
    Tokenizers/ParenthesesOpen.cpp
    Tokenizers/ParenthesesOpen.h
    Tokenizers/ParenthesesClosing.cpp
    Tokenizers/ParenthesesClosing.h Scanning.h Tokenizers/AngleBracketOpen.cpp Tokenizers/AngleBracketOpen.h Tokenizers/AngleBracketClosing.cpp Tokenizers/AngleBracketClosing.h Tokenizers/SquareBracketOpen.cpp Tokenizers/SquareBracketOpen.h Tokenizers/SquareBracketClosing.cpp Tokenizers/SquareBracketClosing.h Tokenizers/ForwardSlash.cpp Tokenizers/ForwardSlash.h Tokenizers/BackwardSlash.cpp Tokenizers/BackwardSlash.h Tokenizers/Adding.cpp Tokenizers/Adding.h Tokenizers/Subtracting.cpp Tokenizers/Subtracting.h Tokenizers/Multiplication.cpp Tokenizers/Multiplication.h Tokenizers/Division.cpp Tokenizers/Division.h)