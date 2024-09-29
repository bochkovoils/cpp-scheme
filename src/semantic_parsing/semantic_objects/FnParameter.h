//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_FNPARAMETER_H
#define CPP_SCHEME_FNPARAMETER_H


#include <memory>
#include "SemanticObject.h"
#include "../../parsing/Token.h"

class FnParameter: public SemanticObject {
private:
    std::size_t _symbol_id;
    std::shared_ptr<Token>  _t;
public:
    FnParameter(std::size_t const& id, std::shared_ptr<Token> t);
    virtual std::string apply_logger(SemanticLogger* logger, std::string& spaces);

    [[nodiscard]] std::size_t get_symbol_id() const {return _symbol_id;}
};


#endif //CPP_SCHEME_FNPARAMETER_H
