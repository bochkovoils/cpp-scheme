//
// Created by giantdad on 13.09.24.
//

#include "Parser.h"


Parser::Parser(const char *string_ptr) : _current_position(string_ptr),
                                         _state(ParserState::SKIP)
{
}

void Parser::next_char() {
    char cursym = *_current_position;
    if(cursym == ' ' || cursym == '\n' || cursym == '\t')   this->switch_to_skip(cursym);
    else if(cursym == '"')                                  this->handle_dq(cursym);
    else if('0' <= cursym && cursym <= '9')                 this->handle_number(cursym);
    else if(cursym == '\'')                                 this->handle_quote(cursym);
    else if(cursym == '(')                                  this->handle_opb(cursym);
    else if(cursym == ')')                                  this->handle_cpb(cursym);
    else if(cursym == '\0')                                 return;
    else if(cursym == ';')                                  this->handle_comment_smb(cursym);
    else                                                    this->handle_symbol(cursym);
    _current_position++;
}

void Parser::switch_to_skip(char &cursym) {
    switch (_state) {
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _state = SKIP;
            return;
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            _state = SKIP;
            return;
        case SKIP:
            return;
        case COMMENT:
            if(cursym == '\n') _state = SKIP;
            return;
    }
}

void Parser::handle_quote(char& cursym) {
    switch (_state) {
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            this->confirm_token(TokenId::T_QUOTE);
            return;
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            this->confirm_token(TokenId::T_QUOTE);
            return;
        case SKIP:
            this->confirm_token(TokenId::T_QUOTE);
            return;
    }
}

void Parser::handle_number(char& cursym) {
    switch (_state) {
        case SKIP:
            _state = ParserState::NUMBER;
            _buffer.push_back(cursym);
            return;
        default:
            _buffer.push_back(cursym);
    }
}

void Parser::handle_dq(char& cursym) {
    switch (_state) {
        case STRING:
            _state = STRING_BACKSLASH;
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('"');
            _state = STRING;
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _state = ParserState::STRING;
            _buffer.push_back(cursym);
            return;
        case TOKEN:
            _buffer.push_back(cursym);
            return;
        case SKIP:
            _state = STRING;
            return;
    }
}

void Parser::handle_symbol(char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        case SKIP:
        case NUMBER:
            _state = ParserState::TOKEN;
        case TOKEN:
            _buffer.push_back(cursym);
            return;
    }
}


void Parser::handle_opb(char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        case SKIP:
            _tokens.emplace_back(TokenId::T_OPEN_BRACKET);
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _tokens.emplace_back(TokenId::T_OPEN_BRACKET);
            _state = SKIP;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            _tokens.emplace_back(TokenId::T_OPEN_BRACKET);
            _state = SKIP;
            return;
    }
}

void Parser::handle_cpb(char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        case SKIP:
            _tokens.emplace_back(TokenId::T_CLOSE_BRACKET);
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _tokens.emplace_back(TokenId::T_CLOSE_BRACKET);
            _state = SKIP;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            _tokens.emplace_back(TokenId::T_CLOSE_BRACKET);
            _state = SKIP;
            return;
    }
}

void Parser::confirm_token(TokenId token_id) {
    _tokens.emplace_back(token_id, _buffer);
    _buffer.clear();
}

Token Parser::next_token() {
    if(!this->_tokens.empty()) {
        auto it = this->_tokens.begin();
        auto res = *it;
        _tokens.erase(it);
        return res;
    }
    if(this->is_end())
        throw 1;
    else {
        while(_tokens.empty()) this->next_char();
        return next_token();
    }
}

bool Parser::is_end() {
    return *_current_position == '\0';
}

bool Parser::has_tokens() {
    return !_tokens.empty();
}

void Parser::handle_comment_smb(char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        default:
            _state = COMMENT;
            return;
    }
}

void Parser::handle_next_string(char &) {

}



