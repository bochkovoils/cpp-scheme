//
// Created by giantdad on 12.09.24.
//

#include "ExceptSymbolsParsingRule.h"

#include <utility>
#include "../ParsingInfo.h"
#include "../../tokens/Atom.h"

ExceptSymbolsParsingRule::ExceptSymbolsParsingRule(std::set<char>  break_symbols): _break_symbols(std::move(break_symbols)) {}

TextPointer ExceptSymbolsParsingRule::try_parse(TextPointer  const& pointer ) {
    std::string result;
    auto forward = TextPointer(pointer);

    while(_break_symbols.count(*forward) == 0) {
//        std::cout << forward.file_position() << std::endl;
//        std::cout << *forward << std::endl;
        std::cout << _break_symbols.size() << std::endl;
        result += *forward;
        forward++;
    }
    return forward;
}

ExceptSymbolsParsingRule::ExceptSymbolsParsingRule(const char *break_symbols) {
    std::set<char> set;
    std::string bs(break_symbols);
    set.insert(bs.begin(), bs.end());
    _break_symbols = set;
}
