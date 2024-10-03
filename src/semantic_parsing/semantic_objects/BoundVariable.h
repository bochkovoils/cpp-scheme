//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_BOUNDVARIABLE_H
#define CPP_SCHEME_BOUNDVARIABLE_H


#include <memory>
#include "../../parsing/Token.h"
#include "SemanticObject.h"

class BoundVariable: public SemanticObject {
private:
    std::shared_ptr<Token> _t;
    std::size_t _id;
public:
    BoundVariable(std::size_t id, std::shared_ptr<Token> token);
    std::string apply_logger(SemanticLogger* logger, std::string& spaces) override;
    std::size_t get_symbol_id() const {return _id;}
    SEMANTIC_WALKER_VISITOR_WALK

};


#endif //CPP_SCHEME_BOUNDVARIABLE_H
