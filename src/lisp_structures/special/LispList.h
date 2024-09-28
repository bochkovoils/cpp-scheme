//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_LISPLIST_H
#define CPP_SCHEME_LISPLIST_H


#include <vector>
#include "../LispObjectRef.h"

class LispList: public LispObject {
private:
    LispObjectRef               _head;
    std::vector<LispObjectRef>  _cells;
    bool                        _is_recursive=false;
    bool                        _done;

//    void reinit();
//public:
//    explicit LispList(LispObjectRef cell);
//    LispObjectRef operator[](std::size_t const&);
//    LispObjectRef car();
//    LispObjectRef cdr();
//    std::string to_string(StringMapper *mapper) override;
//    LispObjectId get_type() override { return LispObjectId::L_CELL; }
};


#endif //CPP_SCHEME_LISPLIST_H
