//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPSTRING_H
#define CPP_SCHEME_LISPSTRING_H


#include "LispObject.h"

class LispString: public LispObject {
private:
    std::string _value;
public:
    LispString(std::string& s);
    LispString(std::string const& s);
    std::string get() {return _value;};
    std::string to_string(StringMapper *mapper) override;
    LispObjectId get_type() override { return LispObjectId::L_STRING; }
    LispObjectRef evaluate(Evaluator *evaluator) override;
};


#endif //CPP_SCHEME_LISPSTRING_H
