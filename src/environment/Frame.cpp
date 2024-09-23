//
// Created by work on 18.09.2024.
//

#include "Frame.h"

std::size_t Frame::size() const {
    return _map.size();
}

void Frame::set_symbol(LispSymbol *symbol, LispObject *obj) {
    _map.insert(std::make_pair(symbol->get_hash(), obj));
}

bool Frame::has(LispSymbol *symbol) const {
    return _map.count(symbol->get_hash()) > 0;
}

LispObject *Frame::get(LispSymbol* s) {
    return _map.at(s->get_hash());
}

