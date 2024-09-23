//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_TREEPAINTER_H
#define CPP_SCHEME_TREEPAINTER_H

#include "../parsing/TreeBuilder.h"
#include "../lisp_structures/LispNull.h"
#include "../lisp_structures/LispCell.h"
#include "../lisp_structures/LispString.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispSymbol.h"
#include "../lisp_structures/StructuresVisitor.h"

class TreePainter: public StructuresVisitor {
private:
    std::stack<std::tuple<int, LispObject*>> _stack;
    std::list<std::tuple<int, LispObject*>> _collect;
    std::string                             _buffer_visitor;
public:
    void paint_tree(LispObject* node);

    virtual void apply(LispSymbol*) override;
    virtual void apply(LispNumber*) override;
    virtual void apply(LispString*) override;
    virtual void apply(LispCell*  ) override;
    virtual void apply(LispNull*  ) override;

    std::string get_spaces(unsigned int spaces);
    void collect(LispObject* node);
    std::list<LispObject*> collect_list(LispCell* node);
};


#endif //CPP_SCHEME_TREEPAINTER_H
