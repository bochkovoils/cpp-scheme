//
// Created by giantdad on 12.09.24.
//

#include "SpanParsingRule.h"

TextPointer SpanParsingRule::try_parse(TextPointer  const& pointer) {
    if(*pointer > _top || *pointer < _bottom)
        return pointer;
    return pointer+1;
}

SpanParsingRule::SpanParsingRule(char bottom, char top): ParsingRule(), _bottom(bottom), _top(top){}
