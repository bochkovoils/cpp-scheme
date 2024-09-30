//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_BYTECODE_H
#define CPP_SCHEME_BYTECODE_H


#include <vector>
#include "OpcodeObject.h"

class ByteCode {
private:
    std::vector<std::size_t>    _data;
    std::vector<std::size_t>    _labels;

public:
    ByteCode(std::vector<std::size_t>& data, std::vector<std::size_t>& labels): _data(data), _labels(labels){};
    ByteCode(std::vector<OpcodeObject>::iterator begin, std::vector<OpcodeObject>::iterator end);
    std::size_t operator[](std::size_t const &);
    std::size_t get_label_position(int const&);
    std::size_t get_main_position() const;
    std::size_t size() const {return _data.size();}
    std::vector<std::size_t>::iterator labels_begin() {return _labels.begin();}
    std::vector<std::size_t>::iterator labels_end() {return _labels.end();}
    std::size_t label_index(std::size_t const& label_id);
};


#endif //CPP_SCHEME_BYTECODE_H
