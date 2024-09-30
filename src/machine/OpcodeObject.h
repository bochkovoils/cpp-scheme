//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_OPCODEOBJECT_H
#define CPP_SCHEME_OPCODEOBJECT_H


#include <vector>

class OpcodeObject {
private:
    std::size_t _opcode;
    std::size_t _label;
    bool        _has_label;
public:
    OpcodeObject(std::size_t opcode);
    OpcodeObject(std::size_t opcode, std::size_t label);
    std::size_t get_opcode() const {return _opcode;}
    std::size_t get_label() const {return _label;}
    bool        has_label() const {return _has_label;}
};


#endif //CPP_SCHEME_OPCODEOBJECT_H
