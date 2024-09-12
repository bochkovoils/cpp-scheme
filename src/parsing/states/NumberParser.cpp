//
// Created by giantdad on 12.09.24.
//

#include "NumberParser.h"
#include "../rules/SpanParsingRule.h"
#include "../rules/RuleRepeatingParsingRule.h"
#include "../../tokens/Number.h"

ParsingRule *NumberParser::parsing_rule() {
    return new RuleRepeatingParsingRule(new SpanParsingRule('0', '9'));
}

Word *NumberParser::parse(TextPointer &left, TextPointer &right) {
    int result = 0;

    std::string vals = right.dif(left);
    for(auto & val: vals) {
        result = result * 10 + val;
    }
    return new Number(result);
}
