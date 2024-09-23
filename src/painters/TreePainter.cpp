//
// Created by work on 18.09.2024.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include "TreePainter.h"

void TreePainter::paint_tree(LispObject *node) {
    if(node == nullptr) {
        std::cout << "Empty string" << std::endl;
        return;
    }
    collect(node);
    std::for_each(_collect.begin(), _collect.end(), [this](auto re){
        int spaces = std::get<0>(re);
        auto node = std::get<1>(re);
        node->apply_visitor(this);
        std::cout << get_spaces(spaces) << _buffer_visitor << std::endl;
    });
}

void TreePainter::collect(LispObject* node) {
    _stack = std::stack<std::tuple<int, LispObject*>>();
    _collect.clear();

    _stack.push(std::make_tuple(0, node));
    while (!_stack.empty()) {
        auto curnode = _stack.top();
        _stack.pop();

        int spaces = std::get<0>(curnode);
        LispObject* node_ = std::get<1>(curnode);
        _collect.emplace_back(spaces, node_);

        auto lst = dynamic_cast<LispCell*>(node_);
        if(lst != nullptr){
            auto collected = this->collect_list(lst);
            int new_count = spaces + 4;
            auto start = collected.end();
            auto end = collected.begin();
            for(auto cur=start; cur !=end;) {
                --cur;
                _stack.push(std::make_tuple(new_count, *cur));
            }
        }
    }
}

std::string TreePainter::get_spaces(unsigned int spaces) {
    std::stringstream ss;
    for(int s=0; s<spaces; s++) {
        ss << " ";
    }
    return ss.str();
}

std::list<LispObject*> TreePainter::collect_list(LispCell* cell) {
    std::list<LispObject*> result;
    std::set<LispObject*> visited;

    while (true) {
        LispObject* head = cell->head();
        LispObject* rest = cell->rest();
        result.push_back(head);

        if(rest == LispNull::get()) break;
        if(visited.count(rest) > 0) break;
        visited.insert(cell);

        auto* next = dynamic_cast<LispCell*>(rest);
        if(next) {
            cell = next;
        }
        else {
            result.push_back(rest);
            break;
        }
    }
    return result;
}

void TreePainter::apply(LispNumber *n) {
    _buffer_visitor = std::string("NUMBER: ") + n->get_value();
}

void TreePainter::apply(LispSymbol *s) {
    _buffer_visitor = std::string("SYMBOL: ") + s->get_name() + std::string(" #:") + std::to_string(s->get_hash());
}

void TreePainter::apply(LispString *s) {
    _buffer_visitor = std::string("STRING: ");
}

void TreePainter::apply(LispNull *) {
    _buffer_visitor = std::string("NULL");
}

void TreePainter::apply(LispCell *) {
    _buffer_visitor = std::string("LIST:");
}