//
// Created by work on 25.09.2024.
//

#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "StructurePainter.h"
#include "../parsing/SyntaxTree.h"

std::string StructurePainter::upstring(std::vector<std::shared_ptr<SyntaxTree>>&& children) {
    std::stringstream ss;
    auto it = children.begin();
    ss << "(" << get_string(*it);
    std::for_each(++it, children.end(), [&ss, this](auto t){
        ss << " " << get_string(t);
    });
    ss << ")";
    return ss.str();
}

std::string StructurePainter::get_string(std::shared_ptr<SyntaxTree> ref) {
    switch (ref->get_id()) {
        case SyntaxTreeId::ST_TOKEN:
            return std::string("!!TOKEN#") + std::to_string(ref->bound_token()->get_id());
        case SyntaxTreeId::ST_LIST:
            return upstring(ref->children());
        case SyntaxTreeId::ST_NULL:
            return "()";
        case SyntaxTreeId::ST_ATOM:
            return get_primitive(ref->bound_token());
        case SyntaxTreeId::ST_QUOTE:
            return "quote";
    }
}

std::string StructurePainter::get_primitive(std::shared_ptr<Token> ref) {
    if(ref->get_id() == TokenId::T_SYMBOL) {
        return ref->get_symbol();
    }
    if(ref->get_id() == TokenId::T_STRING) {
        return std::string("\"") + ref->get_string() + std::string("\"");
    }
    if(ref->get_id() == TokenId::T_NUMBER) {
        return std::to_string(ref->get_value());
    }
    throw 1;
}
