cmake_minimum_required(VERSION 3.23)
project(cpp_scheme)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_scheme
        ./src/main.cpp src/parsing/Parser.cpp src/parsing/Parser.h src/parsing/Token.cpp src/parsing/Token.h)