//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_SYMBOLSCOLLECTOR_H
#define CPP_SCHEME_SYMBOLSCOLLECTOR_H

#include <map>
#include <list>
#include <set>
#include "SemanticWalker.h"

//enum VarBindType {
//    USED,
//    DEFINED
//};
//
//class VarBinding {
//private:
//    std::size_t _id;
//    VarBindType _type;
//public:
//    explicit VarBinding(std::size_t id, VarBindType type=USED): _id(id), _type(type) {};
//    VarBindType get_type() {return _type;}
//    std::size_t get_id() {return _id;}
//
//    void set_id(std::size_t id) {_id=id;}
//    void set_type(VarBindType type){ _type = type; }
//};

class S_Table {
private:
    std::set<std::size_t> _required;
    std::set<std::size_t> _inited;
public:
    S_Table();
    explicit S_Table(std::set<std::size_t>& required): _required(required), _inited() {}
    explicit S_Table(std::set<std::size_t>&& required): _required(required), _inited() {}
    explicit S_Table(std::set<std::size_t>&& required, std::set<std::size_t>&& inited): _required(required), _inited(inited) {}
    void init(std::size_t);
    void require(std::size_t);
    std::set<std::size_t> initialized_symbols();
    std::set<std::size_t> required_symbols();
    void insert_required(std::set<std::size_t>& reqs);
    void insert_required(std::set<std::size_t>&& reqs);
};

class SymbolsCollector: public SemanticWalker {
private:
    std::list<S_Table> _table_stack;
public:
    SymbolsCollector();

    void walk(If* o              ) override;
    void walk(Number* o          ) override;
    void walk(String* o          ) override;
    void walk(BoundVariable* o   ) override;
    void walk(Expression* o      ) override;
    void walk(FnParameter* o     ) override;
    void walk(DefineSymbol* o    ) override;
    void walk(DefineProcedure* o ) override;
    void walk(Procedure* o       ) override;
    void walk(Quote* o           ) override;
};


#endif //CPP_SCHEME_SYMBOLSCOLLECTOR_H
