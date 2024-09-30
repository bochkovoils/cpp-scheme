//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_STACKFRAME_H
#define CPP_SCHEME_STACKFRAME_H


#include <map>
#include "../lisp_structures/LispObjectRef.h"

class StackFrame {
public:
    int get_position() const {return 0;}
    std::map<std::size_t, LispObjectRef> table() {return {};}
};


#endif //CPP_SCHEME_STACKFRAME_H
