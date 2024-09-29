//
// Created by work on 26.09.2024.
//

#include <memory>
#include <sstream>
#include <iostream>
#include "LexemsLogger.h"

void LexemsLogger::handle(std::shared_ptr<Token> t) {
    _tokens.push_back(t);
}

std::string get_string_for_token(Token& t) {
    if(t.get_id() == TokenId::T_STRING) {
        return std::string("\"") + t.get_string() + std::string("\"");
    }
    if(t.get_id() == TokenId::T_SYMBOL) {
        return std::string("#") + t.get_symbol();
    }
    if(t.get_id() == TokenId::T_NUMBER) {
        return std::string("$") + std::to_string(t.get_value());
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

