//
// Created by giantdad on 11.09.24.
//
#include "DefaultParsingState.h"
#include "EofState.h"
#include "ParsingControl.h"
#include "OpenBracketParsingState.h"
#include "CloseBracketParsingState.h"
#include "IntegerParsingState.h"
#include "ParsingControl.h"
#include <iostream>

void DefaultParsingState::next(ParsingControl* state) {
    for(;;) {
        auto _current = state->position();
        switch (*_current) {
            case '\0': state->set_movement(ParsingMovement::FINISH);
                return;
            case '(': state->set_movement(ParsingMovement::TO_OPEN_BRACKET);
                return;
            case ')': state->set_movement(ParsingMovement::TO_CLOSE_BRACKET);
                return;
        }
        if('0' <= *_current && *_current <= '9' || *_current == '-'){
            state->set_movement(ParsingMovement::TO_INT);
            return;
        }

        if(*_current == ' ' || *_current == '\n') {
            state->shift_position_to(_current+1);
            continue;
        }
        else {
            std::cout << "WTF IS " << _current << std::endl;
            throw std::string("WTF is this?");
        }
    }
}