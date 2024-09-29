//
// Created by giantdad on 15.09.24.
//

#include "Token.h"
#include "SymbolicTable.h"
#include <string>

Token::Token(TokenId id,
             unsigned int pos,
             unsigned int line): _id(id),
                                 _code_pos(pos),
                                 _line_pos(line) {
}

Token::Token(TokenId id): _id(id), _line_pos(0), _code_pos(0) {
}

std::string Token::get_symbol() const {
    return SymbolicTable::get().get_symbol(_symbol_id);
}

Token::Token(TokenId id, std::string &s, unsigned int pos, unsigned int line): _id(id), _string(s), _line_pos(line), _code_pos(pos) {

}

Token::Token(TokenId id, size_t s, unsigned int pos, unsigned int line): _id(id), _symbol_id(s), _code_pos(pos), _line_pos(line) {

}

Token::Token(TokenId id, int s, unsigned int pos, unsigned int line): _id(id), _value(s), _line_pos(line), _code_pos(pos) {

}

Token::Token(TokenId id, std::string &&s, unsigned int pos, unsigned int line): _id(id), _string(s), _line_pos(line), _code_pos(pos) {

}

