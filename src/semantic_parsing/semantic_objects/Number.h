//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_NUMBER_H
#define CPP_SCHEME_NUMBER_H


#include <memory>
#include "SemanticObject.h"
#include "../../parsing/Token.h"

class Number: public SemanticObject {
private:
    std::shared_ptr<Token> _t;
    int _value;
public:
    Number(int value, std::shared_ptr<Token> token);
    std::string apply_logger(SemanticLogger* logger, std::string& spaces) override;
    int get_value() {return _value;}
};


#endif //CPP_SCHEME_NUMBER_H
