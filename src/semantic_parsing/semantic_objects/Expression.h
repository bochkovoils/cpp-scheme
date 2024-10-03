//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_EXPRESSION_H
#define CPP_SCHEME_EXPRESSION_H


#include <memory>
#include "SemanticObject.h"
#include "../../parsing/Token.h"

class Expression: public SemanticObject {
private:
    std::shared_ptr<Token>                          _t;
    std::vector<std::shared_ptr<SemanticObject>>    _objs;
public:
    Expression(std::vector<std::shared_ptr<SemanticObject>>& objs, std::shared_ptr<Token> token);
    std::string apply_logger(SemanticLogger* logger, std::string& spaces) override;
    std::vector<std::shared_ptr<SemanticObject>>&    elements();
    std::shared_ptr<SemanticObject>                  head();
    std::vector<std::shared_ptr<SemanticObject>>     args();
    SEMANTIC_WALKER_VISITOR_WALK
};


#endif //CPP_SCHEME_EXPRESSION_H
