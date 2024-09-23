//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPNULL_H
#define CPP_SCHEME_LISPNULL_H


#include <memory>
#include "LispObject.h"

class LispNull: public LispObject {
public:
    static LispNull* get() {
        if(_instance == nullptr) _instance = std::move(std::unique_ptr<LispNull>(new LispNull()));
        return _instance.get();
    }
private:
    static std::unique_ptr<LispNull> _instance;

    LispNull() = default;
    void apply_visitor(StructuresVisitor *visitor) override;
};


#endif //CPP_SCHEME_LISPNULL_H
