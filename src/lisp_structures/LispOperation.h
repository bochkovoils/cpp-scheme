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
    std::string to_string(StringMapper *mapper) override;
    LispObjectId get_type() override { return LispObjectId::L_OPERATION; }
};


#endif //CPP_SCHEME_LISPOPERATION_H
