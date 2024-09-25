//
// Created by work on 18.09.2024.
//

#include "Frame.h"

std::size_t Frame::size() const {
    return _map.size();
}

void Frame::set_symbol(LispObjectRef symbol, LispObjectRef obj) {
    _map.insert(std::make_pair(symbol.as<LispSymbol>()->get_hash(), obj));
}

bool Frame::has(LispObjectRef symbol) const {
    return _map.count(symbol.as<LispSymbol>()->get_hash()) > 0;
}

LispObjectRef Frame::get(LispObjectRef s) {
    return _map.at(s.as<LispSymbol>()->get_hash());
}

