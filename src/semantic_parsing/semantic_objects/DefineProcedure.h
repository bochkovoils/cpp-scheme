//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_DEFINEPROCEDURE_H
#define CPP_SCHEME_DEFINEPROCEDURE_H


#include <memory>
#include "SemanticObject.h"
#include "../../parsing/Token.h"
#include "Procedure.h"

class DefineProcedure: public SemanticObject {
private:
    std::shared_ptr<Token>          _t;
    std::size_t                     _symbol_id;
    std::shared_ptr<Procedure>      _procedure;
public:
    DefineProcedure(std::size_t symbol_id,
                    std::shared_ptr<Procedure> procedure,
                    std::shared_ptr<Token> token);
    std::shared_ptr<Token> token();
    std::size_t get_symbol_id() const;
    std::shared_ptr<Procedure> get_procedure();
    std::string apply_logger(SemanticLogger* logger, std::string& spaces);

};


#endif //CPP_SCHEME_DEFINEPROCEDURE_H
