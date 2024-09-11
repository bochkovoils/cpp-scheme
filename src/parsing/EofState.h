//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_EOFSTATE_H
#define CPP_SCHEME_EOFSTATE_H

#include "ParsingState.h"

class EofState: public ParsingState {
public:
    void next(ParsingControl* words) override {throw this;}
    bool is_terminated() override {return true;}
};

#endif //CPP_SCHEME_EOFSTATE_H
