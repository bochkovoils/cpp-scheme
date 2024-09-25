//
// Created by work on 25.09.2024.
//

#include <set>
#include <sstream>
#include <iostream>
#include "StructurePainter.h"

std::string StructurePainter::map(LispString *s) {
    return std::string("\"") + s->get() + std::string("\"");
}

std::string StructurePainter::map(LispNull *) {
    return "()";
}

std::string StructurePainter::map(LispCell *c) {
    auto result = std::stringstream();
    result << "(";
    std::set<LispCell*> s;
    while(true) {
        auto head = c->head();
        auto rest = c->rest();
        result << head->to_string(this);
        s.insert(c);

        if(rest.is<LispCell>()) {
            result << " ";
            c = rest.as<LispCell>();
        }
        else if(rest.is<LispNull>()) {
            result << ")";
            return result.str();
        }
        else {
            result << " . " << rest->to_string(this) << ")";
            return result.str();
        }
    }
}

std::string StructurePainter::map(LispSymbol *s) {
    return s->get_name();
}

std::string StructurePainter::map(LispNumber *n) {
    return n->get_value();
}

std::string StructurePainter::map(LispOperation *o) {
    return std::string("#operation:") + o->get_symbol().as<LispSymbol>()->get_name();
}

void StructurePainter::paint(LispObjectRef ref) {
    std::cout << ref->to_string(this) << std::endl;
}
