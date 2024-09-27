//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_LEXEMSLOGGER_H
#define CPP_SCHEME_LEXEMSLOGGER_H


#include <list>
#include <variant>
#include <memory>
#include "Token.h"
#include "Observer.h"

class LexemsLogger: public Observer<std::shared_ptr<Token>> {
private:
    std::vector<std::shared_ptr<Token>> _tokens;
public:
    void handle(std::shared_ptr<Token>) override;
    void show();
    void clear();
};


#endif //CPP_SCHEME_LEXEMSLOGGER_H
