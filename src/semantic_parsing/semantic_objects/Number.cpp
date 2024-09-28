//
// Created by work on 28.09.2024.
//

#include "Number.h"

#include <utility>

#include "../SemanticLogger.h"
std::string Number::apply_logger(SemanticLogger *logger, std::string& spaces) {
    return logger->get(this, spaces);
}

Number::Number(int value, std::shared_ptr<Token> token): _value(value), _t(std::move(token)) {
}
