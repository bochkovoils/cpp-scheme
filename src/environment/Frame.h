//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_FRAME_H
#define CPP_SCHEME_FRAME_H


#include <unordered_map>
#include "../lisp_structures/LispSymbol.h"

class Frame {
private:
    std::unordered_map<std::size_t, LispObjectRef> _map;
public:
    std::size_t size() const;
    bool has(LispObjectRef symbol) const;
    void set_symbol(LispObjectRef symbol, LispObjectRef obj);
    LispObjectRef get(LispObjectRef symbol);
};


#endif //CPP_SCHEME_FRAME_H
