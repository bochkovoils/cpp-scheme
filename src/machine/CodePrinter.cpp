//
// Created by work on 30.09.2024.
//

#include <sstream>
#include <set>
#include "CodePrinter.h"
#include "VirtualMachine.h"

std::string CodePrinter::get(std::shared_ptr<ByteCode> code_) {
    std::string spaces(15, ' ');
    std::stringstream ss;
    auto code = *code_;
    std::set<std::size_t> labels(code.labels_begin(), code.labels_end());
    for(std::size_t index=0; index < code.size(); index++) {
        std::string sp = spaces;
        if(labels.count(index)) {
            auto lbid = code.label_index(index);
            std::string number = std::string("L") + std::to_string(lbid)+":";
            sp.replace(0, number.size(), number);
        }
        ss << sp;
        switch (code[index]) {
            case Opcode::RET:
                ss << "RET";
                break;
            case Opcode::LOAD:
                ss << "LOAD " << std::to_string(code[++index]);
                break;
            case Opcode::PUSH:
                ss << "PUSH " << std::to_string(code[++index]);
                break;
            case Opcode::NOOP:
                break;
            case Opcode::CALL:
                ss << "CALL";
                break;
        }
        ss << "\n";
    }
    return ss.str();
}
