//
// Created by giantdad on 12.09.24.
//

#include "StringEqParsingRule.h"

StringEqParsingRule::StringEqParsingRule(const char *s): ParsingRule(), _string(s) {

}

TextPointer StringEqParsingRule::try_parse(TextPointer  const& pointer) {
    auto forward = TextPointer(pointer);
    for(char & it : _string) {
        if(*forward != it) return pointer;
        forward++;
    }
    return forward;
}
