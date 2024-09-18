//
// Created by work on 17.09.2024.
//

#include "LispList.h"

void LispList::push_back(AbstractNode *node) {
    _nodes.emplace_back(node);
}

void LispList::push_front(AbstractNode *node) {
    _nodes.emplace_front(node);
}


