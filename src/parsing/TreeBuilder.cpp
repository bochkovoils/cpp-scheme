//
// Created by work on 17.09.2024.
//

#include <algorithm>
#include <iostream>
#include "TreeBuilder.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispSymbol.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispString.h"

TreeBuilder::TreeBuilder(Parser *parser): _parser(parser) {

}

bool TreeBuilder::is_end() {
    return _parser->is_end() && !_parser->has_tokens();
}


LispObjectRef TreeBuilder::parse_all() {
    if(!_varstack.empty()) {
        return _varstack.top();
    }
    while(!is_end()) {
        Token token = _parser->next_token();

        if(token.get_id() == TokenId::T_CLOSE_BRACKET) {
            read_list();
        }
        else {
            _varstack.push(LispObjectRef(new TokenWrapper(token)));
        }
    }
//    std::cout << "In varstack.top" << std::endl;
//    std::cout << std::get<Token>(_varstack.top()).get_id() << std::endl;
    if(_varstack.empty()) return {};
    return _varstack.top();
}

void TreeBuilder::read_list() {
    std::list<LispObjectRef> resnodes;

    while (true) {
        auto back_val = _varstack.top();
        if(back_val.is<TokenWrapper>()) {
            auto token = back_val.as<TokenWrapper>()->get_token();
            if(token.get_id() == TokenId::T_OPEN_BRACKET) {
                _varstack.pop();
                break;
            }
            if(token.get_id() == TokenId::T_QUOTE) {
                auto next_sym = resnodes.front();
                resnodes.pop_front();

                auto quoted = make_list(LispSymbol::quote, next_sym);

                resnodes.push_front(quoted);
            } else {
                resnodes.push_front(parse_primitive(token));
            }
        } else {
            resnodes.push_front(back_val);
        }
        _varstack.pop();
    }

    if(resnodes.empty()) {
        _varstack.push(LispNull::get());
    }
    else {
        _varstack.push(LispCell::from_list(resnodes.begin(), resnodes.end()));
    }
}

LispObjectRef TreeBuilder::parse_primitive(const Token &token) {
    if(token.get_id() == TokenId::T_STRING)
        return LispObjectRef(new LispString(token.get_value()));
    if(token.get_id() == TokenId::T_NUMBER)
        return LispObjectRef(new LispNumber(token.get_value()));
    if(token.get_id() == TokenId::T_SYMBOL)
        return LispObjectRef(new LispSymbol(token.get_value()));
    throw 1;
}

