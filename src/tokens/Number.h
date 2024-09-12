//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_NUMBER_H
#define CPP_SCHEME_NUMBER_H

#include "Word.h"
#include "TokensInfo.h"

class Number: public Word {
private:
    int _value;
public:
    explicit Number(int const& value): Word(TokenCode::NUMBER), _value(value) {}
    std::string to_string() override {return std::string("[Number ") + std::to_string(_value) + std::string("]");}
};

#endif //CPP_SCHEME_NUMBER_H
