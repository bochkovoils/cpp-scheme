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
    std::string             _string;
    std::size_t             _symbol_id=-1;
    int                     _value=0;
public:
    explicit Token( TokenId id,
                    unsigned int pos=0,
                    unsigned int line=0);
    explicit Token( TokenId id,
                    std::string& s,
                    unsigned int pos=0,
                    unsigned int line=0);
    explicit Token( TokenId id,
                    std::string&& s,
                    unsigned int pos=0,
                    unsigned int line=0);
    explicit Token( TokenId id,
                    std::size_t s,
                    unsigned int pos=0,
                    unsigned int line=0);
    explicit Token( TokenId id,
                    int s,
                    unsigned int pos=0,
                    unsigned int line=0);
    explicit Token(TokenId id);

    [[nodiscard]] TokenId get_id() const {return _id;}
    [[nodiscard]] unsigned int get_position() const {return _code_pos;}
    [[nodiscard]] unsigned int get_line() const {return _line_pos;}
    [[nodiscard]] std::string get_symbol() const;
    [[nodiscard]] std::size_t get_symbol_id() const { return _symbol_id;}
    [[nodiscard]] std::string get_string() const { return _string; }
    [[nodiscard]] int         get_value() const { return _value; }

    virtual ~Token()=default;
};


#endif //CPP_SCHEME_TOKEN_H
