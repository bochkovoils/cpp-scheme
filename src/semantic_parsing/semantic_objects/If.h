//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_IF_H
#define CPP_SCHEME_IF_H


#include <memory>
#include "SemanticObject.h"
#include "../../parsing/Token.h"

class If: public SemanticObject {
private:
    std::shared_ptr<SemanticObject> _condition;
    std::shared_ptr<SemanticObject> _on_true;
    std::shared_ptr<SemanticObject> _on_false;
public:
    If(std::shared_ptr<SemanticObject> cond,
       std::shared_ptr<SemanticObject> on_true,
       std::shared_ptr<SemanticObject> on_false);
    If(std::shared_ptr<SemanticObject> cond,
       std::shared_ptr<SemanticObject> on_true);

    std::shared_ptr<SemanticObject> condition();
    std::shared_ptr<SemanticObject> on_true();
    std::shared_ptr<SemanticObject> on_false();

    std::string apply_logger(SemanticLogger* logger, std::string& spaces) override;
};


#endif //CPP_SCHEME_IF_H
