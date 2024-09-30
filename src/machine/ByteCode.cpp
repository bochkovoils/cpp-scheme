//
// Created by work on 30.09.2024.
//

#include <algorithm>
#include <iostream>
#include "ByteCode.h"

std::size_t ByteCode::operator[](std::size_t const &id) {
    return _data[id];
}

std::size_t ByteCode::get_label_position(const int &id) {
    return _labels[id];
}

std::size_t ByteCode::get_main_position() const {
    return _labels[0];
}

std::size_t ByteCode::label_index(const std::size_t &label_id) {
    auto it = std::find(_labels.begin(), _labels.end(), label_id);
    if (it == _labels.end())
    { throw 1000; }
    return std::distance(_labels.begin(), it);
}

ByteCode::ByteCode(std::vector<OpcodeObject>::iterator begin, std::vector<OpcodeObject>::iterator end) {
    std::size_t labels_count=0;
    std::size_t commands_count=0;
    std::for_each(begin, end, [&labels_count, &commands_count](auto o){
        commands_count++;
        if(o.has_label()) labels_count++;
    });
    _labels=std::vector<std::size_t>(int(labels_count));
    _data=std::vector<std::size_t>(int(commands_count));
    std::size_t i=0;
    std::for_each(begin, end, [this, &i](auto o){
        _data[i] = o.get_opcode();
        if(o.has_label()) _labels[o.get_label()] = i;
        i++;
    });
}
