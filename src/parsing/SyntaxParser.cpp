//
// Created by work on 17.09.2024.
//

#include <algorithm>
#include <iostream>
#include "SyntaxParser.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispSymbol.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispString.h"
#include "../erors/ExceedClosingBracketException.h"

SyntaxParser::SyntaxParser() = default;

bool SyntaxParser::empty() {
    return _varstack.empty();
}


/*
 * Принимает токен и обрабатывает его
 */
void SyntaxParser::accept(std::shared_ptr<Token> token) {
    if(brackets == 0 &&
        token->get_id() != TokenId::T_OPEN_BRACKET &&
        token->get_id() != TokenId::T_CLOSE_BRACKET &&
        token->get_id() != TokenId::T_QUOTE) {

        std::shared_ptr<SyntaxTree> res = collapse_quotes(parse_primitive(token));
        _varstack.push(res);
        if(_varstack.size() == 1) {
            emit(_varstack.top());
            _varstack.pop();
        }
    }
    else if(token->get_id() == TokenId::T_OPEN_BRACKET) {
        brackets++;
        _varstack.push(std::make_shared<SyntaxTree>(SyntaxTreeId::ST_TOKEN, token));
    }
    else if(token->get_id() == TokenId::T_CLOSE_BRACKET) {
        auto lst = collapse_quotes(read_list(token));
        _varstack.push(lst);
        if(_varstack.size() == 1) {
            emit(_varstack.top());
            _varstack.pop();
        }
    }
    else {
        _varstack.push(std::make_shared<SyntaxTree>(SyntaxTreeId::ST_TOKEN, token));
    }
}


/*
 *
 */
std::shared_ptr<SyntaxTree> SyntaxParser::read_list(std::shared_ptr<Token> t) {
    std::list<std::shared_ptr<SyntaxTree>> resnodes;

    while (true) {
        if(_varstack.empty()) {
            throw ExceedClosingBracketException(*t);
        }

        auto val = _varstack.top();
        if(val->get_id() == ST_TOKEN) {
            if(val->bound_token()->get_id() == TokenId::T_OPEN_BRACKET) {
                _varstack.pop();
                brackets--;
                break;
            }
            else {
                resnodes.push_front(parse_primitive(val->bound_token()));
                _varstack.pop();
            }
        } else {
            resnodes.push_front(val);
            _varstack.pop();
        }

        auto front = resnodes.front();
        resnodes.pop_front();
        resnodes.push_front(collapse_quotes(front));
    }

    if(resnodes.empty()) {
        return std::make_shared<SyntaxTree>(SyntaxTreeId::ST_NULL, t);
    }
    else {
        return std::make_shared<SyntaxTree>(SyntaxTreeId::ST_LIST, t, resnodes.begin(), resnodes.end());
    }
}

std::shared_ptr<SyntaxTree> SyntaxParser::parse_primitive(std::shared_ptr<Token> token) {
    return std::make_shared<SyntaxTree>(SyntaxTreeId::ST_ATOM, token);
}

void SyntaxParser::handle(std::shared_ptr<Token> t) {
    accept(t);
}

std::shared_ptr<SyntaxTree> SyntaxParser::collapse_quotes(std::shared_ptr<SyntaxTree> subtree) {
    while(!_varstack.empty()) {
        auto token = _varstack.top()->bound_token();
        if(token->get_id()==TokenId::T_QUOTE) {
            _varstack.pop();
            auto res = std::list<std::shared_ptr<SyntaxTree>>{
                std::make_shared<SyntaxTree>(SyntaxTreeId::ST_QUOTE, token),
                subtree
            };
            subtree = std::make_shared<SyntaxTree>(SyntaxTreeId::ST_LIST,
                                                   token,
                                                   res.begin(),
                                                   res.end());
        }
        else
            break;
    }
    return subtree;
}



