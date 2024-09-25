//
// Created by work on 25.09.2024.
//

#ifndef CPP_SCHEME_STRINGMAPPER_H
#define CPP_SCHEME_STRINGMAPPER_H


#include <string>
#include "../lisp_structures/LispSymbol.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispString.h"
#include "../lisp_structures/LispOperation.h"

class StringMapper {
public:
    virtual std::string map(LispSymbol*)=0;
    virtual std::string map(LispCell*)=0;
    virtual std::string map(LispNumber*)=0;
    virtual std::string map(LispString*)=0;
    virtual std::string map(LispNull*)=0;
    virtual std::string map(LispOperation*)=0;
};


#endif //CPP_SCHEME_STRINGMAPPER_H
