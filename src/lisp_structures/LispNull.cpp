//
// Created by work on 18.09.2024.
//

#include "LispNull.h"
#include "StructuresVisitor.h"

void LispNull::apply_visitor(StructuresVisitor *visitor) {
    return visitor->apply(this);
}

std::unique_ptr<LispNull> LispNull::_instance = nullptr;