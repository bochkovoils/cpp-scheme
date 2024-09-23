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
    LispNumber(std::string  value);
    LispNumber();
    long long int value() {return _value;}
    std::string get_value();
    void apply_visitor(StructuresVisitor *visitor) override;
    LispNumber& operator+=(LispNumber const&);
    LispNumber& operator+=(long long int const&);
};


#endif //CPP_SCHEME_LISPNUMBER_H
