//
// Created by work on 03.10.2024.
//

#ifndef CPP_SCHEME_EVALPROCEDURE_H
#define CPP_SCHEME_EVALPROCEDURE_H


#include <utility>

#include "../semantic_parsing/semantic_objects/Procedure.h"
#include "ByteCode.h"
#include "../lisp_structures/LispObject.h"
#include "../lisp_structures/LispOperation.h"
#include "EvalObject.h"

class EvalProcedure: public LispOperation, public EvalObject {
private:
    static std::size_t counter;
    std::size_t _id;
    std::shared_ptr<Procedure>  _procedure_ptr;
public:
    explicit EvalProcedure(std::shared_ptr<Procedure> proc):
    _id(counter++),
    _procedure_ptr(std::move(proc)) {};

    [[nodiscard]] unsigned int get_id() const {return _procedure_ptr->get_id();}
    std::shared_ptr<Procedure> get_procedure() { return _procedure_ptr; }
};


#endif //CPP_SCHEME_EVALPROCEDURE_H
