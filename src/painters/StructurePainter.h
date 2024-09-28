//
// Created by work on 25.09.2024.
//

#ifndef CPP_SCHEME_STRUCTUREPAINTER_H
#define CPP_SCHEME_STRUCTUREPAINTER_H


#include "StringMapper.h"
#include "../parsing/SyntaxTree.h"

class StructurePainter {
private:
    std::string upstring(std::vector<std::shared_ptr<SyntaxTree>>&& children);
    std::string get_primitive(std::shared_ptr<Token> ref);
public:
    std::string get_string(std::shared_ptr<SyntaxTree> ref);
};


#endif //CPP_SCHEME_STRUCTUREPAINTER_H
