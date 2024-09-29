//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_PROCEDURE_H
#define CPP_SCHEME_PROCEDURE_H


#include <memory>
#include <utility>
#include <vector>
#include "SemanticObject.h"
#include "Expression.h"

class Procedure: public SemanticObject {
private:
    std::shared_ptr<Expression>                     _body;
    std::vector<std::shared_ptr<SemanticObject>>    _parameters;
    bool                                            _dot_notation;
public:
    explicit Procedure(std::shared_ptr<Expression> body,
                       std::vector<std::shared_ptr<SemanticObject>>& parameters,
                       bool dot_notation=false): _body(std::move(body)), _parameters(parameters), _dot_notation(dot_notation) {}
    std::shared_ptr<Expression>                     body() {return _body;}
    std::vector<std::shared_ptr<SemanticObject>>    parameters() {return _parameters;}
    std::size_t                                     arity() {return _parameters.size();}
    bool                                            dot_notation() const {return _dot_notation;}
    std::string apply_logger(SemanticLogger *logger, std::string &spaces) override;
};


#endif //CPP_SCHEME_PROCEDURE_H
