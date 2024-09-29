//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_SEMANTICLOGGER_H
#define CPP_SCHEME_SEMANTICLOGGER_H


#include <string>
#include "semantic_objects/If.h"
#include "semantic_objects/Number.h"
#include "semantic_objects/String.h"
#include "semantic_objects/BoundVariable.h"
#include "semantic_objects/Expression.h"
#include "semantic_objects/FnParameter.h"
#include "semantic_objects/DefineSymbol.h"
#include "semantic_objects/DefineProcedure.h"
#include "semantic_objects/Quote.h"

class SemanticLogger {
public:
    std::string get(If* o,              std::string& s);
    std::string get(Number* o,          std::string& s);
    std::string get(String* o,          std::string& s);
    std::string get(BoundVariable* o,   std::string& s);
    std::string get(Expression* o,      std::string& s);
    std::string get(FnParameter* o,      std::string& s);
    std::string get(DefineSymbol* o,      std::string& s);
    std::string get(DefineProcedure* o,      std::string& s);
    std::string get(Procedure* o,      std::string& s);
    std::string get(Quote* o,      std::string& s);
};

#endif //CPP_SCHEME_SEMANTICLOGGER_H
