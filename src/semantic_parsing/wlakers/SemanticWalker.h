//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_SEMANTICWALKER_H
#define CPP_SCHEME_SEMANTICWALKER_H


#include <string>
class If;
class Number;
class String;
class BoundVariable;
class Expression;
class FnParameter;
class DefineSymbol;
class DefineProcedure;
class Procedure;
class Quote;


class SemanticWalker {
public:
    virtual void walk(If* o              )=0;
    virtual void walk(Number* o          )=0;
    virtual void walk(String* o          )=0;
    virtual void walk(BoundVariable* o   )=0;
    virtual void walk(Expression* o      )=0;
    virtual void walk(FnParameter* o     )=0;
    virtual void walk(DefineSymbol* o    )=0;
    virtual void walk(DefineProcedure* o )=0;
    virtual void walk(Procedure* o       )=0;
    virtual void walk(Quote* o           )=0;
};


#endif //CPP_SCHEME_SEMANTICWALKER_H
