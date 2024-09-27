//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_EVALUATOR_H
#define CPP_SCHEME_EVALUATOR_H


#include <stack>
#include "../lisp_structures/LispObject.h"
#include "../environment/Environment.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispList.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispOperation.h"
#include "../lisp_structures/LispString.h"

class Evaluator {
private:
//    std::stack<LispObjectRef>
public:
    LispObjectRef eval_object(LispSymbol* obj);
    LispObjectRef eval_object(LispNumber* obj);
    LispObjectRef eval_object(LispList* obj);
    LispObjectRef eval_object(LispNull* obj);
    LispObjectRef eval_object(LispCell* obj);
    LispObjectRef eval_object(LispOperation* obj);
    LispObjectRef eval_object(LispString* obj);

    LispObjectRef eval(LispObjectRef obj, std::shared_ptr<Environment> env);
};


#endif //CPP_SCHEME_EVALUATOR_H
