//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPCELL_H
#define CPP_SCHEME_LISPCELL_H


#include <list>
#include "LispObject.h"
#include "LispObjectRef.h"
#include "LispNull.h"



class LispCell: public LispObject {
private:
    LispObjectRef _head;
    LispObjectRef _rest;

public:
    static LispObjectRef from_list(std::list<LispObjectRef>::iterator begin,
                                   std::list<LispObjectRef>::iterator end);

    LispCell();
    LispCell(LispObjectRef, LispObjectRef);

    LispObjectRef head();
    LispObjectRef rest();

    void set_head(LispObjectRef);
    void set_rest(LispObjectRef);

    std::string to_string(StringMapper *mapper) override;
    LispObjectId get_type() override { return LispObjectId::L_CELL; }

};


template<typename... Types>
inline LispObjectRef make_list(Types&... args);

template<>
inline LispObjectRef make_list() {
    return LispNull::get();
}

template<typename First, typename... Types>
LispObjectRef make_list(First& f, Types&... rest) {
    return LispObjectRef(new LispCell(f, make_list(rest...)));
}


#endif //CPP_SCHEME_LISPCELL_H
