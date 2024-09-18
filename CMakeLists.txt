cmake_minimum_required(VERSION 3.23)
project(cpp_scheme)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_scheme
        ./src/main.cpp src/parsing/Parser.cpp src/parsing/Parser.h src/parsing/Token.cpp src/parsing/Token.h src/parsing/LispList.cpp src/parsing/LispList.h src/parsing/Symbol.cpp src/parsing/Symbol.h src/parsing/TreeBuilder.cpp src/parsing/TreeBuilder.h src/parsing/AbstractNode.cpp src/parsing/AbstractNode.h src/parsing/LispString.cpp src/parsing/LispString.h src/painters/TreePainter.cpp src/painters/TreePainter.h)