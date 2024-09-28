//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_PARSEDTREELOGGER_H
#define CPP_SCHEME_PARSEDTREELOGGER_H


#include <memory>
#include "../lisp_structures/LispObjectRef.h"
#include "Observer.h"
#include "SyntaxTree.h"

class ParsedTreeLogger: public Observer<std::shared_ptr<SyntaxTree>> {
private:
    std::vector<std::shared_ptr<SyntaxTree>> _objs;
public:
    void handle(std::shared_ptr<SyntaxTree>) override;
//    void show();
//    void clear();
};


#endif //CPP_SCHEME_PARSEDTREELOGGER_H
