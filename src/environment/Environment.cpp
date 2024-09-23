//
// Created by work on 23.09.2024.
//

#include "Environment.h"

#include <memory>

bool Environment::has(LispSymbol *symbol) {
    for(auto & frame : _frames) {
        if(frame->has(symbol)) {
            auto obj = frame->get(symbol);
            _frames.front()->set_symbol(symbol, obj);
            return true;
        }
    }
    return false;
}

LispObject* Environment::get(LispSymbol *symbol) {
    if(has(symbol))
        return _frames.front()->get(symbol);
    throw 1;
}

void Environment::set(LispSymbol *symbol, LispObject *obj) {
    _frames.front()->set_symbol(symbol, obj);
}

Environment::Environment(const std::shared_ptr<Frame>& addition_frame,
                         std::list<std::shared_ptr<Frame>>::iterator begin,
                         std::list<std::shared_ptr<Frame>>::iterator end): _frames(begin, end) {
    _frames.push_front(addition_frame);
}

Environment* Environment::extend() {
    return new Environment{std::make_shared<Frame>(), _frames.begin(), _frames.end()};
}

Environment::Environment() {
    _frames.push_back(std::make_shared<Frame>());
}

Environment* Environment::global_root = new Environment();
