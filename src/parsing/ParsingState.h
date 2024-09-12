//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_PARSINGSTATE_H
#define CPP_SCHEME_PARSINGSTATE_H

#include <vector>
#include <memory>
#include "../tokens/Word.h"
#include <iostream>

class ParsingInfo;

class ParsingState {
public:
    virtual void next(ParsingInfo* state) = 0;
    virtual bool is_terminated() = 0;
};

#endif //CPP_SCHEME_PARSINGSTATE_H
