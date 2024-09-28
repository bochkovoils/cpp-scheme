//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_SYNTAXPARSER_H
#define CPP_SCHEME_SYNTAXPARSER_H


#include "LexicalParser.h"
#include "../lisp_structures/LispObject.h"
#include "../lisp_structures/LispObjectRef.h"
#include "SyntaxTree.h"
#include <utility>
#include <variant>
#include <stack>
#include <memory>

class SyntaxParser: public Observer<std::shared_ptr<Token>>,
                    public Observable<std::shared_ptr<SyntaxTree>> {
private:
    std::stack<std::shared_ptr<SyntaxTree>> _varstack;
    int brackets = 0;

    std::shared_ptr<SyntaxTree> parse_primitive(std::shared_ptr<Token>);
    std::shared_ptr<SyntaxTree> read_list(std::shared_ptr<Token> t);
    std::shared_ptr<SyntaxTree> collapse_quotes(std::shared_ptr<SyntaxTree> tree);

    void accept(std::shared_ptr<Token>);
public:
    explicit SyntaxParser();
    void handle(std::shared_ptr<Token>) override;
    bool empty();
};


#endif //CPP_SCHEME_SYNTAXPARSER_H
