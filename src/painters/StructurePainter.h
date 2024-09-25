//
// Created by work on 25.09.2024.
//

#ifndef CPP_SCHEME_STRUCTUREPAINTER_H
#define CPP_SCHEME_STRUCTUREPAINTER_H


#include "StringMapper.h"

class StructurePainter: public StringMapper {
public:
    virtual std::string map(LispSymbol*     );
    virtual std::string map(LispCell*       );
    virtual std::string map(LispNumber*     );
    virtual std::string map(LispString*     );
    virtual std::string map(LispNull*       );
    virtual std::string map(LispOperation*  );

    void paint(LispObjectRef ref);
};


#endif //CPP_SCHEME_STRUCTUREPAINTER_H
