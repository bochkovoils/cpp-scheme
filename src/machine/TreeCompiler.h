//
// Created by work on 03.10.2024.
//

#ifndef CPP_SCHEME_TREECOMPILER_H
#define CPP_SCHEME_TREECOMPILER_H


#include <stack>
#include "../semantic_parsing/wlakers/SemanticWalker.h"
#include "EvalProcedure.h"
#include "../parsing/Observer.h"

class TreeCompiler:
        public SemanticWalker,
        public Observer<std::shared_ptr<SemanticObject>>,
        public Observable<LispObjectRef> {
private:
    std::stack<EvalObject*> _bodies;
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

    void log(int spaces);

    void handle(std::shared_ptr<SemanticObject>) override;
};


#endif //CPP_SCHEME_TREECOMPILER_H
