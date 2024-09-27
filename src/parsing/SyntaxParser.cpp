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

        std::list<LispObjectRef> res;
        res.push_front(parse_primitive(token));
        collapse_quotes(res);
        _varstack.push(res.front());

        if(_varstack.size() == 1) {
            emit(_varstack.top());
            _varstack.pop();
        }
    }
    else if(token->get_id() == TokenId::T_OPEN_BRACKET) {
        brackets++;
        _varstack.push(LispObjectRef(new TokenWrapper(token)));
    }
    else if(token->get_id() == TokenId::T_CLOSE_BRACKET) {
        std::list<LispObjectRef> res;
        read_list(*token);
        res.push_front(_varstack.top());
        _varstack.pop();
        collapse_quotes(res);
        _varstack.push(res.front());
        if(_varstack.size() == 1) {
            emit(_varstack.top());
            _varstack.pop();
        }
    }
    else {
        _varstack.push(LispObjectRef(new TokenWrapper(token)));
    }
}


/*
 *
 */
void SyntaxParser::read_list(Token const& t) {
    std::list<LispObjectRef> resnodes;

    while (true) {
        if(_varstack.empty()) {
            throw ExceedClosingBracketException(t);
        }

        auto back_val = _varstack.top();
        if(back_val.is<TokenWrapper>()) {
            auto token = back_val.as<TokenWrapper>()->get_token();
            if(token->get_id() == TokenId::T_OPEN_BRACKET) {
                _varstack.pop();
                brackets--;
                break;
            }
            else {
                resnodes.push_front(parse_primitive(token));
                _varstack.pop();
            }
        } else {
            resnodes.push_front(back_val);
            _varstack.pop();
        }
        collapse_quotes(resnodes);
    }

    if(resnodes.empty()) {
        _varstack.push(LispNull::get());
    }
    else {
        _varstack.push(LispCell::from_list(resnodes.begin(), resnodes.end()));
    }
}

LispObjectRef SyntaxParser::parse_primitive(std::shared_ptr<Token> token) {
    if(token->get_id() == TokenId::T_STRING)
        return LispObjectRef(new LispString(dynamic_cast<StringToken const*>(token.get())->get_string()));
    if(token->get_id() == TokenId::T_NUMBER)
        return LispObjectRef(new LispNumber(dynamic_cast<NumberToken const*>(token.get())->get_value()));
    if(token->get_id() == TokenId::T_SYMBOL)
        return LispObjectRef(new LispSymbol(dynamic_cast<SymbolToken const*>(token.get())->get_symbol_id()));
    throw 1;
}

void SyntaxParser::handle(std::shared_ptr<Token> t) {
    accept(t);
}

void SyntaxParser::collapse_quotes(std::list<LispObjectRef>& resnodes) {
    while(!_varstack.empty()) {
        if(_varstack.top().is<TokenWrapper>() && _varstack.top().as<TokenWrapper>()->get_token()->get_id() == TokenId::T_QUOTE) {
            if(resnodes.empty()) throw 1;
            auto next_sym = resnodes.front();
            resnodes.pop_front();
            auto quoted = make_list(LispSymbol::quote, next_sym);
            resnodes.push_front(quoted);
            _varstack.pop();
        }
        else
            return;
    }
}



