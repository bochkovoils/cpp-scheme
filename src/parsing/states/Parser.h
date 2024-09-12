//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_PARSER_H
#define CPP_SCHEME_PARSER_H


#include "../rules/ParsingRule.h"
#include "../../tokens/Word.h"

class Parser {
public:
    virtual ParsingRule* parsing_rule()=0;
    virtual Word* parse(TextPointer& left, TextPointer& right)=0;

};


#endif //CPP_SCHEME_PARSER_H
