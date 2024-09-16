//
// Created by giantdad on 13.09.24.
//

#ifndef CPP_SCHEME_PARSER_H
#define CPP_SCHEME_PARSER_H


#include <string>
#include <vector>
#include <list>
#include "Token.h"

enum ParserState {
    STRING,             // Starts from " and stops on "
    TOKEN,              // Any symbols sequence
    NUMBER,             // Any sequence of 0-9
    SKIP,               // On skipping symbols
    STRING_BACKSLASH,   // On \" and same
    COMMENT             // On comment
};

class Parser {
private:
    ParserState         _state = ParserState::SKIP;
    const char*         _current_position = nullptr;
    std::vector<char>   _buffer = std::vector<char>();
    std::list<Token>    _tokens = std::list<Token>();
public:
    explicit Parser(const char* string_ptr);
    void next_char();
    Token next_token();
    bool is_end();
    bool has_tokens();

    void switch_to_skip(char &sym);
    void handle_quote(char &cursym);
    void handle_number(char &cursym);
    void handle_dq(char &cursym);
    void handle_symbol(char &cursym);
    void handle_comment_smb(char &cursym);
    void handle_next_string(char &cursym);
    void handle_opb(char &cursym);
    void handle_cpb(char &cursym);

    void confirm_token(TokenId token_id, bool skip_body=false);

    void handle_exit(char &cursym);

    void handle_backslash(char &cursym);
};


#endif //CPP_SCHEME_PARSER_H
