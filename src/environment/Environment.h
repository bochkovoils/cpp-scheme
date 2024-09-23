//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_ENVIRONMENT_H
#define CPP_SCHEME_ENVIRONMENT_H


#include <list>
#include <memory>
#include "Frame.h"

class Environment {
public:
    static Environment* global_root;
private:
    std::list<std::shared_ptr<Frame>> _frames;
public:
    Environment();
    Environment(const std::shared_ptr<Frame>& addition_frame,
                std::list<std::shared_ptr<Frame>>::iterator begin,
                std::list<std::shared_ptr<Frame>>::iterator end);

    bool has(LispSymbol* symbol);
    LispObject* get(LispSymbol* symbol);
    void set(LispSymbol* symbol, LispObject* obj);
    Environment* extend();
};


#endif //CPP_SCHEME_ENVIRONMENT_H
