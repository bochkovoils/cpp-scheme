//
// Created by work on 18.09.2024.
//

#include "LispString.h"

#include "../painters/StringMapper.h"
std::string LispString::to_string(StringMapper *mapper) {
    return mapper->map(this);
}

LispString::LispString(std::string &s): _value(std::move(s)) {
}

LispString::LispString(std::string const&s): _value(s) {
}