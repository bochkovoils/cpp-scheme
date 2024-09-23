//
// Created by work on 18.09.2024.
//

#include "LispSymbol.h"

#include <utility>
#include "StructuresVisitor.h"

std::string LispSymbol::get_name() {
    return _name;
}


LispSymbol::LispSymbol(std::string name): _name(std::move(name)) {}

LispObject *LispSymbol::quote = new LispSymbol("QUOTE");
std::hash<std::string_view> const LispSymbol::hash = std::hash<std::string_view>();

void LispSymbol::apply_visitor(StructuresVisitor *visitor) {
    visitor->apply(this);
}

std::size_t LispSymbol::get_hash() {
    return LispSymbol::hash(_name);
}
