//
// Created by work on 18.09.2024.
//

#include "LispNumber.h"

#include <utility>
#include "StructuresVisitor.h"

void LispNumber::apply_visitor(StructuresVisitor *visitor) {
    return visitor->apply(this);
}

LispNumber::LispNumber(std::string value): _value() {
    for(auto it : value) {
        _value = _value * 10 + it - '0';
    }
}

std::string LispNumber::get_value() {
    return std::to_string(_value);
}

LispNumber::LispNumber() {
    _value = 0;
}

LispNumber &LispNumber::operator+=(const LispNumber &n) {
    _value += n._value;
    return *this;
}

LispNumber &LispNumber::operator+=(const long long int &n) {
    _value += n;
    return *this;
}
