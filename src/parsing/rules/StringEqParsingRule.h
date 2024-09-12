//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_STRINGEQPARSINGRULE_H
#define CPP_SCHEME_STRINGEQPARSINGRULE_H


#include <string>
#include "ParsingRule.h"

class StringEqParsingRule : public ParsingRule {
private:
    std::string _string;
public:
    StringEqParsingRule(char const*);

    TextPointer try_parse(TextPointer const& parser) override;
};


#endif //CPP_SCHEME_STRINGEQPARSINGRULE_H
