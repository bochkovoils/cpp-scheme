//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_PARSINGRULE_H
#define CPP_SCHEME_PARSINGRULE_H


#include "../text_handling/TextPointer.h"

class ParsingInfo;

class ParsingRule {
public:
    virtual TextPointer try_parse( TextPointer const& parser ) = 0;
};


#endif //CPP_SCHEME_PARSINGRULE_H
