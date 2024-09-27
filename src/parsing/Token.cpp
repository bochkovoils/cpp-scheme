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

SymbolToken::SymbolToken(TokenId id, std::size_t symbol_id, unsigned int pos, unsigned int line): Token(id, pos, line), _symbol_id(symbol_id) {

}

std::string SymbolToken::get_symbol() const {
    return SymbolicTable::get().get_symbol(_symbol_id);
}

std::size_t SymbolToken::get_symbol_id() const {
    return _symbol_id;
}

NumberToken::NumberToken(TokenId id, int value, unsigned int pos, unsigned int line): Token(id, pos, line), _value(value) {

}

int NumberToken::get_value() const {
    return _value;
}


StringToken::StringToken(TokenId id, std::string value, unsigned int pos, unsigned int line)
    : Token(id, pos, line), _value(std::move(value)) {

}

std::string StringToken::get_string() const {
    return _value;
}

//TokenStruct::TokenStruct(TokenStruct const &aStruct) {
//    if(aStruct.id == TokenId::T_SYMBOL) {
//        id = aStruct.id;
//        symbolToken = aStruct.symbolToken;
//        return;
//    }
//    if(aStruct.id == TokenId::T_NUMBER) {
//        id = aStruct.id;
//        numberToken = aStruct.numberToken;
//        return;
//    }
//    if(aStruct.id == TokenId::T_STRING) {
//        id = aStruct.id;
//        stringToken = aStruct.stringToken;
//        return;
//    }
//    id = aStruct.id;
//    token = aStruct.token;
//}
