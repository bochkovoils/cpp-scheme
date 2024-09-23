//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_FRAME_H
#define CPP_SCHEME_FRAME_H


#include <unordered_map>
#include "../lisp_structures/LispSymbol.h"

class Frame {
private:
    std::unordered_map<std::size_t, LispObject*> _map;
public:
    std::size_t size() const;
    bool has(LispSymbol* symbol) const;
    void set_symbol(LispSymbol* symbol, LispObject* obj);
    LispObject* get(LispSymbol* symbol);
};


#endif //CPP_SCHEME_FRAME_H
