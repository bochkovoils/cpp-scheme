//
// Created by work on 30.09.2024.
//

#include <iostream>
#include "VirtualMachine.h"
#include "../lisp_structures/LispNumber.h"
#include "../semantic_parsing/semantic_objects/FnParameter.h"
#include "EvalProcedure.h"
#include "../lisp_structures/LispCell.h"

int VirtualMachine::eval() {
    while(!_stack.empty()) {
        step();
    }
    return 0;
}

void VirtualMachine::step() {
    auto frame = _stack.back();
    auto code = *frame.eval_object().as<EvalObject>()->byte_code();
    auto pos = frame.position();

    switch (code[pos]) {
        case Opcode::BRACKET:
            _params.emplace_back(LispObjectRef(new LispObjectBracket()));
            break;
        case Opcode::PUSH_NUMBER:
            _params.emplace_back(LispObjectRef(new LispNumber(code[++pos])));
            break;
        case Opcode::LOAD:
            _params.emplace_back(_stack.back().variables()->get(++pos));
            break;
        case Opcode::RET:
            ret();
            break;
        case Opcode::CALL:
            init_frame();
            break;
        default:
            throw -2;
    }
    if(!_stack.empty())
        _stack.back().update_position(++pos);
}
void VirtualMachine::ret() {
    auto res = _params.back();
    _params.pop_back();
    _stack.pop_back();
    _params.push_back(res);
    _result = MovRef{res};
}

void VirtualMachine::init_frame() {
    auto fn_ = _params.back();
    auto fn = dynamic_cast<EvalProcedure*>(fn_.get());
    if(fn == nullptr) {
        throw -3;
    }

    _params.pop_back();
    auto args_l = std::list<LispObjectRef>();
    while(true) {
        if(_params.empty()) throw 1;
        auto obj = _params.back();
        if(obj->get_type() == LispObjectId::L_BRACKET) {
            _params.pop_back();
            break;
        }
        _params.pop_back();
        args_l.push_front(obj);
    }

    auto pvec = std::vector<LispObjectRef>(args_l.begin(), args_l.end());
    auto curframe =  _stack.back();
    auto params = fn->get_procedure()->parameters();
    auto argmap = std::map<std::size_t, LispObjectRef>();
    if(params.size() != pvec.size() && !curframe.eval_object().as<EvalProcedure>()->get_procedure()->dot_notation()) {
        throw -5;
    }
    if(params.size() != pvec.size() && curframe.eval_object().as<EvalProcedure>()->get_procedure()->dot_notation()) {
        if(params.size() < pvec.size()) throw -5;
        auto vec = LispCell::from_vector(pvec.begin()+params.size()-1, pvec.end());
        pvec[params.size()-1] = MovRef{vec};
    }
    for(int i=0; i<params.size(); i++) {
        argmap.insert(std::make_pair(params[i]->get_symbol_id(), pvec[i]));
    }

    auto vart = _stack.back().variables()->clone();
    vart->extends(argmap);
    _stack.emplace_back(fn_, vart);
}
