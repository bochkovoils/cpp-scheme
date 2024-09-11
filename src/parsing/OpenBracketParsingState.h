//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_OPENBRACKETPARSINGSTATE_H
#define CPP_SCHEME_OPENBRACKETPARSINGSTATE_H

#include "ParsingState.h"

class OpenBracketParsingState: public ParsingState {
public:
    void next(ParsingControl* state) override;
    bool is_terminated() override {return false;}
};

#endif //CPP_SCHEME_OPENBRACKETPARSINGSTATE_H
