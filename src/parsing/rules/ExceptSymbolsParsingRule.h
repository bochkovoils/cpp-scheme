//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_EXCEPTSYMBOLSPARSINGRULE_H
#define CPP_SCHEME_EXCEPTSYMBOLSPARSINGRULE_H

#include "ParsingRule.h"
#include <set>

class ExceptSymbolsParsingRule : public ParsingRule {
private:
    std::set<char>  _break_symbols;
public:
    explicit ExceptSymbolsParsingRule(std::set<char>  break_symbols);
    explicit ExceptSymbolsParsingRule(char const* break_symbols);
    TextPointer try_parse(TextPointer  const& parser ) override;
};


#endif //CPP_SCHEME_EXCEPTSYMBOLSPARSINGRULE_H
