//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_STRING_H
#define CPP_SCHEME_STRING_H


#include <string>
#include <memory>
#include "../../parsing/Token.h"
#include "SemanticObject.h"

class String: public SemanticObject {
private:
    std::shared_ptr<Token>  _token;
    std::string             _string;
public:
    String(std::string string, std::shared_ptr<Token> token);
    std::string apply_logger(SemanticLogger* logger, std::string& spaces) override;
    std::string get_string() {return _string;}
};


#endif //CPP_SCHEME_STRING_H
