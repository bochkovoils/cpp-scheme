//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_SEQUENTIALPARSINGRULE_H
#define CPP_SCHEME_SEQUENTIALPARSINGRULE_H

#include <list>
#include <memory>
#include "ParsingRule.h"

class SequentialParsingRule : public ParsingRule {
private:
    std::list<std::shared_ptr<ParsingRule>> _rules;
public:
    explicit SequentialParsingRule(std::list<ParsingRule*> rules);
    TextPointer try_parse(const TextPointer &parser) override;
};


#endif //CPP_SCHEME_SEQUENTIALPARSINGRULE_H
