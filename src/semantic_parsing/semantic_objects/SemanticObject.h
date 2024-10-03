//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_SEMANTICOBJECT_H
#define CPP_SCHEME_SEMANTICOBJECT_H

#include <string>
#include "../wlakers/SemanticWalker.h"
#include "../wlakers/SymbolsCollector.h"

#define SEMANTIC_WALKER_VISITOR_WALK \
    void apply_walker(SemanticWalker* walker) override { walker->walk(this); }

class SemanticLogger;

class SemanticObject {
private:
    static unsigned int _counter;
    unsigned int _id;
    S_Table      _stable;
public:
    SemanticObject();
    unsigned int get_id() const;
    virtual std::string apply_logger(SemanticLogger* logger, std::string& spaces)=0;
    virtual void        apply_walker(SemanticWalker* walker)=0;
    S_Table symbols_table() {return _stable;}
    void set_symbols_table(S_Table& s) {_stable = s;}
    virtual ~SemanticObject()=default;

};


#endif //CPP_SCHEME_SEMANTICOBJECT_H
