//
// Created by giantdad on 11.09.24.
//
#include "ParsingControl.h"
#include "DefaultParsingState.h"
#include "CloseBracketParsingState.h"
#include "OpenBracketParsingState.h"
#include "EofState.h"
#include "IntegerParsingState.h"
#include <algorithm>

ParsingControl::ParsingControl(): _movement(ParsingMovement::TO_DEFAULT),
                                  _line_id(0),
                                  _position_in_line(0),
                                  _words(),
                                  _position(nullptr),
                                  _default_state(DefaultParsingState()),
                                  _int_state(IntegerParsingState()),
                                  _open_bracket_state(OpenBracketParsingState()),
                                  _close_bracket_state(CloseBracketParsingState()),
                                  _eof_state(EofState())
{}

void ParsingControl::set_movement(ParsingMovement movement) {this->_movement = movement;}
void ParsingControl::set_line_id(int const& line_id) {this->_line_id = line_id;}
void ParsingControl::shift_position_to(char const* position) {
    auto prev = this->_position;
    this->_position = position;
    this->_position_in_line += position - prev;
}

void ParsingControl::push_word(Word* word) {this->_words.push_back(std::shared_ptr<Word>(word));}

std::vector<std::shared_ptr<Word>> ParsingControl::words() const {return this->_words;}

ParsingMovement ParsingControl::movement() const {return this->_movement;}
const char* ParsingControl::position() const {return this->_position;}
ParsingState* ParsingControl::get_state() {
    switch (this->_movement) {
        case ParsingMovement::TO_DEFAULT: return &(this->_default_state);
        case ParsingMovement::TO_INT: return &(this->_int_state);
        case ParsingMovement::TO_CLOSE_BRACKET: return &(this->_close_bracket_state);
        case ParsingMovement::TO_OPEN_BRACKET: return &(this->_open_bracket_state);
        case ParsingMovement::FINISH: return &(this->_eof_state);
        case TO_SYMBOL:
            throw 1;
        case TO_ERROR:
            throw 2;
    }
}
void ParsingControl::parse(std::string& str) {
    this->_line_id = 0;
    this->_position_in_line = 0;
    this->_position = str.c_str();
    this->_words.clear();
    while(true){
        auto curstate = this->get_state();
        if(curstate->is_terminated()) return;
        curstate->next(this);
    }
}
