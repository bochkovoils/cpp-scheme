//
// Created by giantdad on 15.09.24.
//

#ifndef CPP_SCHEME_TOKEN_H
#define CPP_SCHEME_TOKEN_H

#include <string>
#include <vector>

enum TokenId {
    T_SYMBOL,
    T_NUMBER,
    T_STRING,
    T_OPEN_BRACKET,
    T_CLOSE_BRACKET,
    T_QUOTE,
    T_EMPTY
};

class Token {
private:
    TokenId                 _id;
    unsigned int            _code_pos;
    unsigned int            _line_pos;
public:
    explicit Token( TokenId id,
                    unsigned int pos=0,
                    unsigned int line=0);
    explicit Token(TokenId id);

    [[nodiscard]] TokenId get_id() const {return _id;}
    [[nodiscard]] unsigned int get_position() const {return _code_pos;}
    [[nodiscard]] unsigned int get_line() const {return _line_pos;}

    virtual ~Token()=default;
};

class SymbolToken: public Token {
private:
    std::size_t _symbol_id;
public:
    SymbolToken(TokenId id,
                std::size_t symbol_id,
                unsigned int pos,
                unsigned int line);

    [[nodiscard]] std::string get_symbol() const;
    [[nodiscard]] std::size_t get_symbol_id() const;
};

class NumberToken: public Token {
private:
    int _value;
public:
    NumberToken(TokenId id, int value, unsigned int pos, unsigned int line);
    [[nodiscard]] int get_value() const;
};

class StringToken: public Token {
private:
    std::string _value;
public:
    StringToken(TokenId id, std::string value, unsigned int pos, unsigned int line);
    [[nodiscard]] std::string get_string() const;
};


#endif //CPP_SCHEME_TOKEN_H
