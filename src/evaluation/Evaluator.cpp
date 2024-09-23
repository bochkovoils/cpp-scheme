//
// Created by work on 23.09.2024.
//

#include "Evaluator.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispString.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispOperation.h"

LispObject *Evaluator::eval(LispObject *object) {
    return eval(object, Environment::global_root);
}

LispObject *Evaluator::eval(LispObject *object, Environment *environment) {
    auto number = dynamic_cast<LispNumber*>(object);
    if(number) return object;

    auto symbol = dynamic_cast<LispSymbol*>(object);
    if(symbol) return environment->get(symbol);

    auto string = dynamic_cast<LispString*>(object);
    if(string) return object;

    auto null = dynamic_cast<LispNull*>(object);
    if(null) return null;

    auto cell = dynamic_cast<LispCell*>(object);
    if(cell) {
        auto head = dynamic_cast<LispSymbol*>(cell->head());
        auto p = environment->get(head);
        auto proc = dynamic_cast<LispOperation*>(p);
        proc->execute(cell->rest(), this);
    }
}
