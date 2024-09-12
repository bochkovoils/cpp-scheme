//
// Created by giantdad on 11.09.24.
//

#include "IntegerParsingState.h"
#include "DefaultParsingState.h"
#include "ParsingInfo.h"

void IntegerParsingState::next(ParsingInfo* state) {
    bool is_positive = true;
    int result = 0;
    auto forward = state->position();
    auto current = state->position();
    if(*forward == '-') {is_positive = false; forward++;}

    while(*forward >= '0' && *forward <= '9') {
        result = result*10 + *forward - '0';
        forward++;
    }
    if(!is_positive) result = -result;
    state->push_word(new Number(result));
    state->set_movement(ParsingMovement::TO_DEFAULT);
    state->shift_position_to(forward);
}

