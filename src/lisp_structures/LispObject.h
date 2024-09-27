//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_LISPOBJECT_H
#define CPP_SCHEME_LISPOBJECT_H

#include <string>

class StringMapper;
class Evaluator;
class LispObjectRef;

enum LispObjectId {
    TRASH=-1,
    L_NULL,
    L_CELL,
    L_NUMBER,
    L_STRING,
    L_SYMBOL,
    L_OPERATION
};

class LispObject {
public:
    virtual ~LispObject();

    virtual std::string     to_string(StringMapper* mapper)=0;
    virtual LispObjectId    get_type()=0;
    virtual LispObjectRef   evaluate(Evaluator* evaluator)=0;
};


#endif //CPP_SCHEME_LISPOBJECT_H
