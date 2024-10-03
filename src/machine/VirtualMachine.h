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
#include "../lisp_structures/LispNull.h"
#include "EvalProcedure.h"

enum Opcode {
    LOAD=std::size_t(0),
    PUSH_NUMBER=std::size_t(1),
    CALL=std::size_t(2),
    RET=std::size_t(3),
    NOOP=std::size_t(4),
    BRACKET=std::size_t(5),
    CALL_AND_RET=std::size_t(6)
};

class LispObjectBracket: public LispObject {
    virtual std::string     to_string(StringMapper* mapper) { throw 1; }
    virtual LispObjectId    get_type() {return L_BRACKET; }
};
class VirtualMachine {
private:
    std::list<StackFrame>       _stack;
    std::list<LispObjectRef>    _params;
    LispObjectRef               _result = LispNull::get();
public:
    explicit VirtualMachine(LispObjectRef eval_object, std::shared_ptr<VarTable> table) {
        if(!eval_object.is<EvalProcedure>()) {
            throw -6;
        }
        _stack.emplace_back(eval_object, table);
    }
    void ret();
    void init_frame();
    void step();
    int eval();
    LispObjectRef result() {return _result;}
};


#endif //CPP_SCHEME_VIRTUALMACHINE_H
