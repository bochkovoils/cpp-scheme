cmake_minimum_required(VERSION 3.23)
project(cpp_scheme)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_scheme
        ./src/main.cpp
        src/parsing/Parser.cpp
        src/parsing/Parser.h
        src/parsing/Token.cpp
        src/parsing/Token.h
        src/parsing/ElementsList.cpp
        src/parsing/ElementsList.h
        src/parsing/Atom.cpp
        src/parsing/Atom.h
        src/parsing/TreeBuilder.cpp
        src/parsing/TreeBuilder.h
        src/parsing/AbstractNode.cpp
        src/parsing/AbstractNode.h
        src/painters/TreePainter.cpp
        src/painters/TreePainter.h
        src/lisp_structures/LispObject.cpp
        src/lisp_structures/LispObject.h
        src/lisp_structures/LispList.cpp
        src/lisp_structures/LispList.h
        src/lisp_structures/LispSymbol.cpp
        src/lisp_structures/LispSymbol.h
        src/lisp_structures/LispNumber.cpp
        src/lisp_structures/LispNumber.h
        src/lisp_structures/LispString.cpp
        src/lisp_structures/LispString.h
        src/lisp_structures/LispCell.cpp
        src/lisp_structures/LispCell.h
        src/lisp_structures/LispNull.cpp
        src/lisp_structures/LispNull.h src/environment/Frame.cpp src/environment/Frame.h)