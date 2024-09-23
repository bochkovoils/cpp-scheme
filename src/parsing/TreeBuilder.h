//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_TREEBUILDER_H
#define CPP_SCHEME_TREEBUILDER_H


#include "Parser.h"
#include "../lisp_structures/LispObject.h"
#include <utility>
#include <variant>
#include <stack>
#include <memory>


enum TreeBuilderState {
    EMPTY,
    PARSING,
};

class TokenWrapper: public LispObject {
private:
    Token _token;
public:
    explicit TokenWrapper(Token  token): _token(std::move(token)) {};
    [[nodiscard]] Token const& get_token() const {return _token; }
    void apply_visitor(StructuresVisitor *visitor) override { throw 1; }
};

class TreeBuilder {
private:
    Parser* _parser{};
    std::stack<LispObject*> _varstack;
public:
    explicit TreeBuilder(Parser* parser);

    bool is_end();
    LispObject* next();

    LispObject* parse_all();
    LispObject* parse_primitive(Token const&);

    void read_list();
};


#endif //CPP_SCHEME_TREEBUILDER_H
