//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_ORPARSINGRULE_H
#define CPP_SCHEME_ORPARSINGRULE_H


#include <list>
#include "ParsingRule.h"

class OrParsingRule: public ParsingRule {
private:
    std::list<std::shared_ptr<ParsingRule>> _rules;
public:
    explicit OrParsingRule(std::list<ParsingRule*> rules);
    TextPointer try_parse(const TextPointer &parser) override;
};


#endif //CPP_SCHEME_ORPARSINGRULE_H
