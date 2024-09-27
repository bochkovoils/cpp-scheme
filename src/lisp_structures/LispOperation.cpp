//
// Created by work on 23.09.2024.
//

#include "LispOperation.h"

#include "../painters/StringMapper.h"
std::string LispOperation::to_string(StringMapper *mapper) {
    return mapper->map(this);
}

#include "../evaluation/Evaluator.h"
LispObjectRef LispOperation::evaluate(Evaluator *evaluator) {
    return evaluator->eval_object(this);
}