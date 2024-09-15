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
    TokenId     _id;
    std::string _value;
public:
    Token(TokenId id, std::vector<char> const& value);
    explicit Token(TokenId id);

    [[nodiscard]] TokenId get_id() const {return _id;}
    [[nodiscard]] std::string const& get_value() const {return _value;}
};


#endif //CPP_SCHEME_TOKEN_H
