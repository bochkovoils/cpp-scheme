//
// Created by work on 01.10.2024.
//

#include "TailRecursionReplacer.h"
//
// Created by work on 30.09.2024.
//

#include <algorithm>
#include <iostream>
#include "TailRecursionReplacer.h"

#include "../semantic_objects/Number.h"
#include "../semantic_objects/BoundVariable.h"
#include "../semantic_objects/Expression.h"
#include "../semantic_objects/FnParameter.h"
#include "../semantic_objects/DefineSymbol.h"
#include "../semantic_objects/DefineProcedure.h"
#include "../semantic_objects/If.h"
#include "../semantic_objects/Quote.h"
#include "../semantic_objects/Procedure.h"



void TailRecursionReplacer::walk(If *o) {
    o->on_true()->apply_walker(this);
    o->on_false()->apply_walker(this);
}

void TailRecursionReplacer::walk(Number *o) {}
void TailRecursionReplacer::walk(String *o) {}

void TailRecursionReplacer::walk(BoundVariable *o) {
}

void TailRecursionReplacer::walk(Expression *o) {

}

void TailRecursionReplacer::walk(FnParameter *o) {
}

void TailRecursionReplacer::walk(DefineSymbol *o) {
}

void TailRecursionReplacer::walk(DefineProcedure *o) {
    _stack.push_back(o->get_symbol_id());
    o->get_procedure()->apply_walker(this);
}

void TailRecursionReplacer::walk(Procedure *o) {
    std::set<std::size_t> inited;
    auto body = o->body()->elements();
    std::for_each(body.begin(), body.end(), [&inited, this, &o](auto elem){
        if(auto defs = dynamic_cast<DefineSymbol*>(elem.get())) {
            inited.insert(defs->get_symbol_id());
            return;
        }
        if(auto deff = dynamic_cast<DefineProcedure*>(elem.get())) {
            inited.insert(deff->get_symbol_id());
            return;
        }
        elem->apply_walker(this);
    });
    auto last = dynamic_cast<Expression*>((body.end()-1)->get());
}

void TailRecursionReplacer::walk(Quote *o) {

}

