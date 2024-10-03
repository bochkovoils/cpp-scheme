//
// Created by work on 01.10.2024.
//

#ifndef CPP_SCHEME_TAILRECURSIONREPLACER_H
#define CPP_SCHEME_TAILRECURSIONREPLACER_H


#include <list>
#include "SemanticWalker.h"

class TailRecursionReplacer: public SemanticWalker {
private:
    std::list<std::size_t>  _stack;
private:
    void walk(If* o              ) override;
    void walk(Number* o          ) override;
    void walk(String* o          ) override;
    void walk(BoundVariable* o   ) override;
    void walk(Expression* o      ) override;
    void walk(FnParameter* o     ) override;
    void walk(DefineSymbol* o    ) override;
    void walk(DefineProcedure* o ) override;
    void walk(Procedure* o       ) override;
    void walk(Quote* o           ) override;
};


#endif //CPP_SCHEME_TAILRECURSIONREPLACER_H
