//
// Created by work on 28.09.2024.
//

#include "BoundVariable.h"

#include <utility>


BoundVariable::BoundVariable(std::size_t id, std::shared_ptr<Token> token): _id(id), _t(std::move(token)) {

}

#include "../SemanticLogger.h"
std::string BoundVariable::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}


