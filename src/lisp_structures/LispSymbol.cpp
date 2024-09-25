//
// Created by work on 18.09.2024.
//

#include "LispSymbol.h"

#include <utility>
#include "../painters/StringMapper.h"
std::string LispSymbol::to_string(StringMapper *mapper) {
    return mapper->map(this);
}

std::string LispSymbol::get_name() {
    return _name;
}


LispSymbol::LispSymbol(std::string name): _name(std::move(name)) {}

LispObjectRef LispSymbol::quote = LispObjectRef(new LispSymbol("quote"));
std::hash<std::string_view> const LispSymbol::hash = std::hash<std::string_view>();

std::size_t LispSymbol::get_hash() {
    return LispSymbol::hash(_name);
}
