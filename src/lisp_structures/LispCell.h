//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPCELL_H
#define CPP_SCHEME_LISPCELL_H


#include <list>
#include "LispObject.h"

class LispCell: public LispObject {
private:
    LispObject* _head;
    LispObject* _rest;

public:
    static LispCell* from_list( std::list<LispObject*>::iterator begin,
                                std::list<LispObject*>::iterator end);

    LispCell();
    LispCell(LispObject *, LispObject *);

    LispObject* head();
    LispObject* rest();

    void set_head(LispObject*);
    void set_rest(LispObject*);

    void apply_visitor(StructuresVisitor *visitor) override;
};


#endif //CPP_SCHEME_LISPCELL_H
