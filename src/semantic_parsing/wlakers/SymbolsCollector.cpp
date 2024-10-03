//
// Created by work on 30.09.2024.
//

#include <algorithm>
#include "SymbolsCollector.h"

#include "../semantic_objects/Number.h"
#include "../semantic_objects/BoundVariable.h"
#include "../semantic_objects/Expression.h"
#include "../semantic_objects/FnParameter.h"
#include "../semantic_objects/DefineSymbol.h"
#include "../semantic_objects/DefineProcedure.h"
#include "../semantic_objects/If.h"
#include "../semantic_objects/Quote.h"
#include "../semantic_objects/Procedure.h"


void S_Table::init(std::size_t i) {
    _inited.insert(i);
}


void S_Table::require(size_t i) {
    if(_inited.count(i)) return;
    _required.insert(i);
}

std::set<std::size_t> S_Table::initialized_symbols() {
    return _inited;
}

std::set<std::size_t> S_Table::required_symbols() {
    return _required;
}

void S_Table::insert_required(std::set<std::size_t> &reqs) {
    std::for_each(reqs.begin(), reqs.end(), [this](auto o){
        require(o);
    });
}
void S_Table::insert_required(std::set<std::size_t> &&reqs) {
    std::for_each(reqs.begin(), reqs.end(), [this](auto o){
        require(o);
    });
}

S_Table::S_Table() = default;


void SymbolsCollector::walk(If *o) {
    auto n = S_Table(std::set<std::size_t>(), _table_stack.back().initialized_symbols());
    _table_stack.push_back(n);
    S_Table& cur = _table_stack.back();

    o->condition()->apply_walker(this);
    o->on_true()->apply_walker(this);
    o->on_false()->apply_walker(this);

    o->set_symbols_table(cur);
    S_Table cur_ = _table_stack.back();
    _table_stack.pop_back();
    _table_stack.back().insert_required(cur_.required_symbols());
}

void SymbolsCollector::walk(Number *o) {}
void SymbolsCollector::walk(String *o) {}

void SymbolsCollector::walk(BoundVariable *o) {
    _table_stack.back().require(o->get_symbol_id());
}

void SymbolsCollector::walk(Expression *o) {
    auto s = S_Table(std::set<std::size_t>(), _table_stack.back().initialized_symbols());

    _table_stack.push_back(s);
    std::for_each(o->elements().begin(), o->elements().end(), [this](std::shared_ptr<SemanticObject> subo) {
        subo->apply_walker(this);
    });
    o->set_symbols_table(_table_stack.back());
    s = _table_stack.back();
    _table_stack.pop_back();
    _table_stack.back().insert_required(s.required_symbols());

}

void SymbolsCollector::walk(FnParameter *o) {
    _table_stack.back().init(o->get_symbol_id());
}

void SymbolsCollector::walk(DefineSymbol *o) {
    o->get_eval_expression()->apply_walker(this);
    _table_stack.back().init(o->get_symbol_id());
}

void SymbolsCollector::walk(DefineProcedure *o) {
    _table_stack.back().init(o->get_symbol_id());
    auto stable = S_Table(std::set<std::size_t>(), _table_stack.back().initialized_symbols());
    _table_stack.push_back(stable);
    o->get_procedure()->apply_walker(this);
    stable = _table_stack.back();
    o->set_symbols_table(stable);
    _table_stack.pop_back();
    _table_stack.back().insert_required(stable.required_symbols());
}

void SymbolsCollector::walk(Procedure *o) {
    auto stable = S_Table(std::set<std::size_t>(), _table_stack.back().initialized_symbols());
    _table_stack.push_back(stable);
    auto fnparams = o->parameters();
    std::for_each(fnparams.begin(), fnparams.end(), [this](std::shared_ptr<FnParameter> fp){
        fp->apply_walker(this);
    });
    o->body()->apply_walker(this);
    stable = _table_stack.back();
    o->set_symbols_table(stable);
    _table_stack.pop_back();
    _table_stack.back().insert_required(stable.required_symbols());
}

void SymbolsCollector::walk(Quote *o) {

}

SymbolsCollector::SymbolsCollector() {
    _table_stack.emplace_back();
}
