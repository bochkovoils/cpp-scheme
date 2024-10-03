//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_DEFINESYMBOL_H
#define CPP_SCHEME_DEFINESYMBOL_H


#include <memory>
#include "SemanticObject.h"
#include "../../parsing/Token.h"

class DefineSymbol: public SemanticObject {
private:
    std::shared_ptr<Token>  _t;
    std::size_t             _symbol_id;
    std::shared_ptr<SemanticObject>    _eval_expression;
public:
    DefineSymbol(std::size_t symbol_id, std::shared_ptr<SemanticObject> evalexp, std::shared_ptr<Token> token);
    std::shared_ptr<Token> token();
    std::size_t get_symbol_id() const;
    std::shared_ptr<SemanticObject> get_eval_expression();
    std::string apply_logger(SemanticLogger* logger, std::string& spaces);
    SEMANTIC_WALKER_VISITOR_WALK
};


#endif //CPP_SCHEME_DEFINESYMBOL_H
