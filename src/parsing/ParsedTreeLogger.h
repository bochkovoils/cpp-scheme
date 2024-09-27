//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_PARSEDTREELOGGER_H
#define CPP_SCHEME_PARSEDTREELOGGER_H


#include "../lisp_structures/LispObjectRef.h"
#include "Observer.h"

class ParsedTreeLogger: public Observer<LispObjectRef> {
private:
    std::vector<LispObjectRef> _objs;
public:
    void handle(LispObjectRef) override;
//    void show();
//    void clear();
};


#endif //CPP_SCHEME_PARSEDTREELOGGER_H
