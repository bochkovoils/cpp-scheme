//
// Created by work on 03.10.2024.
//

#ifndef CPP_SCHEME_EVALOBJECT_H
#define CPP_SCHEME_EVALOBJECT_H


#include <memory>
#include "ByteCode.h"

class EvalObject {
protected:
    std::shared_ptr<ByteCode> _byte_code;
    std::vector<OpcodeObject> _opcodes;
    bool _is_done= false;
public:

    std::shared_ptr<ByteCode> byte_code();
    EvalObject* push(OpcodeObject &&obj) {_opcodes.push_back(obj); return this;}
    EvalObject& operator<<(OpcodeObject&& obj) {_opcodes.push_back(obj); _is_done=false; return *this;}
};


#endif //CPP_SCHEME_EVALOBJECT_H
