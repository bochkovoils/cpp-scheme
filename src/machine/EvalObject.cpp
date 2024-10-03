//
// Created by work on 03.10.2024.
//

#include "EvalObject.h"

std::shared_ptr<ByteCode> EvalObject::byte_code() {
    if(_is_done) return _byte_code;
    _byte_code = std::make_shared<ByteCode>(_opcodes.begin(), _opcodes.end());
    _is_done = true;
    return _byte_code;
}
