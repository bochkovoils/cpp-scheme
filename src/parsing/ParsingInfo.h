//
// Created by giantdad on 11.09.24.
//

#ifndef CPP_SCHEME_PARSINGINFO_H
#define CPP_SCHEME_PARSINGINFO_H

#include "../tokens/Word.h"
#include <vector>
#include <memory>

#include "DefaultParsingState.h"
#include "EofState.h"
#include "OpenBracketParsingState.h"
#include "CloseBracketParsingState.h"
#include "IntegerParsingState.h"
#include "ParsingInfo.h"

enum ParsingMovement {
    TO_DEFAULT,
    TO_INT,
    TO_SYMBOL,
    TO_ERROR,
    TO_OPEN_BRACKET,
    TO_CLOSE_BRACKET,
    FINISH
};

class ParsingInfo {
private:
    ParsingMovement                     _movement;
    int                                 _line_id;
    int                                 _position_in_line;
    const char*                         _position{};
    std::vector<std::shared_ptr<Word>>  _words;

    DefaultParsingState         _default_state;
    CloseBracketParsingState    _close_bracket_state;
    OpenBracketParsingState     _open_bracket_state;
    EofState                    _eof_state;
    IntegerParsingState         _int_state;

    ParsingState* get_state();
public:
    ParsingInfo();

    void set_movement(ParsingMovement movement);
    void set_line_id(int const& line_id);
    void shift_position_to(char const* position);
    void push_word(Word* word);

    [[nodiscard]] std::vector<std::shared_ptr<Word>> words() const;
    [[nodiscard]] ParsingMovement movement() const;
    [[nodiscard]] const char* position() const;
    void parse(std::string& str);
};
#endif //CPP_SCHEME_PARSINGINFO_H
