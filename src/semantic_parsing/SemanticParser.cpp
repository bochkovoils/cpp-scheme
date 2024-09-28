//
// Created by work on 28.09.2024.
//

#include <algorithm>
#include <utility>
#include "SemanticParser.h"
#include "../parsing/SymbolicTable.h"
#include "semantic_objects/If.h"
#include "semantic_objects/Number.h"
#include "semantic_objects/String.h"
#include "semantic_objects/BoundVariable.h"
#include "semantic_objects/Expression.h"

std::shared_ptr<SemanticObject> SemanticParser::parse(std::shared_ptr<SyntaxTree> tree) {
    if(tree->get_id() == SyntaxTreeId::ST_ATOM) {
        switch (tree->bound_token()->get_id()) {
            case TokenId::T_NUMBER:
                return std::shared_ptr<SemanticObject>(
                        new Number(dynamic_cast<NumberToken*>(tree->bound_token().get())->get_value(),
                                   tree->bound_token()));
            case TokenId::T_STRING:
                return std::shared_ptr<SemanticObject>(
                        new String(dynamic_cast<StringToken*>(tree->bound_token().get())->get_string(),
                                   tree->bound_token()));
            case TokenId::T_SYMBOL:
                return std::shared_ptr<SemanticObject>(
                        new BoundVariable(dynamic_cast<SymbolToken*>(tree->bound_token().get())->get_symbol_id(),
                                          tree->bound_token()));
            default:
                throw 1;
        }
    }
    if(tree->get_id() == SyntaxTreeId::ST_QUOTE) {
        return parse_quote(tree);
    }
    if(tree->get_id() == SyntaxTreeId::ST_LIST) {
        return parse_list(tree);
    }
    if(tree->get_id() == SyntaxTreeId::ST_NULL) {
        return parse_null(tree);
    }
    throw 2;
}

std::shared_ptr<SemanticObject> SemanticParser::parse_quote(std::shared_ptr<SyntaxTree>) {
    return std::shared_ptr<SemanticObject>();
}

std::shared_ptr<SemanticObject> SemanticParser::parse_list(std::shared_ptr<SyntaxTree> tree) {
    auto children = tree->children();
    if(children[0]->get_id() == SyntaxTreeId::ST_ATOM) {
        auto head = children[0];
        if(dynamic_cast<NumberToken*>(head->bound_token().get()))
            throw 3;
        if(dynamic_cast<StringToken*>(head->bound_token().get()))
            throw 4;

        auto token_id = dynamic_cast<SymbolToken*>(head->bound_token().get())->get_symbol_id();
        auto stable = SymbolicTable::get();
        if(token_id == stable.get_id("if")      ) return parse_if(children);
        if(token_id == stable.get_id("define")  ) return parse_define(children);
        if(token_id == stable.get_id("let")     ) return parse_let(children);
        if(token_id == stable.get_id("let*")    ) return parse_lets(children);
        if(token_id == stable.get_id("cond")    ) return parse_cond(children);
        else return parse_expression(children, tree->bound_token());
    }
    else if(children[0]->get_id() == SyntaxTreeId::ST_QUOTE)
        throw 6;
    else return parse_expression(children, tree->bound_token());
}

std::shared_ptr<SemanticObject> SemanticParser::parse_if(std::vector<std::shared_ptr<SyntaxTree>>& elems) {
    if(elems.size() < 3 || elems.size() > 4)
        throw 7;
    auto cond = elems[1];
    auto on_true = elems[2];
    if(elems.size() == 4) {
        auto on_false = elems[3];
        return std::shared_ptr<SemanticObject>(new If(parse(cond), parse(on_true), parse(on_false)));
    }
    return std::shared_ptr<SemanticObject>(new If(parse(cond), parse(on_true)));
}

std::shared_ptr<SemanticObject> SemanticParser::parse_define(std::vector<std::shared_ptr<SyntaxTree>>& vector1,
                                                             std::shared_ptr<Token> t) {
    throw 8;
}

std::shared_ptr<SemanticObject> SemanticParser::parse_let(std::vector<std::shared_ptr<SyntaxTree>>& vector1) {
    throw 9;
}

std::shared_ptr<SemanticObject> SemanticParser::parse_null(std::shared_ptr<SyntaxTree> sharedPtr) {
    throw 10;
}

std::shared_ptr<SemanticObject> SemanticParser::parse_lets(std::vector<std::shared_ptr<SyntaxTree>>& vector1) {
    throw 11;
}

std::shared_ptr<SemanticObject> SemanticParser::parse_cond(std::vector<std::shared_ptr<SyntaxTree>>& vector1) {
    throw 12;
}

std::shared_ptr<SemanticObject> SemanticParser::parse_expression(std::vector<std::shared_ptr<SyntaxTree>>& vector1, std::shared_ptr<Token> t) {
    auto res = std::vector<std::shared_ptr<SemanticObject>>();
    std::for_each(vector1.begin(), vector1.end(), [this, &res](auto obj) {
        res.push_back(parse(obj));
    });
    return std::shared_ptr<SemanticObject>(new Expression(res, std::move(t)));
}

std::pair<std::vector<std::size_t>, bool>
SemanticParser::parse_parameters(std::vector<std::shared_ptr<SyntaxTree>> &params) {
    auto res = std::vector<std::size_t>();
    for(int i=0; i<params.size(); i++) {
        if(params[i]->get_id() != SyntaxTreeId::ST_ATOM)
            throw 13;
        if(params[i]->bound_token()->get_id() != TokenId::T_SYMBOL)
            throw 14;

        auto token = dynamic_cast<SymbolToken*>(params[i]->bound_token().get());
        if(token->get_symbol_id() == SymbolicTable::get().get_id(".")) {
            i++;
            if(i >= params.size())
                throw 15;
            if(i != params.size()-1)
                throw 16;
            if(params[i]->get_id() != SyntaxTreeId::ST_ATOM)
                throw 13;
            if(params[i]->bound_token()->get_id() != TokenId::T_SYMBOL)
                throw 14;
            res.push_back(params[i]);
            return std::make_pair(res, true);
        }
        res.push_back(params[i]);
    }
    return std::make_pair(res, false);
}
