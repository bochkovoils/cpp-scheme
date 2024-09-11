//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_DEFAULTPARSINGSTATE_H
#define CPP_SCHEME_DEFAULTPARSINGSTATE_H

#include "ParsingState.h"

class DefaultParsingState: public ParsingState {
    void next(ParsingControl* state) override;
    bool is_terminated() override {return false;}
};
#endif //CPP_SCHEME_DEFAULTPARSINGSTATE_H
