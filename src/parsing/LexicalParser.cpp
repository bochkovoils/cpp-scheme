//
// Created by giantdad on 13.09.24.
//

#include <iostream>
#include <algorithm>
#include <memory>
#include "LexicalParser.h"
#include "SymbolicTable.h"


LexicalParser::LexicalParser() : _state(LexicalParserState::SKIP)
{
}

void LexicalParser::next_char(const char& cursym) {
    auto prev_state = _state;
    if(cursym == '\n') {
        _cur_line++;
        _cur_pos=0;
    }
    else {
        _cur_pos++;
    }

    if(cursym == ' ' || cursym == '\n' || cursym == '\t')   this->switch_to_skip(cursym);
    else if(cursym == '"')                                  this->handle_dq(cursym);
    else if('0' <= cursym && cursym <= '9')                 this->handle_number(cursym);
    else if(cursym == '\\')                                 this->handle_backslash(cursym);
    else if(cursym == '\'')                                 this->handle_quote(cursym);
    else if(cursym == '(')                                  this->handle_opb(cursym);
    else if(cursym == ')')                                  this->handle_cpb(cursym);
    else if(cursym == '\0')                                 this->handle_exit(cursym);
    else if(cursym == ';')                                  this->handle_comment_smb(cursym);
    else                                                    this->handle_symbol(cursym);

    if(cursym == '\0') {
        _token_pos =0;
        _token_line=0;
        _cur_line =0;
        _cur_pos=-1;
        return;
    }
}

void LexicalParser::switch_to_skip(const char &sym) {
    switch (_state) {
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _state = SKIP;
            return;
        case STRING:
            _buffer.push_back(sym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(sym);
            _state = STRING;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            _state = SKIP;
            return;
        case SKIP:
            return;
        case COMMENT:
            if(sym == '\n') { this->confirm_token(TokenId::T_EMPTY, true); _state = SKIP; }
            return;
    }
}

void LexicalParser::handle_quote(const char &cursym) {
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
            _state = STRING;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            this->confirm_token(TokenId::T_QUOTE);
            return;
        case SKIP:
            _token_pos = _cur_pos;
            _token_line = _cur_line;
            this->confirm_token(TokenId::T_QUOTE);
            return;
        case COMMENT:
            break;
    }
}

void LexicalParser::handle_number(const char &cursym) {
    switch (_state) {
        case SKIP:
            _token_pos = _cur_pos;
            _token_line = _cur_line;
            _state = LexicalParserState::NUMBER;
            _buffer.push_back(cursym);
            return;
        default:
            _buffer.push_back(cursym);
    }
}

void LexicalParser::handle_dq(const char &cursym) {
    switch (_state) {
        case STRING:
            this->confirm_token(TokenId::T_STRING);
            _state = SKIP;
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('"');
            _state = STRING;
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _state = LexicalParserState::STRING;
            _buffer.push_back(cursym);
            return;
        case TOKEN:
            _buffer.push_back(cursym);
            return;
        case SKIP:
            _token_pos = _cur_pos;
            _token_line = _cur_line;
            _state = STRING;
            return;
        case COMMENT:
            break;
    }
}

void LexicalParser::handle_symbol(const char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back(cursym);
            return;
        case SKIP:
            _token_pos = _cur_pos;
            _token_line = _cur_line;
        case NUMBER:
            _state = LexicalParserState::TOKEN;
        case TOKEN:
            _buffer.push_back(cursym);
            return;
        case COMMENT:
            break;
    }
}


void LexicalParser::handle_opb(const char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            _state = STRING;
            return;
        case SKIP:
            _token_pos = _cur_pos;
            _token_line = _cur_line;
            this->confirm_token(TokenId::T_OPEN_BRACKET, true);
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            this->confirm_token(TokenId::T_OPEN_BRACKET, true);
            _state = SKIP;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            this->confirm_token(TokenId::T_OPEN_BRACKET, true);
            return;
        case COMMENT:
            break;
    }
}

void LexicalParser::handle_cpb(const char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            _state = STRING;
            return;
        case SKIP:
            _token_pos = _cur_pos;
            _token_line = _cur_line;
            this->confirm_token(TokenId::T_CLOSE_BRACKET, true);
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            this->confirm_token(TokenId::T_CLOSE_BRACKET, true);
            _state = SKIP;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            this->confirm_token(TokenId::T_CLOSE_BRACKET, true);
            _state = SKIP;
            return;
        case COMMENT:
            break;
    }
}

void LexicalParser::handle_exit(const char &cursym) {
    switch (_state) {
        case STRING:
            this->confirm_token(TokenId::T_STRING);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            this->confirm_token(TokenId::T_STRING);
            _state = STRING;
            return;
        case SKIP:
//            this->confirm_token(TokenId::T_EMPTY);
            _state = SKIP;
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            _state = SKIP;
            return;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            _state = SKIP;
            return;
        case COMMENT:
//            this->confirm_token(TokenId::T_EMPTY, true);
            _state = SKIP;
            return;
    }
}

void LexicalParser::confirm_token(TokenId token_id, bool skip_body) {
    if(token_id == TokenId::T_NUMBER) {
        auto t = std::make_shared<Token>(token_id,
                                         std::stoi(std::string(_buffer.begin(), _buffer.end())),
                                         _token_pos,
                                         _token_line);
        emit(t);
    }
    else if(token_id == TokenId::T_SYMBOL) {
        auto t = std::make_shared<Token>(token_id,
                                         std::size_t(SymbolicTable::get().insert(std::string(_buffer.begin(), _buffer.end()))),
                                         _token_pos,
                                         _token_line);
        emit(t);
    }
    else if(token_id == TokenId::T_STRING) {
        auto t = std::make_shared<Token>(token_id,
                                         std::string(_buffer.begin(), _buffer.end()),
                                         _token_pos,
                                         _token_line);
        emit(t);
    }
    else {
        auto t = std::make_shared<Token>(token_id, _token_pos, _token_line);
        emit(t);
    }
    _token_pos = _cur_pos;
    _token_line = _cur_line;
    _buffer.clear();
}

void LexicalParser::handle_comment_smb(const char &cursym) {
    switch (_state) {
        case STRING:
            _buffer.push_back(cursym);
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            return;
        case NUMBER:
            this->confirm_token(TokenId::T_NUMBER);
            break;
        case TOKEN:
            this->confirm_token(TokenId::T_SYMBOL);
            break;
        default:
            break;
    }
    _state = COMMENT;
}

void LexicalParser::handle_backslash(const char &cursym) {
    switch (_state) {
        case STRING:
            _state = STRING_BACKSLASH;
            return;
        case STRING_BACKSLASH:
            _buffer.push_back('\\');
            _buffer.push_back(cursym);
            _state = STRING;
            return;
        case SKIP:
            _buffer.push_back(cursym);
            _state = TOKEN;
            return;
        case NUMBER:
            _buffer.push_back(cursym);
            _state = TOKEN;
            return;
        case TOKEN:
            _buffer.push_back(cursym);
            return;
        case COMMENT:
            return;
    }
}

void LexicalParser::operator<<(const char *s) {
    while (*s != '\0') {
        next_char(*s);
        s++;
    }
    next_char(*s);
}

void LexicalParser::operator<<(const std::string &s) {
    (*this) << s.c_str();
}

