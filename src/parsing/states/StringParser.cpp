//
// Created by giantdad on 12.09.24.
//

#include <list>
#include <set>
#include <iostream>
#include "StringParser.h"
#include "Parser.h"
#include "LeftBracketParser.h"
#include "RightBracketParser.h"
#include "NumberParser.h"

StringParser::StringParser(TextPointer &pointer)
: _start_pointer(pointer),
_current_pointer(pointer),
_prev_pointer(pointer),
_words() {
}

std::list<Word *> StringParser::words() {
    std::list<Parser*> parsers {
        new LeftBracketParser(),
        new RightBracketParser(),
        new NumberParser()
    };
    std::set<char> skip{' ', '\0', '\n'};
    while(!_current_pointer.is_eof()) {
        std::cout << *_current_pointer << std::endl;
        if(skip.count(*_current_pointer)) {
            ++_current_pointer;
            continue;
        }
        _prev_pointer = _current_pointer;
        for(auto & parser: parsers) {
            _current_pointer = parser->parsing_rule()->try_parse(_prev_pointer);
            if(_current_pointer != _prev_pointer) {
                _words.push_back(parser->parse(_prev_pointer, _current_pointer));
                break;
            }
        }
        throw "Unknown object";
    }
    return _words;
}


