//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPSTRING_H
#define CPP_SCHEME_LISPSTRING_H


#include "LispObject.h"

class LispString: public LispObject {
public:
    void apply_visitor(StructuresVisitor *visitor) override;
};


#endif //CPP_SCHEME_LISPSTRING_H
