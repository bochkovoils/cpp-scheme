//
// Created by work on 29.09.2024.
//

#ifndef CPP_SCHEME_INLINEPAINTER_H
#define CPP_SCHEME_INLINEPAINTER_H


#include "StringMapper.h"

class InlinePainter: public StringMapper {
public:
    std::string map(LispSymbol*) override;
    std::string map(LispCell*) override;
    std::string map(LispNumber*) override;
    std::string map(LispString*) override;
    std::string map(LispNull*) override;
    std::string map(LispOperation*) override;

};


#endif //CPP_SCHEME_INLINEPAINTER_H
