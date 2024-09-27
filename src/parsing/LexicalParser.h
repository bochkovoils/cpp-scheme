//
// Created by giantdad on 13.09.24.
//

#ifndef CPP_SCHEME_LEXICALPARSER_H
#define CPP_SCHEME_LEXICALPARSER_H


#include <string>
#include <vector>
#include <list>
#include <set>
#include <variant>
#include <memory>
#include "Token.h"
#include "Observer.h"

enum LexicalParserState {
    STRING,             // Starts from " and stops on "
    TOKEN,              // Any symbols sequence
    NUMBER,             // Any sequence of 0-9
    SKIP,               // On skipping symbols
    STRING_BACKSLASH,   // On \" and same
    COMMENT             // On comment
};


class LexicalParser: public Observable<std::shared_ptr<Token>> {
private:
    LexicalParserState                  _state = LexicalParserState::SKIP;
    std::vector<char>                   _buffer = std::vector<char>();

    unsigned int                        _token_pos=0;
    unsigned int                        _token_line=0;
    unsigned int                        _cur_pos=-1;
    unsigned int                        _cur_line=0;

    void switch_to_skip(const char &sym);
    void handle_quote(const char &cursym);
    void handle_number(const char &cursym);
    void handle_dq(const char &cursym);
    void handle_symbol(const char &cursym);
    void handle_comment_smb(const char &cursym);
    void handle_opb(const char &cursym);
    void handle_cpb(const char &cursym);
    void handle_exit(const char &cursym);
    void handle_backslash(const char &cursym);

    void confirm_token(TokenId token_id, bool skip_body=false);

public:
    explicit LexicalParser();
    void next_char(const char&);

    void operator<<(const char* s);
    void operator<<(std::string const& s);
};


#endif //CPP_SCHEME_LEXICALPARSER_H
