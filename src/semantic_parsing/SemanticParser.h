//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_SEMANTICPARSER_H
#define CPP_SCHEME_SEMANTICPARSER_H


#include <memory>
#include "semantic_objects/SemanticObject.h"
#include "../parsing/SyntaxTree.h"

class SemanticParser {
public:
    std::shared_ptr<SemanticObject> parse(std::shared_ptr<SyntaxTree>);
    std::shared_ptr<SemanticObject> parse_quote(std::shared_ptr<SyntaxTree>);
    std::shared_ptr<SemanticObject> parse_list(std::shared_ptr<SyntaxTree> sharedPtr);
    std::shared_ptr<SemanticObject> parse_if(std::vector<std::shared_ptr<SyntaxTree>>& vector1);
    std::shared_ptr<SemanticObject> parse_define(std::vector<std::shared_ptr<SyntaxTree>>& vector1,
                                                 std::shared_ptr<Token> t);
    std::shared_ptr<SemanticObject> parse_let(std::vector<std::shared_ptr<SyntaxTree>>& vector1);
    std::shared_ptr<SemanticObject> parse_null(std::shared_ptr<SyntaxTree> sharedPtr);
    std::shared_ptr<SemanticObject> parse_lets(std::vector<std::shared_ptr<SyntaxTree>>& vector1);
    std::shared_ptr<SemanticObject> parse_cond(std::vector<std::shared_ptr<SyntaxTree>>& vector1);
    std::shared_ptr<SemanticObject> parse_expression(std::vector<std::shared_ptr<SyntaxTree>>& vector1,
                                                     std::shared_ptr<Token> t);

    std::pair<std::vector<std::size_t>, bool> parse_parameters(std::vector<std::shared_ptr<SyntaxTree>>& params);
};


#endif //CPP_SCHEME_SEMANTICPARSER_H
