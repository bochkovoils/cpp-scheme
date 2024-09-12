//
// Created by giantdad on 12.09.24.
//

#include "OrParsingRule.h"
#include <algorithm>

OrParsingRule::OrParsingRule(std::list<ParsingRule *> rules) {
    for(auto & rule: rules) {
        _rules.push_back(std::shared_ptr<ParsingRule>(rule));
    }
}

TextPointer OrParsingRule::try_parse(const TextPointer &pointer) {
    auto forward = pointer;
    for(auto & rule: _rules) {
        forward = rule->try_parse(pointer);
        if(!(forward == pointer)) return forward;
    }
    return forward;
}
