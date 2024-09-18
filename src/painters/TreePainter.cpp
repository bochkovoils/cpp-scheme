//
// Created by work on 18.09.2024.
//

#include <iostream>
#include <algorithm>
#include <sstream>
#include "TreePainter.h"

void TreePainter::paint_tree(AbstractNode *node) {
    auto collected = collect(node);
    std::for_each(collected.begin(), collected.end(), [this](auto re){
        int spaces = std::get<0>(re);
        auto node = std::get<1>(re);
        std::cout << get_spaces(spaces) << ms(node) << std::endl;
    });
}

std::list<std::tuple<int, AbstractNode *>> TreePainter::collect(AbstractNode* node) {
    std::stack<std::tuple<int, AbstractNode*>> stack{};
    std::list<std::tuple<int, AbstractNode*>> result;

    stack.push(std::make_tuple(0, node));
    while (!stack.empty()) {
        auto curnode = stack.top();
        stack.pop();

        int spaces = std::get<0>(curnode);
        AbstractNode* node_ = std::get<1>(curnode);
        result.emplace_back(spaces, node_);

        auto lst = dynamic_cast<LispList*>(node_);
        if(lst != nullptr){
            int new_count = spaces + 4;
            auto start = lst->end();
            auto end = lst->begin();
            for(auto cur=start; cur !=end;) {
                --cur;
                stack.push(std::make_tuple(new_count, *cur));
            }
        }
    }
    return result;
}

std::string TreePainter::make_string(LispList *list) {
    return "LIST:";
}

std::string TreePainter::make_string(Symbol *list) {
    return std::string("SYMBOL: ") + list->get_text();
}

std::string TreePainter::make_string(TokenWrapper *list) {
    return "!!!TOKEN_WRAPPER!!!";
}

std::string TreePainter::get_spaces(unsigned int spaces) {
    std::stringstream ss;
    for(int s=0; s<spaces; s++) {
        ss << " ";
    }
    return ss.str();
}

std::string TreePainter::ms(AbstractNode *list) {
    if(list->get_type() == AbstractNodeType::A_SYMBOL       ) return make_string(dynamic_cast<Symbol*      >(list));
    if(list->get_type() == AbstractNodeType::LIST           ) return make_string(dynamic_cast<LispList*    >(list));
    if(list->get_type() == AbstractNodeType::TOKEN_WRAPPER  ) return make_string(dynamic_cast<TokenWrapper*>(list));
    else throw 1;
}
