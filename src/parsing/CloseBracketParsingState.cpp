//
// Created by giantdad on 11.09.24.
//
#include <iostream>
#include "CloseBracketParsingState.h"
#include "DefaultParsingState.h"
#include "ParsingInfo.h"
#include "../tokens/CloseBracket.h"

void CloseBracketParsingState::next(ParsingInfo* state) {
    const char* cur = state->position();
    if(*cur != ')') {
        std::cout << ")" << std::endl;
        throw 1;
    }
    state->push_word(new CloseBracket());
    state->set_movement(ParsingMovement::TO_DEFAULT);
    state->shift_position_to(cur+1);
}