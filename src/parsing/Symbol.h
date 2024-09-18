//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_SYMBOL_H
#define CPP_SCHEME_SYMBOL_H


#include <string>
#include "AbstractNode.h"

class Symbol: public AbstractNode {
public:
    static Symbol QUOTE_SYMBOL;
private:
    std::string _text;
public:
    explicit Symbol(std::string text);
    AbstractNodeType get_type() override {return AbstractNodeType::A_SYMBOL;}

    [[nodiscard]] std::string get_text() const;
};

#endif //CPP_SCHEME_SYMBOL_H
