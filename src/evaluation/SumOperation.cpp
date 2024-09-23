//
// Created by work on 23.09.2024.
//

#include "SumOperation.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"

LispObject *SumOperation::execute(LispObject* rest, Evaluator* env) {
    auto result = new LispNumber();
    while (rest != LispNull::get()) {
        auto cell = dynamic_cast<LispCell*>(rest);
        if(cell) {
            auto next_ = env->eval(cell->head());
            auto next = dynamic_cast<LispNumber*>(next_);
            if(!bool(next))
                throw 1;
            (*result) += (*next);
            rest = cell->rest();
        }
        else {
            throw 1;
        }
    }
    return result;
}

