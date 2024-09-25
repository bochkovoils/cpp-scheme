//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_EVALUATOR_H
#define CPP_SCHEME_EVALUATOR_H


#include "../lisp_structures/LispObject.h"
#include "../environment/Environment.h"

class Evaluator {
public:
    LispObjectRef eval(LispObjectRef obj, std::shared_ptr<Environment> env);
};


#endif //CPP_SCHEME_EVALUATOR_H
