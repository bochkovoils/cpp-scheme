//
// Created by work on 17.09.2024.
//

#include "Atom.h"

Atom::Atom(std::string text): _text(std::move(text)) {

}

std::string Atom::get_text() const {
    return _text;
}

Atom Atom::QUOTE_SYMBOL = Atom("QUOTE");