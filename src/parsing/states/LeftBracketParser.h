//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_LEFTBRACKETPARSER_H
#define CPP_SCHEME_LEFTBRACKETPARSER_H


#include "Parser.h"

class LeftBracketParser: public Parser {
public:
    Word * parse(TextPointer &left, TextPointer &right) override;
    ParsingRule * parsing_rule() override;
};


#endif //CPP_SCHEME_LEFTBRACKETPARSER_H
