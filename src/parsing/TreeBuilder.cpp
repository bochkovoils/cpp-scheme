//
// Created by work on 17.09.2024.
//

#include <algorithm>
#include <iostream>
#include "TreeBuilder.h"

TreeBuilder::TreeBuilder(Parser *parser): _parser(parser) {

}

bool TreeBuilder::is_end() {
    return _parser->is_end() && !_parser->has_tokens();
}

AbstractNode *TreeBuilder::next() {
    return nullptr;
}

AbstractNode* TreeBuilder::parse_all() {
    if(!_varstack.empty()) {
        return _varstack.top();
    }
    while(!is_end()) {
        Token token = _parser->next_token();

        if(token.get_id() == TokenId::T_CLOSE_BRACKET) {
            read_list();
        }
        else {
            _varstack.push(new TokenWrapper(token));
        }
    }
    std::cout << "In varstack.top" << std::endl;
//    std::cout << std::get<Token>(_varstack.top()).get_id() << std::endl;
    if(_varstack.empty()) return nullptr;
    return _varstack.top();
}

void TreeBuilder::read_list() {
    std::list<AbstractNode*> resnodes;
    auto node = new ElementsList();

    while (true) {
        auto back_val = _varstack.top();
        if(back_val->get_type() == AbstractNodeType::TOKEN_WRAPPER) {
            auto token = dynamic_cast<TokenWrapper*>(back_val)->get_token();
            if(token.get_id() == TokenId::T_OPEN_BRACKET) {
                delete back_val;
                _varstack.pop();
                break;
            }
            if(token.get_id() == TokenId::T_QUOTE) {
                auto next_sym = resnodes.front();
                resnodes.pop_front();

                auto quoted = new ElementsList();
                quoted->push_back(&Atom::QUOTE_SYMBOL);
                quoted->push_back(next_sym);

                resnodes.push_front(quoted);
            } else {
                resnodes.push_front(new Atom(token.get_value()));
            }
            delete back_val;
        } else {
            resnodes.push_front(back_val);
        }
        _varstack.pop();
    }

    std::for_each(resnodes.begin(), resnodes.end(), [node](auto var) {
        node->push_back(var);
    });
    _varstack.push(node);
}


//Atom *TreeBuilder::next() {
//    if(_stack.empty()) {
//
//    }
//}
//
//bool TreeBuilder::is_end() {
//    return _parser->is_end();
//}
//
//AbstractNode *TreeBuilder::read_next() {
//    auto token = _parser->next_token();
//    if(token.get_id() == TokenId::T_EMPTY) return nullptr;
//    if(token.get_id() == TokenId::T_OPEN_BRACKET) {
//        _stack.push(token);
//        reduce_list();
//    }
//}
//
//void TreeBuilder::reduce_list() {
//}
//
//
