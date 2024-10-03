//
// Created by work on 03.10.2024.
//

#ifndef CPP_SCHEME_VARTABLE_H
#define CPP_SCHEME_VARTABLE_H


#include <map>
#include <memory>
#include "../lisp_structures/LispObject.h"
#include "../lisp_structures/LispObjectRef.h"

class LinkBox {
private:
    LispObjectRef   _ref;
    bool            _is_bound;
public:
    LinkBox(): _ref(), _is_bound(false) {}
    LinkBox(LispObjectRef ref): _ref(ref), _is_bound(true) {}
    void assign(LispObjectRef ref) {_ref = MovRef{ref};}
    LispObjectRef get() {return _ref;}
};

class VarTable {
private:
    std::map<std::size_t, std::shared_ptr<LinkBox>>   _vars;
public:
    VarTable()=default;
    explicit VarTable(std::map<std::size_t, std::shared_ptr<LinkBox>>& map);
    void define(std::size_t symbol_id, LispObjectRef obj);
    LispObjectRef get(std::size_t symbol_id);
    void set(std::size_t symbol_id, LispObjectRef obj);
    bool contains(std::size_t symbol_id);
    std::shared_ptr<VarTable> clone();

    void extends(std::map<size_t, LispObjectRef> map);
};


#endif //CPP_SCHEME_VARTABLE_H
