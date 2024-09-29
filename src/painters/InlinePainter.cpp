//
// Created by work on 29.09.2024.
//

#include <sstream>
#include "InlinePainter.h"

std::string InlinePainter::map(LispOperation *op) {
    return "#operation";
}

std::string InlinePainter::map(LispNull *) {
    return "()";
}

std::string InlinePainter::map(LispString *s) {
    return s->get();
}

std::string InlinePainter::map(LispNumber *n) {
    return n->get_value();
}

std::string InlinePainter::map(LispCell *c) {
    std::stringstream ss;
    ss << "(";

    auto head = c->head();
    auto rest = c->rest();

    while(rest->get_type() == LispObjectId::L_CELL) {
        ss << head->to_string(this) << " ";
        auto nexth = rest.as<LispCell>()->head();
        auto nextr = rest.as<LispCell>()->rest();
        head = MovRef{nexth};
        rest = MovRef{nextr};
    }
    ss << head->to_string(this) << " ";
    if(rest->get_type() == LispObjectId::L_NULL)

        ss << ")";
    else {
        ss << " . " << rest->to_string(this) << ")";
    }
    return ss.str();
}

std::string InlinePainter::map(LispSymbol *s) {
    return s->get_name();
}
