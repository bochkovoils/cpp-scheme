//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_WORD_H
#define CPP_SCHEME_WORD_H

#include "TokensInfo.h"
#include <optional>

class Word {
protected:
    TokenCode _index;
public:
    explicit Word(TokenCode index): _index(index) {}
    TokenCode token_code() {return this->_index;}
    virtual std::string to_string() = 0;
};
#endif //CPP_SCHEME_WORD_H
