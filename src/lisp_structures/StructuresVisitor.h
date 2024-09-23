//
// Created by work on 23.09.2024.
//

#ifndef CPP_SCHEME_STRUCTURESVISITOR_H
#define CPP_SCHEME_STRUCTURESVISITOR_H

#include "LispSymbol.h"
#include "LispNumber.h"
#include "LispString.h"
#include "LispCell.h"
#include "LispNull.h"

class StructuresVisitor {
public:
    virtual void apply(LispSymbol*)=0;
    virtual void apply(LispNumber*)=0;
    virtual void apply(LispString*)=0;
    virtual void apply(LispCell*  )=0;
    virtual void apply(LispNull*  )=0;
};


#endif //CPP_SCHEME_STRUCTURESVISITOR_H
