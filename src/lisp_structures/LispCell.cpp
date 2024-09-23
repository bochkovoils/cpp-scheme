//
// Created by work on 18.09.2024.
//

#include "LispCell.h"
#include "LispNull.h"
#include "StructuresVisitor.h"

LispCell::LispCell(LispObject * head, LispObject* rest): _head(head), _rest(rest) {

}
LispCell::LispCell(): _head(LispNull::get()), _rest(LispNull::get()) {}

LispObject* LispCell::head() {return _head;}
LispObject* LispCell::rest() {return _rest;}

void LispCell::set_head(LispObject *o) {_head = o;}
void LispCell::set_rest(LispObject *r) {_rest = r;}

LispCell *LispCell::from_list(std::list<LispObject *>::iterator begin, std::list<LispObject *>::iterator end) {
    if(begin == end) return new LispCell();

    auto result = new LispCell(*begin++, LispNull::get());
    auto current = result;
    while (begin != end) {
        auto next = new LispCell(*begin++, LispNull::get());
        current->_rest = next;
        current = next;
    }
    return result;
}


void LispCell::apply_visitor(StructuresVisitor *visitor) {
    return visitor->apply(this);
}
