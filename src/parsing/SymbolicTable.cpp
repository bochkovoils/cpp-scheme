//
// Created by work on 27.09.2024.
//

#include <string>
#include "SymbolicTable.h"

bool SymbolicTable::contains(const std::string_view &s) {
    return _str2id.count(s.data()) > 0;
}

std::size_t SymbolicTable::get_id(const std::string_view &s) {
    if(!contains(s)) throw 1;
    return _str2id[s.data()];
}

std::size_t SymbolicTable::insert(const std::string_view &s) {
    auto s_ = std::string(s);
    if(contains(s_))
        return _str2id[s_.c_str()];
    _str2id[s_.c_str()] = _maxid;
    _id2str[_maxid] = s_;
    auto res = _maxid;
    _maxid++;
    return res;
}

std::string SymbolicTable::get_symbol(std::size_t const& id) {
    return _id2str[id];
}

std::size_t SymbolicTable::size() const {
    return _str2id.size();
}

SymbolicTable& SymbolicTable::get() {
    return _instance;
}

SymbolicTable SymbolicTable::_instance = SymbolicTable();
