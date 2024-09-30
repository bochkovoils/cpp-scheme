//
// Created by work on 18.09.2024.
//

#include "LispNull.h"


#include "../painters/StringMapper.h"
std::string LispNull::to_string(StringMapper *mapper) {
    return mapper->map(this);
}
LispObjectRef LispNull::_instance = LispObjectRef(new LispNull());

