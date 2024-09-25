//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPSYMBOL_H
#define CPP_SCHEME_LISPSYMBOL_H


#include <string>
#include "LispObject.h"
#include "LispObjectRef.h"

class LispSymbol: public LispObject {
public:
    static const std::hash<std::string_view> hash;
    static LispObjectRef quote;
private:
    std::string _name;
public:
    explicit LispSymbol(std::string  name);

    std::string get_name();
    std::size_t get_hash();
    std::string to_string(StringMapper *mapper) override;
    LispObjectId get_type() override { return LispObjectId::L_SYMBOL; }
};


#endif //CPP_SCHEME_LISPSYMBOL_H
