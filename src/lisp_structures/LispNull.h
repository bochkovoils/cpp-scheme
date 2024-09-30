//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPNULL_H
#define CPP_SCHEME_LISPNULL_H


#include <memory>
#include "LispObject.h"
#include "LispObjectRef.h"

class LispNull: public LispObject {
public:
    static LispObjectRef get() {
        return _instance;
    }
private:
    static LispObjectRef _instance;

    LispNull() = default;
    std::string to_string(StringMapper *mapper) override;
    LispObjectId get_type() override { return LispObjectId::L_NULL; }
};


#endif //CPP_SCHEME_LISPNULL_H
