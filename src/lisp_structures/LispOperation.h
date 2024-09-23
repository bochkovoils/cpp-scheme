//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_LISPOPERATION_H
#define CPP_SCHEME_LISPOPERATION_H


#include <list>
#include "LispObject.h"
#include "LispSymbol.h"

class Evaluator;

class LispOperation: public LispObject {
public:
    virtual LispSymbol* get_symbol()=0;
    virtual LispObject* execute(LispObject* args, Evaluator* env)=0;
    void apply_visitor(StructuresVisitor *visitor) override;
};


#endif //CPP_SCHEME_LISPOPERATION_H
