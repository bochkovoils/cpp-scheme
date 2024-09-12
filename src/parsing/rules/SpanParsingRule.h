//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_SPANPARSINGRULE_H
#define CPP_SCHEME_SPANPARSINGRULE_H


#include "ParsingRule.h"

class SpanParsingRule: public ParsingRule {
private:
    char const _bottom;
    char const _top;
public:
    SpanParsingRule(char bottom, char top);
    TextPointer try_parse(TextPointer  const& parser) override;
};


#endif //CPP_SCHEME_SPANPARSINGRULE_H
