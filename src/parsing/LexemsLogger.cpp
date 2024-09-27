//
// Created by work on 26.09.2024.
//

#include <memory>
#include <sstream>
#include <iostream>
#include "LexemsLogger.h"

void LexemsLogger::handle(std::shared_ptr<Token> t) {
    if(t->get_id() == TokenId::T_SYMBOL) {
        _tokens.push_back(std::shared_ptr<Token>(new SymbolToken(t->get_id(),
                                                 dynamic_cast<SymbolToken const*>(t.get())->get_symbol_id(),
                                                 t->get_position(),
                                                 t->get_line())));
        return;
    }
    if(t->get_id() == TokenId::T_NUMBER) {
        _tokens.push_back(std::shared_ptr<Token>(new NumberToken(t->get_id(),
                                                                 dynamic_cast<NumberToken const*>(t.get())->get_value(),
                                                                 t->get_position(),
                                                                 t->get_line())));
        return;
    }
    if(t->get_id() == TokenId::T_STRING) {
        _tokens.push_back(std::shared_ptr<Token>(new StringToken(t->get_id(),
                                                                 dynamic_cast<StringToken const*>(t.get())->get_string(),
                                                                 t->get_position(),
                                                                 t->get_line())));
        return;
    }
    _tokens.push_back(std::make_shared<Token>(t->get_id(),
                                              t->get_position(),
                                              t->get_line()));
}

std::string get_string_for_token(Token& t) {
    if(t.get_id() == TokenId::T_STRING) {
        return std::string("\"") + dynamic_cast<StringToken*>(&t)->get_string() + std::string("\"");
    }
    if(t.get_id() == TokenId::T_SYMBOL) {
        return std::string("#") + dynamic_cast<SymbolToken*>(&t)->get_symbol();
    }
    if(t.get_id() == TokenId::T_NUMBER) {
        return std::string("$") + std::to_string(dynamic_cast<NumberToken*>(&t)->get_value());
    }
    switch (t.get_id()) {
        case TokenId::T_OPEN_BRACKET:
            return "(";
        case TokenId::T_QUOTE:
            return "'";
        case TokenId::T_CLOSE_BRACKET:
            return ")";
        default:
            throw 1;
    }
}

void LexemsLogger::show() {
    std::stringstream ss;
    ss << "Tokens: ";
    std::for_each(_tokens.begin(), _tokens.end(), [this, &ss](auto token) {
        ss << "[" << get_string_for_token(*token) << "] ";
    });
    std::cout << ss.str() << std::endl;
}

void LexemsLogger::clear() {
    _tokens.clear();
}

