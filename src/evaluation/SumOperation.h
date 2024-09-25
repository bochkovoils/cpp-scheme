//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_SUMOPERATION_H
#define CPP_SCHEME_SUMOPERATION_H


#include <list>
#include "../lisp_structures/LispSymbol.h"
#include "../lisp_structures/LispOperation.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispCell.h"
#include "../environment/Environment.h"
#include "Evaluator.h"

class SumOperation: public LispOperation {
private:
    LispSymbol _symbol = LispSymbol("+");
public:
//    LispSymbol* get_symbol() override { return &_symbol; }
//    LispObject* execute(LispObject* rest, Evaluator* env) override;
};


#endif //CPP_SCHEME_SUMOPERATION_H
