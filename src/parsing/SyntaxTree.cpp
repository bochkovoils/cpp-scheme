//
// Created by work on 27.09.2024.
//

#include "SyntaxTree.h"

#include <utility>
#include <algorithm>

SyntaxTree::SyntaxTree(SyntaxTreeId id, std::shared_ptr<Token> token): _id(id), _bound_token(std::move(token)), _children() {
}

SyntaxTree::SyntaxTree(SyntaxTreeId id,
                       std::shared_ptr<Token> token,
                       std::list<std::shared_ptr<SyntaxTree>>::iterator begin,
                       std::list<std::shared_ptr<SyntaxTree>>::iterator end):

                       _id(id),
                       _bound_token(std::move(token)),
                       _children(begin, end) {
}

bool SyntaxTree::empty() const {
    return _children.empty();
}

bool SyntaxTree::is_leaf() const {
    return _id == SyntaxTreeId::ST_ATOM;
}

std::vector<std::shared_ptr<SyntaxTree>> SyntaxTree::children() {
    return _children;
}

void SyntaxTree::push(std::list<std::shared_ptr<SyntaxTree>>::iterator begin, std::list<std::shared_ptr<SyntaxTree>>::iterator end) {
    std::for_each(begin, end, [this](auto e) {
        _children.push_back(e);
    });
}

std::size_t SyntaxTree::size() const {
    return _children.size();
}

std::shared_ptr<Token> SyntaxTree::bound_token() {
    return _bound_token;
}

SyntaxTree::SyntaxTree(SyntaxTreeId id,
                       std::shared_ptr<Token> token,
                       std::shared_ptr<SyntaxTree> subtree): _id(id),
                                                             _bound_token(std::move(token)),
                                                             _children{std::move(subtree)} {

}

void SyntaxTree::push(std::shared_ptr<SyntaxTree> st) {
    _children.push_back(st);
}



