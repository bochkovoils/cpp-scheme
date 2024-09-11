//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_INTEGERPARSINGSTATE_H
#define CPP_SCHEME_INTEGERPARSINGSTATE_H

#include "ParsingState.h"
#include "../tokens/Number.h"

class IntegerParsingState: public ParsingState {
public:
    void next(ParsingControl* state) override;
    bool is_terminated() override {return false;}
};
#endif //CPP_SCHEME_INTEGERPARSINGSTATE_H
