//
// Created by giantdad on 12.09.24.
//

#include "RightBracketParser.h"
#include "../rules/StringEqParsingRule.h"
#include "../../tokens/CloseBracket.h"

ParsingRule *RightBracketParser::parsing_rule() {
    return new StringEqParsingRule(")");
}

Word *RightBracketParser::parse(TextPointer &left, TextPointer &right) {
    return new CloseBracket();
}
