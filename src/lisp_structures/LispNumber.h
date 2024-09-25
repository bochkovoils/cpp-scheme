//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPNUMBER_H
#define CPP_SCHEME_LISPNUMBER_H


#include <string>
#include "LispObject.h"

class LispNumber: public LispObject {
private:
    long long int _value;
public:
    explicit LispNumber(std::string  value);
    LispNumber();
    long long int value() {return _value;}
    std::string get_value();
    std::string to_string(StringMapper *mapper) override;
    LispNumber& operator+=(LispNumber const&);
    LispNumber& operator+=(long long int const&);
    LispObjectId get_type() override { return LispObjectId::L_NUMBER; }
};


#endif //CPP_SCHEME_LISPNUMBER_H
