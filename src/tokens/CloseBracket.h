//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_CLOSEBRACKET_H
#define CPP_SCHEME_CLOSEBRACKET_H

#include "Word.h"

class CloseBracket: public Word {
public:
    CloseBracket(): Word(TokenCode::CLOSE_BRACKET) {}
    std::string to_string() override {return "[CloseBracket]";}
};
#endif //CPP_SCHEME_CLOSEBRACKET_H
