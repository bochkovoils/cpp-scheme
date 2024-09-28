//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_QUOTE_H
#define CPP_SCHEME_QUOTE_H


#include <memory>
#include "../../lisp_structures/LispObject.h"
#include "../../lisp_structures/LispObjectRef.h"
#include "../SemanticLogger.h"

class Quote {
private:
    LispObjectRef   _obj;
public:
    explicit Quote(LispObjectRef& obj): _obj(obj){};

    LispObjectRef get_object() { return _obj; }

//    std::string apply_logger(SemanticLogger *logger);
};


#endif //CPP_SCHEME_QUOTE_H
