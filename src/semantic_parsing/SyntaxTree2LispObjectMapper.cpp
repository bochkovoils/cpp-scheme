//
// Created by work on 29.09.2024.
//

#include <algorithm>
#include "SyntaxTree2LispObjectMapper.h"
#include "../lisp_structures/LispSymbol.h"
#include "../lisp_structures/LispString.h"
#include "../lisp_structures/LispNumber.h"
#include "../lisp_structures/LispCell.h"
#include "../parsing/SymbolicTable.h"

LispObjectRef SyntaxTree2LispObjectMapper::map(SyntaxTree *tree) {
    if(tree->get_id() == SyntaxTreeId::ST_ATOM) {
        switch (tree->bound_token()->get_id()) {
            case TokenId::T_SYMBOL:
                return LispObjectRef(new LispSymbol(tree->bound_token()->get_symbol_id()));
            case TokenId::T_STRING:
                return LispObjectRef(new LispString(tree->bound_token()->get_string()));
            case TokenId::T_NUMBER:
                return LispObjectRef(new LispNumber(tree->bound_token()->get_value()));
            default:
                throw 100;
        }
    }
    if(tree->get_id() == SyntaxTreeId::ST_QUOTE) {
        return LispSymbol::quote;
    }
    if(tree->get_id() == SyntaxTreeId::ST_NULL) {
        return LispNull::get();
    }
    if(tree->get_id() == SyntaxTreeId::ST_LIST) {
        auto res = std::vector<LispObjectRef>();
        auto children = tree->children();
        std::for_each(children.begin(), children.end(), [this, &res](auto o){
            res.push_back(map(o.get()));
        });
        return LispCell::from_vector(res.begin(), res.end());
    }
    throw 101;
}
