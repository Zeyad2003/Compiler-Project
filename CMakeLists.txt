cmake_minimum_required(VERSION 3.23)
project(Compiler-Project)

set(CMAKE_CXX_STANDARD 20)

add_executable(Compiler-Project main.cpp
        Parser.cpp
        Parser.h
        Lexer.h
        Lexer.cpp
)
