//
// Created by work on 18.09.2024.
//

#include "LispString.h"
#include "StructuresVisitor.h"

void LispString::apply_visitor(StructuresVisitor *visitor) {
    visitor->apply(this);
}
