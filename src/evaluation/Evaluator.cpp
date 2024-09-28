//
// Created by work on 23.09.2024.
//

#include "Evaluator.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispString.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispOperation.h"

//LispObject *Evaluator::eval(LispObject *object) {
//    return eval(object, Environment::global_root);
//}
//
//LispObject *Evaluator::eval(LispObject *object, Environment *environment) {
//    auto number = dynamic_cast<LispNumber*>(object);
//    if(number) return object;
//
//    auto symbol = dynamic_cast<LispSymbol*>(object);
//    if(symbol) return environment->get(symbol);
//
//    auto string = dynamic_cast<LispString*>(object);
//    if(string) return object;
//
//    auto null = dynamic_cast<LispNull*>(object);
//    if(null) return null;
//
//    auto cell = dynamic_cast<LispCell*>(object);
//    if(cell) {
//        auto head = dynamic_cast<LispSymbol*>(cell->head());
//        auto p = environment->get(head);
//        auto proc = dynamic_cast<LispOperation*>(p);
//        proc->execute(cell->rest(), this);
//    }
//}
LispObjectRef Evaluator::eval(LispObjectRef obj, std::shared_ptr<Environment> env) {
    if(obj.is<LispCell>()) {
        auto cell = obj.as<LispCell>();
        auto head = cell->head();
        auto rest = cell->rest();
        if(head.is<LispSymbol>() && head.as<LispSymbol>()->get_name() == "+") {
            auto res = new LispNumber("0");
            while (!rest.is<LispNull>()) {
                if(rest.as<LispCell>()->head().is<LispCell>()) {
                    (*res) += *eval(rest.as<LispCell>()->head(), env).as<LispNumber>();
                }
                else {
                    (*res) += *(rest.as<LispCell>()->head().as<LispNumber>());
                }
                auto n = rest.as<LispCell>()->rest();
                rest = MovRef{n};
            }
            return LispObjectRef(res);
        }
    }
    return {};
}


LispObjectRef Evaluator::eval_object(LispSymbol* obj){
    return {};
}

LispObjectRef Evaluator::eval_object(LispNumber* obj){
    return {};
}

LispObjectRef Evaluator::eval_object(LispList* obj){
    return {};
}

LispObjectRef Evaluator::eval_object(LispNull* obj){
    return {};
}

LispObjectRef Evaluator::eval_object(LispCell* obj){
    return {};
}

LispObjectRef Evaluator::eval_object(LispOperation* obj){
    return {};
}

LispObjectRef Evaluator::eval_object(LispString* obj){
    return {};
}

LispObjectRef Evaluator::trye(LispObjectRef obj) {
    return LispObjectRef();
}
