//
// Created by work on 28.09.2024.
//

#include "String.h"

#include <utility>

String::String(std::string string, std::shared_ptr<Token> token): _string(std::move(string)), _token(std::move(token)) {
}

#include "../SemanticLogger.h"
std::string String::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}
