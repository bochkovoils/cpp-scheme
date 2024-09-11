//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_OPENBRACKET_H
#define CPP_SCHEME_OPENBRACKET_H

#include "Word.h"

class OpenBracket : public Word {
public:
    OpenBracket(): Word(TokenCode::OPEN_BRACKET) {}
    std::string to_string() override {return "[OpenBracket]";}
};

#endif //CPP_SCHEME_OPENBRACKET_H
