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
    ss  << spaces   << "IF:\n"
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
    ss << s << "EXPRESSION:\n";
    std::for_each(elems.begin(), elems.end(), [this, &ss, &newspaces](auto o){
        ss << o->apply_logger(this, newspaces);
    });
    return ss.str();
}
