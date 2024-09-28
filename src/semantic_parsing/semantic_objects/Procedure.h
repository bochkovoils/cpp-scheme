//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_PROCEDURE_H
#define CPP_SCHEME_PROCEDURE_H


#include <memory>
#include <vector>
#include "SemanticObject.h"

class Procedure: public SemanticObject {
private:
    std::vector<std::shared_ptr<SemanticObject>>    _body;
    std::vector<std::size_t>                        _parameters;
    bool                                            _dot_notation;
public:
    explicit Procedure(std::vector<std::shared_ptr<SemanticObject>>& body,
                       std::vector<std::size_t>& parameters,
                       bool dot_notation=false): _body(body), _parameters(parameters), _dot_notation(dot_notation) {}
    std::vector<std::shared_ptr<SemanticObject>>    body() {return _body;}
    std::vector<std::size_t>                        parameters() {return _parameters;}
    std::size_t                                     arity() {return _parameters.size();}
    bool                                            dot_notation() const {return _dot_notation;}
};


#endif //CPP_SCHEME_PROCEDURE_H
