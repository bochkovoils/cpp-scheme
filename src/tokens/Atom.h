//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_ATOM_H
#define CPP_SCHEME_ATOM_H


#include "Word.h"

class Atom : public Word {
private:
    std::string _name;

public:
    explicit Atom(std::string name);

    std::string to_string() override;
};


#endif //CPP_SCHEME_ATOM_H
