//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_SYNTAXPARSER_H
#define CPP_SCHEME_SYNTAXPARSER_H


#include "LexicalParser.h"
#include "../lisp_structures/LispObject.h"
#include "../lisp_structures/LispObjectRef.h"
#include <utility>
#include <variant>
#include <stack>
#include <memory>

class TokenWrapper: public LispObject {
private:
    std::shared_ptr<Token> _token;
public:
    explicit TokenWrapper(std::shared_ptr<Token> token): _token(token) {};
    [[nodiscard]] std::shared_ptr<Token> get_token() const {return _token; }
    std::string to_string(StringMapper *mapper) override {throw 1;}
    LispObjectId get_type() override {return LispObjectId::TRASH; }
    LispObjectRef evaluate(Evaluator *evaluator) override {throw 1;}
};

class SyntaxParser: public Observer<std::shared_ptr<Token>>, public Observable<LispObjectRef> {
private:
    std::stack<LispObjectRef> _varstack;
    int brackets = 0;

    LispObjectRef parse_primitive(std::shared_ptr<Token>);
    void read_list(Token const&);
    void accept(std::shared_ptr<Token>);
    void collapse_quotes(std::list<LispObjectRef>& lst);
public:
    explicit SyntaxParser();
    void handle(std::shared_ptr<Token>) override;
    bool empty();
};


#endif //CPP_SCHEME_SYNTAXPARSER_H
