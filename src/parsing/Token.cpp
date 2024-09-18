//
// Created by giantdad on 15.09.24.
//

#include "Token.h"
#include <string>

std::hash<std::string> Token::_hash_fn= std::hash<std::string>();

Token::Token(TokenId id, const std::vector<char> &value): _id(id), _value(value.begin(), value.end()) {
    _hash = _hash_fn(_value);
}

Token::Token(TokenId id): _id(id), _value(), _hash() {
}

