//
// Created by work on 18.09.2024.
//

#include "LispSymbol.h"

#include <utility>
#include "../painters/StringMapper.h"
#include "../parsing/SymbolicTable.h"

std::string LispSymbol::to_string(StringMapper *mapper) {
    return mapper->map(this);
}

std::string LispSymbol::get_name() {
    return SymbolicTable::get().get_symbol(_id);
}

LispObjectRef LispSymbol::quote = LispObjectRef(new LispSymbol(SymbolicTable::get().insert("quote")));
std::hash<std::string_view> const LispSymbol::hash = std::hash<std::string_view>();

LispSymbol::LispSymbol(const size_t &id): _id(id) {

}

