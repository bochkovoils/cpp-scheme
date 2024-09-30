//
// Created by work on 30.09.2024.
//

#ifndef CPP_SCHEME_CODEPRINTER_H
#define CPP_SCHEME_CODEPRINTER_H


#include <string>
#include <memory>
#include "ByteCode.h"

class CodePrinter {
public:
    std::string get(std::shared_ptr<ByteCode> code);
};


#endif //CPP_SCHEME_CODEPRINTER_H
