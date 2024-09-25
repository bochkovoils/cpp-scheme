//
// Created by work on 25.09.2024.
//

#include <set>
#include "ListSupport.h"

ListSupport::ListSupport(LispCell *cell) {
    _start = cell;
}

std::size_t ListSupport::size() {
    if(!_is_done) fill();
    return _cells.size();
}

LispCell *ListSupport::get(std::size_t id) {
    if(!_is_done) fill();
    return _cells.at(id);
}

LispCell* ListSupport::operator[](const size_t &index) {
    if(!_is_done) fill();
    return _cells[index];
}

void ListSupport::fill() {
    std::set<LispCell*> v;
    auto current = _start;
    while(true) {
        v.insert(current);
        _cells.push_back(current);
        auto obj = current->head();
        auto next = current->rest();

        if(next.is<LispNull>()) {
            _is_done = true;
            _is_recursive = false;
            return;
        }
        else if(next.is<LispCell>() && v.count(next.as<LispCell>())) {
            _is_done = true;
            _is_recursive = true;
            return;
        }
        else if(next.is<LispCell>()) {
            current = next.as<LispCell>();
        } else {
            throw 1;
        }
    }
}

bool ListSupport::is_recursive() {
    if(!_is_done) fill();
    return _is_recursive;
}

ListSupport ListSupport::skip(std::size_t const&i) {
    if(!_is_done) fill();
    return ListSupport(_cells[i]);
}



