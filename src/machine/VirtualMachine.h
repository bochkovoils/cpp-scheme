//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_VIRTUALMACHINE_H
#define CPP_SCHEME_VIRTUALMACHINE_H

#include <cstddef>
#include <memory>
#include <stack>
#include <list>
#include "../lisp_structures/LispObjectRef.h"
#include "ByteCode.h"
#include "StackFrame.h"

enum Opcode {
    LOAD=std::size_t(0),
    PUSH=std::size_t(1),
    CALL=std::size_t(2),
    RET=std::size_t(3),
    NOOP=std::size_t(4)
};

class VirtualMachine {
private:
    std::shared_ptr<ByteCode> _code;
    std::size_t               _current_position;
    std::list<StackFrame>     _stack;
public:
    explicit VirtualMachine(std::shared_ptr<ByteCode> code): _code(code),
                                                             _current_position(code->get_main_position()),
                                                             _stack() {};
    int eval();
};


#endif //CPP_SCHEME_VIRTUALMACHINE_H
