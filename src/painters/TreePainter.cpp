//
// Created by work on 18.09.2024.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include <set>
#include "TreePainter.h"

void TreePainter::paint(LispObjectRef ref) {
    std::cout << "PARSING TREE:" << std::endl;
    if(ref.empty()) {
        std::cout << "Empty" << std::endl;
        return;
    }
    collect(ref);
    std::for_each(_collect.begin(), _collect.end(), [this](auto re){
        int spaces = std::get<0>(re);
        auto node = std::get<1>(re);
        std::cout << get_spaces(spaces) << node->to_string(this) << std::endl;
    });
}

void TreePainter::collect(LispObjectRef& node) {
    _stack = std::stack<std::tuple<int, LispObjectRef>>();
    _collect.clear();

    _stack.push(std::make_tuple(0, node));
    while (!_stack.empty()) {
        auto curnode = _stack.top();
        _stack.pop();

        int spaces = std::get<0>(curnode);
        LispObjectRef node_ = std::get<1>(curnode);
        _collect.emplace_back(spaces, node_);

        if(node_.is<LispCell>()){
            auto collected = this->collect_list(node_.as<LispCell>());
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

std::string TreePainter::map(LispSymbol *) {
    return "SYMBOL";
}

std::string TreePainter::map(LispCell *) {
    return "LIST";
}

std::string TreePainter::map(LispNumber *) {
    return "NUMBER";
}

std::string TreePainter::map(LispString *) {
    return "STRING";
}

std::string TreePainter::map(LispNull *) {
    return "NULL";
}

std::string TreePainter::map(LispOperation *) {
    return "OPERATION";
}

std::list<LispObjectRef> TreePainter::collect_list(LispCell* cell) {
    std::list<LispObjectRef> result;
    std::set<LispObject*> visited;

    while (true) {
        auto head = cell->head();
        auto rest = cell->rest();
        result.push_back(head);

        if(rest.is<LispNull>()) break;
        if(visited.count(cell) > 0) break;
        visited.insert(cell);

        if(rest.is<LispCell>()) {
            cell = rest.as<LispCell>();
        }
        else {
            result.push_back(rest);
            break;
        }
    }
    return result;
}
