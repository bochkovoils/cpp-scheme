//
// Created by work on 17.09.2024.
//

#include "ElementsList.h"

void ElementsList::push_back(AbstractNode *node) {
    _nodes.emplace_back(node);
}

void ElementsList::push_front(AbstractNode *node) {
    _nodes.emplace_front(node);
}


