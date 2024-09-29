//
// Created by work on 18.09.2024.
//

#include "LispCell.h"
#include "LispNull.h"

LispCell::LispCell(LispObjectRef head, LispObjectRef rest): _head(head), _rest(rest) {

}
LispCell::LispCell(): _head(LispNull::get()), _rest(LispNull::get()) {}

LispObjectRef LispCell::head() {return _head;}
LispObjectRef LispCell::rest() {return _rest;}

void LispCell::set_head(LispObjectRef o) {_head = MovRef{o};}
void LispCell::set_rest(LispObjectRef r) {_rest = MovRef{r};}

LispObjectRef LispCell::from_list(std::list<LispObjectRef>::iterator begin, std::list<LispObjectRef>::iterator end) {
    if(begin == end) return LispObjectRef(new LispCell());

    auto result = LispObjectRef(new LispCell(*begin++, LispNull::get()));
    auto current = result;
    while (begin != end) {
        auto next = LispObjectRef(new LispCell(*begin++, LispNull::get()));
        current.as<LispCell>()->_rest = MovRef{next};
        current = MovRef{next};
    }
    return result;
}

#include "../painters/StringMapper.h"
std::string LispCell::to_string(StringMapper *mapper) {
    return mapper->map(this);
}


#include "../evaluation/Evaluator.h"
LispObjectRef LispCell::evaluate(Evaluator *evaluator) {
    return evaluator->eval_object(this);
}

LispObjectRef
LispCell::from_vector(std::vector<LispObjectRef>::iterator begin, std::vector<LispObjectRef>::iterator end) {
    if(begin == end) return LispObjectRef(new LispCell());

    auto curit = begin;
    auto result = LispObjectRef(new LispCell(*curit, LispNull::get()));
    auto current = result;
    curit++;

    while (curit != end) {
        auto next = LispObjectRef(new LispCell(*curit, LispNull::get()));
        current.as<LispCell>()->_rest = MovRef{next};
        current = MovRef{next};
        curit++;
    }
    return result;
}


