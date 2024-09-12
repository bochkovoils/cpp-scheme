//
// Created by giantdad on 12.09.24.
//

#include "LeftBracketParser.h"
#include "../rules/StringEqParsingRule.h"
#include "../../tokens/OpenBracket.h"

ParsingRule *LeftBracketParser::parsing_rule() {
    return new StringEqParsingRule("(");
}

Word *LeftBracketParser::parse(TextPointer &left, TextPointer &right) {
    return new OpenBracket();
}
