//
// Created by work on 25.09.2024.
//

#ifndef CPP_SCHEME_LISTSUPPORT_H
#define CPP_SCHEME_LISTSUPPORT_H


#include <vector>
#include "../lisp_structures/LispCell.h"

class ListSupport {
private:
    LispCell*               _start;
    std::vector<LispCell*>  _cells;
    bool                    _is_recursive;
    bool                    _is_done;

    void fill();

public:
    explicit ListSupport(LispCell* cell);
    std::size_t size();
    ListSupport skip(std::size_t const&);
    LispCell* get(std::size_t id);
    LispCell* operator[](std::size_t const& index);

    bool is_recursive();
};


#endif //CPP_SCHEME_LISTSUPPORT_H
