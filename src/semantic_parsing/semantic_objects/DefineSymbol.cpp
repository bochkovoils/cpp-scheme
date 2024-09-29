//
// Created by work on 27.09.2024.
//

#include "DefineSymbol.h"

#include <utility>

DefineSymbol::DefineSymbol(std::size_t symbol_id, std::shared_ptr<SemanticObject> evalexp,
                           std::shared_ptr<Token> token)
                           : _symbol_id(symbol_id),
                             _eval_expression(std::move(evalexp)),
                             _t(std::move(token)){

}

std::shared_ptr<Token> DefineSymbol::token() {
    return _t;
}

std::size_t DefineSymbol::get_symbol_id() const {
    return _symbol_id;
}

std::shared_ptr<SemanticObject> DefineSymbol::get_eval_expression() {
    return _eval_expression;
}

#include "../SemanticLogger.h"
std::string DefineSymbol::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}

