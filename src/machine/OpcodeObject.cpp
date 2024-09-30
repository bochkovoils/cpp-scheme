//
// Created by work on 30.09.2024.
//

#include "OpcodeObject.h"

OpcodeObject::OpcodeObject(std::size_t opcode): _opcode(opcode),
                                                _label(0),
                                                _has_label(false) {

}

OpcodeObject::OpcodeObject(std::size_t opcode, std::size_t label): _opcode(opcode),
                                                                   _label(label),
                                                                   _has_label(true)   {}
