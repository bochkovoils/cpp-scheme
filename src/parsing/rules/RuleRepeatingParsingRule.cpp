//
// Created by giantdad on 12.09.24.
//

#include "RuleRepeatingParsingRule.h"


TextPointer RuleRepeatingParsingRule::try_parse(const TextPointer &pointer) {
    auto forward = pointer;
    for(int repeats=0; repeats<_top; repeats++) {
        TextPointer next = _rule->try_parse(forward);
        if(next == forward) {
            if(repeats >= _bottom) return forward;
            else return pointer;
        }
        forward = next;
    }
    return forward;
}

RuleRepeatingParsingRule::RuleRepeatingParsingRule(std::unique_ptr<ParsingRule> rule, unsigned int bottom,
                                                   unsigned int top) :
                                                   _rule(std::move(rule)),
                                                   _bottom(bottom),
                                                   _top(top)
                                                   {

}

RuleRepeatingParsingRule::RuleRepeatingParsingRule(ParsingRule *rule, unsigned int bottom, unsigned int top) :
        _rule(rule),
        _bottom(bottom),
        _top(top) {

}
