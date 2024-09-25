//
// Created by work on 24.09.2024.
//

#ifndef CPP_SCHEME_LISPOBJECTREF_H
#define CPP_SCHEME_LISPOBJECTREF_H


#include "LispObject.h"

struct MovRef;

class LispObjectRef {
private:
    mutable unsigned int* _counter;
    LispObject* _ptr;
public:
    LispObjectRef(LispObjectRef&);
    LispObjectRef(LispObjectRef const&);
    LispObjectRef & operator=(const LispObjectRef&) = delete;
    LispObjectRef & operator=(MovRef);
    explicit LispObjectRef(LispObject*);
    LispObjectRef();

    LispObject& operator*();
    LispObject* operator->();
    LispObject* get();
    LispObjectId get_type() { return _ptr->get_type(); };

    bool empty() const;

    template<class Typename> Typename* as() {
        auto res = dynamic_cast<Typename*>(_ptr);
        if(res == nullptr)
            throw 1;
        return res;
    }
    template<class Typename> bool is() {
        auto r = dynamic_cast<Typename*>(_ptr);
        return r != nullptr;
    }

    ~LispObjectRef();

};

struct MovRef  {
    LispObjectRef& ref;
};;


#endif //CPP_SCHEME_LISPOBJECTREF_H
