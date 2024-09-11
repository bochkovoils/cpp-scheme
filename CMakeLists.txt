cmake_minimum_required(VERSION 3.23)
project(cpp_scheme)

set(CMAKE_CXX_STANDARD 17)

add_executable(cpp_scheme
        ./src/main.cpp
        src/tokens/Word.h
        src/tokens/Number.h
        src/tokens/TokensInfo.h
        src/tokens/OpenBracket.h
        src/tokens/Number.cpp
        src/parsing/ParsingState.h
        src/parsing/OpenBracketParsingState.h
        src/parsing/OpenBracketParsingState.cpp
        src/parsing/DefaultParsingState.h
        src/parsing/DefaultParsingState.cpp
        src/parsing/EofState.h
        src/parsing/CloseBracketParsingState.h
        src/parsing/CloseBracketParsingState.cpp
        src/tokens/CloseBracket.h
        src/parsing/IntegerParsingState.h src/parsing/IntegerParsingState.cpp src/parsing/ParsingControl.h src/parsing/ParsingControl.cpp)