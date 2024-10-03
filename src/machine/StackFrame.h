//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_STACKFRAME_H
#define CPP_SCHEME_STACKFRAME_H


#include <map>
#include <utility>
#include "../lisp_structures/LispObjectRef.h"
#include "EvalObject.h"
#include "VarTable.h"

class StackFrameState {

};

class StackFrame {
private:
    LispObjectRef               _eval_obj;
    std::shared_ptr<VarTable>   _vars;
    std::size_t                 _position;

public:
    StackFrame(LispObjectRef eo, std::shared_ptr<VarTable> table):  _eval_obj(eo),
                                                                    _vars(std::move(table)),
                                                                    _position(0) {}
    [[nodiscard]] std::size_t   position() const  {return _position;}
    std::shared_ptr<VarTable>   variables()     { return _vars; }
    LispObjectRef               eval_object()   {return _eval_obj;}
    void update_position(std::size_t const& i)  { _position = i; }
};


#endif //CPP_SCHEME_STACKFRAME_H
