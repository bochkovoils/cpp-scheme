//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_SYNTAX2SEMANTICSUBSCRIBER_H
#define CPP_SCHEME_SYNTAX2SEMANTICSUBSCRIBER_H


#include <memory>
#include <utility>
#include "../parsing/Observer.h"
#include "../parsing/SyntaxTree.h"
#include "semantic_objects/SemanticObject.h"
#include "SemanticParser.h"

class Syntax2SemanticSubscriber: public Observer    <std::shared_ptr<SyntaxTree>>,
                                 public Observable  <std::shared_ptr<SemanticObject>> {
private:
    std::shared_ptr<SemanticParser> _so;
public:
    explicit Syntax2SemanticSubscriber(std::shared_ptr<SemanticParser> so): _so(std::move(so)) {}
    void handle(std::shared_ptr<SyntaxTree>) override;
};


#endif //CPP_SCHEME_SYNTAX2SEMANTICSUBSCRIBER_H
