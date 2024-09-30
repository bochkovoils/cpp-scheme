//
// Created by work on 30.09.2024.
//

#include "VirtualMachine.h"

int VirtualMachine::eval() {
    auto code = *_code;
    std::size_t position = code.get_main_position();
    while(true) {
        switch (code[position]) {
            case Opcode::RET:
                return 0;
            default:
                return 1;
        }
    }
}
