//
// Created by work on 03.10.2024.
//

#ifndef CPP_SCHEME_EVALSCOLLECTOR_H
#define CPP_SCHEME_EVALSCOLLECTOR_H


#include <list>
#include "EvalObject.h"
#include "../parsing/Observer.h"
#include "../lisp_structures/LispObjectRef.h"

class EvalsCollector: public Observer<LispObjectRef> {
private:
    std::list<LispObjectRef> _agenda;
public:
    std::list<LispObjectRef>& get_agenda() {return _agenda;}
    void handle(LispObjectRef) override;
};


#endif //CPP_SCHEME_EVALSCOLLECTOR_H
