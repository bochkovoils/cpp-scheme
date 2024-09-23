//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_STRINGPAINTER_H
#define CPP_SCHEME_STRINGPAINTER_H


#include "../lisp_structures/StructuresVisitor.h"

class StringPainter: public StructuresVisitor {
public:
    virtual void apply(LispSymbol*) override;
    virtual void apply(LispNumber*) override;
    virtual void apply(LispString*) override;
    virtual void apply(LispCell*  ) override;
    virtual void apply(LispNull*  ) override;
};


#endif //CPP_SCHEME_STRINGPAINTER_H
