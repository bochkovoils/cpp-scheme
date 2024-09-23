//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPSYMBOL_H
#define CPP_SCHEME_LISPSYMBOL_H


#include <string>
#include "LispObject.h"

class LispSymbol: public LispObject {
public:
    static const std::hash<std::string_view> hash;
    static LispObject* quote;
private:
    std::string _name;
public:
    explicit LispSymbol(std::string  name);

    std::string get_name();
    std::size_t get_hash();
    void apply_visitor(StructuresVisitor *visitor) override;
};


#endif //CPP_SCHEME_LISPSYMBOL_H
