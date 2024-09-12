//
// Created by giantdad on 11.09.24.
//

#include "OpenBracketParsingState.h"
#include "DefaultParsingState.h"
#include "ParsingInfo.h"
#include <exception>
#include <iostream>
#include "../tokens/OpenBracket.h"

void OpenBracketParsingState::next(ParsingInfo* state) {
    const char* cur = state->position();
    if(*cur != '(') {
        std::cout << "(" << std::endl;
        throw 1;
    }
    state->push_word(new OpenBracket());
    state->set_movement(ParsingMovement::TO_DEFAULT);
    state->shift_position_to(cur+1);
}