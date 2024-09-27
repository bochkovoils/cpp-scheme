//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_TREEPAINTER_H
#define CPP_SCHEME_TREEPAINTER_H

#include "../parsing/SyntaxParser.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispString.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispSymbol.h"
#include "StringMapper.h"

class TreePainter: public StringMapper {
private:
    std::stack<std::tuple<int, LispObjectRef>> _stack;
    std::list<std::tuple<int, LispObjectRef>> _collect;
    std::string                             _buffer_visitor;
public:
    virtual std::string map(LispSymbol*);
    virtual std::string map(LispCell*);
    virtual std::string map(LispNumber*);
    virtual std::string map(LispString*);
    virtual std::string map(LispNull*);
    virtual std::string map(LispOperation*);

    std::string get_spaces(unsigned int spaces);
    void collect(LispObjectRef& node);
    std::list<LispObjectRef> collect_list(LispCell* node);
    void paint(LispObjectRef ref);
};


#endif //CPP_SCHEME_TREEPAINTER_H
