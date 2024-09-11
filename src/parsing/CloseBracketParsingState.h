//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_CLOSEBRACKETPARSINGSTATE_H
#define CPP_SCHEME_CLOSEBRACKETPARSINGSTATE_H

#include "ParsingState.h"

class ParsingControl;

class CloseBracketParsingState: public ParsingState {
public:
    void next(ParsingControl* state) override;
    bool is_terminated() override {return false;}
};


#endif //CPP_SCHEME_CLOSEBRACKETPARSINGSTATE_H
