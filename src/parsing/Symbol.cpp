//
// Created by work on 17.09.2024.
//

#include "Symbol.h"

Symbol::Symbol(std::string text): _text(std::move(text)) {

}

std::string Symbol::get_text() const {
    return _text;
}

Symbol Symbol::QUOTE_SYMBOL = Symbol("QUOTE");