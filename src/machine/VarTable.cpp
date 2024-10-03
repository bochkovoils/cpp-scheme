//
// Created by work on 03.10.2024.
//

#include <algorithm>
#include "VarTable.h"

void VarTable::define(std::size_t symbol_id, LispObjectRef obj) {
    _vars.insert_or_assign(symbol_id, std::make_shared<LinkBox>(obj));
}

bool VarTable::contains(std::size_t symbol_id) {
    return _vars.count(symbol_id);
}

LispObjectRef VarTable::get(std::size_t symbol_id) {
    if(!contains(symbol_id)) throw 1000;
    return _vars[symbol_id]->get();
}

void VarTable::set(std::size_t symbol_id, LispObjectRef obj) {
    if(!contains(symbol_id)) throw 1000;
    _vars[symbol_id]->assign(obj);
}

std::shared_ptr<VarTable> VarTable::clone() {
    return std::make_shared<VarTable>(_vars);
}

void VarTable::extends(std::map<std::size_t, LispObjectRef> map) {
    std::for_each(map.begin(), map.end(), [this](auto obj){
        define(obj.first, obj.second);
    });
}

VarTable::VarTable(std::map<std::size_t, std::shared_ptr<LinkBox>>& map): _vars(map) {
}
