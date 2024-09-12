//
// Created by giantdad on 12.09.24.
//

#include "SequentialParsingRule.h"
#include <algorithm>

TextPointer SequentialParsingRule::try_parse(const TextPointer &pointer) {
    auto forward = pointer;
    for(auto & rule: _rules) {
        auto next = rule->try_parse(forward);
        if(next == forward) return pointer;
        forward = next;
    }
    return forward;
}

SequentialParsingRule::SequentialParsingRule(std::list<ParsingRule *> rules) {
    std::for_each(rules.begin(), rules.end(), [this](auto rule){
        this->_rules.push_back(std::shared_ptr<ParsingRule>(rule));
    });
}
