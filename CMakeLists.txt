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
        src/parsing/IntegerParsingState.h
        src/parsing/IntegerParsingState.cpp
        src/parsing/ParsingInfo.h
        src/parsing/ParsingInfo.cpp
        src/parsing/rules/ParsingRule.cpp
        src/parsing/rules/ParsingRule.h
        src/parsing/text_handling/TextPointer.cpp
        src/parsing/text_handling/TextPointer.h
        src/parsing/rules/ExceptSymbolsParsingRule.cpp
        src/parsing/rules/ExceptSymbolsParsingRule.h
        src/tokens/Atom.cpp src/tokens/Atom.h
        src/parsing/rules/SpanParsingRule.cpp
        src/parsing/rules/SpanParsingRule.h
        src/parsing/rules/StringEqParsingRule.cpp
        src/parsing/rules/StringEqParsingRule.h
        src/parsing/rules/RuleRepeatingParsingRule.cpp
        src/parsing/rules/RuleRepeatingParsingRule.h
        src/parsing/rules/SequentialParsingRule.cpp
        src/parsing/rules/SequentialParsingRule.h
        src/parsing/states/LeftBracketParser.cpp
        src/parsing/states/LeftBracketParser.h
        src/parsing/states/Parser.cpp
        src/parsing/states/Parser.h
        src/parsing/states/RightBracketParser.cpp
        src/parsing/states/RightBracketParser.h
        src/parsing/states/NumberParser.cpp
        src/parsing/states/NumberParser.h
        src/parsing/rules/OrParsingRule.cpp
        src/parsing/rules/OrParsingRule.h src/parsing/states/StringParser.cpp src/parsing/states/StringParser.h)