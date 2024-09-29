//
// Created by work on 28.09.2024.
//

#include "FnParameter.h"

#include <utility>
#include "../SemanticLogger.h"

FnParameter::FnParameter(std::size_t const& id, std::shared_ptr<Token> t): _symbol_id(id), _t(std::move(t)) {
}

std::string FnParameter::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}
