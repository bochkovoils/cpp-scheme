//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_EXCEEDCLOSINGBRACKETEXCEPTION_H
#define CPP_SCHEME_EXCEEDCLOSINGBRACKETEXCEPTION_H


#include "../parsing/Token.h"

class ExceedClosingBracketException: public std::exception {
private:
    Token _token;
public:
    explicit ExceedClosingBracketException(Token token);
};


#endif //CPP_SCHEME_EXCEEDCLOSINGBRACKETEXCEPTION_H
