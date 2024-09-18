//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_TREEBUILDER_H
#define CPP_SCHEME_TREEBUILDER_H


#include "Parser.h"
#include "Symbol.h"
#include "LispList.h"
#include <utility>
#include <variant>
#include <stack>
#include <memory>


enum TreeBuilderState {
    EMPTY,
    PARSING,
};

class TokenWrapper: public AbstractNode {
private:
    Token _token;
public:
    explicit TokenWrapper(Token  token): _token(std::move(token)) {};
    AbstractNodeType get_type() override {return AbstractNodeType::TOKEN_WRAPPER;}
    [[nodiscard]] Token const& get_token() const {return _token; }
};

class TreeBuilder {
private:
    Parser* _parser{};
    std::stack<AbstractNode*> _vstack;
    std::stack<Token> _tstack;
    std::stack<AbstractNode*> _varstack;
public:
    explicit TreeBuilder(Parser* parser);

    bool is_end();
    AbstractNode* next();

    AbstractNode* parse_all();

    void read_list();
};


#endif //CPP_SCHEME_TREEBUILDER_H
