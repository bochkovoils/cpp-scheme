//
// Created by giantdad on 12.09.24.
//

#include "Atom.h"

Atom::Atom(std::string name) : Word(TokenCode::SYMBOL), _name(std::move(name)) {}

std::string Atom::to_string() {
    return std::string("[Atom ") + _name + std::string("]");
}

