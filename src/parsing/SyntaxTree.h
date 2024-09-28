//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_SYNTAXTREE_H
#define CPP_SCHEME_SYNTAXTREE_H


#include <vector>
#include <memory>
#include <list>
#include "../lisp_structures/LispObject.h"
#include "Token.h"

enum SyntaxTreeId {
    ST_ATOM,
    ST_LIST,
    ST_TOKEN,
    ST_NULL,
    ST_QUOTE
};

class SyntaxTree {
private:
    SyntaxTreeId                                _id;
    std::vector<std::shared_ptr<SyntaxTree>>    _children;
    std::shared_ptr<Token>                      _bound_token;
public:
    SyntaxTree(SyntaxTreeId id,
               std::shared_ptr<Token> token);
    SyntaxTree(SyntaxTreeId id,
               std::shared_ptr<Token> token,
               std::shared_ptr<SyntaxTree> subtree);
    SyntaxTree(SyntaxTreeId id,
               std::shared_ptr<Token> token,
               std::list<std::shared_ptr<SyntaxTree>>::iterator begin,
               std::list<std::shared_ptr<SyntaxTree>>::iterator end);

    bool empty() const;
    bool is_leaf() const;
    std::vector<std::shared_ptr<SyntaxTree>> children();
    void push(std::list<std::shared_ptr<SyntaxTree>>::iterator begin,
              std::list<std::shared_ptr<SyntaxTree>>::iterator end);
    void push(std::shared_ptr<SyntaxTree> st);
    std::size_t size() const;
    std::shared_ptr<Token>  bound_token();
    SyntaxTreeId get_id() const { return _id; };
};


#endif //CPP_SCHEME_SYNTAXTREE_H
