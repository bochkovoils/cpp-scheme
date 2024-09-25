//
// Created by work on 24.09.2024.
//

#include <iostream>
#include "LispObjectRef.h"


LispObject *LispObjectRef::get() {
    return _ptr;
}

LispObject &LispObjectRef::operator*() {
    return *_ptr;
}

LispObject *LispObjectRef::operator->() {
    return _ptr;
}

LispObjectRef::LispObjectRef(LispObject *ptr): _counter(new unsigned int(1)), _ptr(ptr)
{
//    std::cout << "created object " << _ptr << " counter: " << *_counter << " type " << _ptr->get_type() << std::endl;
}

LispObjectRef::LispObjectRef(LispObjectRef &obj) {
    _counter = obj._counter;
    _ptr = obj._ptr;
    (*_counter)++;
//    std::cout << "COPY OF" << _ptr <<" / " << *_counter << " / "<< _ptr->get_type() << std::endl;
}

LispObjectRef::~LispObjectRef() {
    (*_counter)--;
    if(empty()) return;
//    std::cout << "Removing... There is " << std::to_string(*_counter) << " for " << _ptr << " with type " << _ptr->get_type() << std::endl;
    if(*_counter == 0) {
//        std::cout << "Object has been deleted: " << _ptr << std::endl;
        delete _counter;
        delete _ptr;
    }
}

LispObjectRef::LispObjectRef(const LispObjectRef &obj) {
    _counter = obj._counter;
    _ptr = obj._ptr;
    (*_counter)++;
//    std::cout << "COPY OF" << _ptr <<" / " << *_counter << " / "<< _ptr->get_type() << std::endl;
}

//template<class Typename>
//bool LispObjectRef::is() {
//    auto r = dynamic_cast<Typename*>(_ptr);
//    return r != nullptr;
//}

bool LispObjectRef::empty() const {
    return _ptr == nullptr;
}

LispObjectRef::LispObjectRef(): _counter(nullptr), _ptr(nullptr) {

}

LispObjectRef &LispObjectRef::operator=(MovRef mv) {
    (*_counter)--;
    if(*_counter == 0) {
        delete _counter;
        delete _ptr;
    }

    _counter = mv.ref._counter;
    _ptr = mv.ref._ptr;
    (*_counter)++;
    return *this;
}

