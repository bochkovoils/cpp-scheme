//
// Created by work on 29.09.2024.
//

#ifndef CPP_SCHEME_SYNTAXTREE2LISPOBJECTMAPPER_H
#define CPP_SCHEME_SYNTAXTREE2LISPOBJECTMAPPER_H


#include "../lisp_structures/LispObjectRef.h"
#include "../parsing/SyntaxTree.h"

class SyntaxTree2LispObjectMapper {
public:
    LispObjectRef map(SyntaxTree*);
};


#endif //CPP_SCHEME_SYNTAXTREE2LISPOBJECTMAPPER_H
