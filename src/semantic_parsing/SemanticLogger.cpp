//
// Created by work on 28.09.2024.
//

#include <sstream>
#include <algorithm>
#include "SemanticLogger.h"
#include "../parsing/SymbolicTable.h"

std::string SemanticLogger::get(If *o, std::string& spaces) {
    auto newspaces = spaces + std::string("    ");
    auto cond = o->condition()->apply_logger(this, newspaces);
    auto ontrue = o->on_true()->apply_logger(this, newspaces);
    auto onfalse = newspaces + std::string("()\n");
    if(o->on_false().get())
        onfalse = o->on_false()->apply_logger(this, newspaces);

    std::stringstream ss;
    ss  << spaces   << "IF:  " << get_parameters(o) << "\n"
                    << cond
                    << ontrue
                    << onfalse;
    return ss.str();
}

std::string SemanticLogger::get(Number *o, std::string &s) {
    return s + "NUMBER:" + std::to_string(o->get_value()) + "\n";
}

std::string SemanticLogger::get(String *o, std::string &s) {
    return s + "STRING: \"" + o->get_string() + "\"\n";
}

std::string SemanticLogger::get(BoundVariable *o, std::string &s) {
    return s + "BOUNDVAR: " + std::to_string(o->get_symbol_id()) + "#" + SymbolicTable::get().get_symbol(o->get_symbol_id()) + "\n";
}

std::string SemanticLogger::get(Expression *o, std::string &s) {
    auto newspaces = s + "    ";
    auto elems = o->elements();
    std::stringstream ss;
    ss << s << "EXPRESSION:   " << get_parameters(o) << "\n";
    std::for_each(elems.begin(), elems.end(), [this, &ss, &newspaces](auto o){
        ss << o->apply_logger(this, newspaces);
    });
    return ss.str();
}

std::string SemanticLogger::get(FnParameter *o, std::string &s) {
    std::stringstream ss;
    ss << s << "FN_PARAM: " << SymbolicTable::get().get_symbol(o->get_symbol_id()) << "\n";
    return ss.str();
}

std::string SemanticLogger::get(DefineSymbol *o, std::string &s) {
    std::string newspaces = s + "    ";
    std::stringstream ss;
    ss << s << "DEFSYM: " << SymbolicTable::get().get_symbol(o->get_symbol_id()) << "\n";
    ss << o->get_eval_expression()->apply_logger(this, newspaces);
    return ss.str();
}

std::string SemanticLogger::get(DefineProcedure *o, std::string &s) {
    auto argspaces = s + "    ";
    auto newspaces =  argspaces + "    ";
    std::stringstream ss;
    ss << s+"DEFPROC: " << SymbolicTable::get().get_symbol(o->get_symbol_id()) << "    " << get_parameters(o) << "\n";
    ss << o->get_procedure()->apply_logger(this, argspaces);
    return ss.str();
}

std::string SemanticLogger::get(Procedure *o, std::string &s) {
    auto argspaces = s + "    ";
    auto newspaces =  argspaces + "    ";
    std::stringstream ss;
    ss << s << "PROCEDURE:    " << get_parameters(o) << "\n";
    ss << argspaces << "ISDOT: " << o->dot_notation() << "\n";
    ss << argspaces << "PARAMETERS:\n";
    auto params = o->parameters();
    std::for_each(params.begin(), params.end(), [this, &ss, &newspaces](auto obj){
        ss << obj->apply_logger(this, newspaces);
    });
    ss << argspaces << "BODY:\n";
    ss << o->body()->apply_logger(this, newspaces);
    return ss.str();
}

#include "../painters/InlinePainter.h"
std::string SemanticLogger::get(Quote *o, std::string &s) {
    InlinePainter sm;
    return s + std::string("QUOTE: ") + o->get_object()->to_string(&sm) + "\n";
}

std::string SemanticLogger::get_parameters(SemanticObject *o) {
    std::stringstream ss;
    auto params = o->symbols_table().required_symbols();
    ss << "{";
    std::for_each(params.begin(), params.end(), [&ss](std::size_t s){
        ss << SymbolicTable::get().get_symbol(s) << ",";
    });
    ss << "}";

    auto init = o->symbols_table().initialized_symbols();
    ss << "[";
    std::for_each(init.begin(), init.end(), [&ss](std::size_t s){
        ss << "," << SymbolicTable::get().get_symbol(s);
    });
    ss << "]";
    return ss.str();
}
