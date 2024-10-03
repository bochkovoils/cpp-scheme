//
// Created by work on 03.10.2024.
//

#include "EvalsCollector.h"
#include "VirtualMachine.h"

void EvalsCollector::handle(LispObjectRef o) {
    (*o.as<EvalObject>()) << OpcodeObject(Opcode::RET);
    _agenda.push_back(o);
}
