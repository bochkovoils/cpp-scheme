//
// Created by giantdad on 15.09.24.
//

#include "Token.h"

Token::Token(TokenId id, const std::vector<char> &value): _id(id), _value(value.begin(), value.end()) {
}

Token::Token(TokenId id): _id(id), _value() {
}
