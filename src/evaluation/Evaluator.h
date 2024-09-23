//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_EVALUATOR_H
#define CPP_SCHEME_EVALUATOR_H


#include "../lisp_structures/LispObject.h"
#include "../environment/Environment.h"

class Evaluator {
public:
    LispObject* eval(LispObject* object, Environment* environment);

    LispObject *eval(LispObject *object);
};


#endif //CPP_SCHEME_EVALUATOR_H
