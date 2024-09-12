//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_RULEREPEATINGPARSINGRULE_H
#define CPP_SCHEME_RULEREPEATINGPARSINGRULE_H


#include "ParsingRule.h"

class RuleRepeatingParsingRule : public ParsingRule {
private:
    std::unique_ptr<ParsingRule> _rule;
    unsigned int _bottom;
    unsigned int _top;
public:
    explicit RuleRepeatingParsingRule(std::unique_ptr<ParsingRule> rule,
                                      unsigned int bottom=1,
                                      unsigned int top=1);
    explicit RuleRepeatingParsingRule(ParsingRule* rule,
                                      unsigned int bottom=1,
                                      unsigned int top=1);
    TextPointer try_parse(const TextPointer &parser) override;
};


#endif //CPP_SCHEME_RULEREPEATINGPARSINGRULE_H
