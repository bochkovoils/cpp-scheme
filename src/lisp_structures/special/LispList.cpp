////
//// Created by work on 26.09.2024.
////
//
//#include <set>
//#include "LispList.h"
//#include "../LispNull.h"
//
//LispList::LispList(LispObjectRef cell): _done(false), _head(cell) {}
//
//LispObjectRef LispList::operator[](const size_t &) {
////    if(!_done)
//}
//
//LispObjectRef LispList::car() {
//    return LispObjectRef();
//}
//
//LispObjectRef LispList::cdr() {
//    return LispObjectRef();
//}
//
//void LispList::reinit() {
//    std::set<LispObject*> visited{};
//    LispObjectRef current = _head;
//    for(;;) {
//        if(current.is<LispNull>()) {
//            return;
//        }
//        if(bool(visited.count(current.get()))) {
//            _is_recursive = true;
//            return;
//        }
//        visited.insert(current.get());
//        _cells.push_back(current);
//    }
//}
