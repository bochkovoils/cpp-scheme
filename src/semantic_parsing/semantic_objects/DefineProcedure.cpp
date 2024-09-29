//
// Created by work on 28.09.2024.
//

#include "DefineProcedure.h"

#include <utility>

DefineProcedure::DefineProcedure(std::size_t symbol_id,
                                 std::shared_ptr<Procedure> procedure,
                                 std::shared_ptr<Token> token)
                                 :  _symbol_id(symbol_id),
                                    _procedure(std::move(procedure)),
                                    _t(std::move(token)) {

}

std::shared_ptr<Token> DefineProcedure::token() {
    return _t;
}

std::size_t DefineProcedure::get_symbol_id() const {
    return _symbol_id;
}

std::shared_ptr<Procedure> DefineProcedure::get_procedure() {
    return _procedure;
}

#include "../SemanticLogger.h"
std::string DefineProcedure::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}
