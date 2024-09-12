//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_STRINGPARSER_H
#define CPP_SCHEME_STRINGPARSER_H


#include <vector>
#include "../text_handling/TextPointer.h"
#include "../../tokens/Word.h"

class StringParser {
private:
    std::list<Word*>    _words;
    TextPointer&        _start_pointer;
    TextPointer         _current_pointer;
    TextPointer         _prev_pointer;
public:
    explicit StringParser(TextPointer& pointer);
    std::list<Word*> words();
};


#endif //CPP_SCHEME_STRINGPARSER_H
