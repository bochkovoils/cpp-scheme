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
    std::size_t _id;
public:
    explicit LispSymbol(std::size_t const& id);

    std::string get_name();
    std::string to_string(StringMapper *mapper) override;
    LispObjectId get_type() override { return LispObjectId::L_SYMBOL; }
    std::size_t get_id() const { return _id; }
};


#endif //CPP_SCHEME_LISPSYMBOL_H
