//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPOBJECT_H
#define CPP_SCHEME_LISPOBJECT_H

class StructuresVisitor;

class LispObject {
public:
    virtual ~LispObject();

    virtual void apply_visitor(StructuresVisitor* visitor)=0;
};


#endif //CPP_SCHEME_LISPOBJECT_H
