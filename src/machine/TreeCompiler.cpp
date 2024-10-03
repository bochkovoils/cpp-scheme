//
// Created by work on 03.10.2024.
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include "TreeCompiler.h"
#include "VirtualMachine.h"

#include "../semantic_parsing/semantic_objects/Number.h"
#include "../semantic_parsing/semantic_objects/BoundVariable.h"
#include "../semantic_parsing/semantic_objects/Expression.h"
#include "../semantic_parsing/semantic_objects/FnParameter.h"
#include "../semantic_parsing/semantic_objects/DefineSymbol.h"
#include "../semantic_parsing/semantic_objects/DefineProcedure.h"
#include "../semantic_parsing/semantic_objects/If.h"
#include "../semantic_parsing/semantic_objects/Quote.h"
#include "../semantic_parsing/semantic_objects/Procedure.h"
#include "CodePrinter.h"

void TreeCompiler::walk(If* o              ){
    throw -1;
}
void TreeCompiler::walk(Number* o          ){
    (*_bodies.top()) << OpcodeObject(Opcode::PUSH_NUMBER) << o->get_value();
}

void TreeCompiler::walk(String* o          ){
    throw -1;
}

void TreeCompiler::walk(BoundVariable* o   ){
    (*_bodies.top()) << OpcodeObject(Opcode::LOAD) << o->get_symbol_id();
}

void TreeCompiler::walk(Expression* o      ){
    (*_bodies.top()) << OpcodeObject(Opcode::BRACKET);
    auto body = o->elements();
    auto head = o->head();
    auto args = o->args();
    std::for_each(args.begin(), args.end(), [this](auto elem) {
        elem->apply_walker(this);
    });
    head->apply_walker(this);
    (*_bodies.top()) << OpcodeObject(Opcode::CALL);
}

void TreeCompiler::walk(FnParameter* o     ){}
void TreeCompiler::walk(DefineSymbol* o    ){}
void TreeCompiler::walk(DefineProcedure* o ){}
void TreeCompiler::walk(Procedure* o       ){}
void TreeCompiler::walk(Quote* o           ){}

void TreeCompiler::log(int spaces) {
    std::cout << "CODE:" << std::endl;
    std:: cout << CodePrinter().get(_bodies.top()->byte_code()) << std::endl;
}

void TreeCompiler::handle(std::shared_ptr<SemanticObject> o) {
    while (!_bodies.empty()) {
        _bodies.pop();
    }
    _bodies.push(new EvalObject());
    o->apply_walker(this);
    log(0);
    auto res = _bodies.top();
    emit(LispObjectRef(reinterpret_cast<LispObject *>(res)));
}
