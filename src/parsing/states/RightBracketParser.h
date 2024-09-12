//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_RIGHTBRACKETPARSER_H
#define CPP_SCHEME_RIGHTBRACKETPARSER_H

#include "Parser.h"

class RightBracketParser: public Parser {
public:
    ParsingRule * parsing_rule() override;
    Word* parse(TextPointer& left, TextPointer& right) override;
};


#endif //CPP_SCHEME_RIGHTBRACKETPARSER_H
