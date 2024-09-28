//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_SEMANTICOBJECT_H
#define CPP_SCHEME_SEMANTICOBJECT_H

#include <string>

class SemanticLogger;

class SemanticObject {
private:
    static unsigned int _counter;
    unsigned int _id;
public:
    SemanticObject();
    unsigned int get_id() const;
    virtual std::string apply_logger(SemanticLogger* logger, std::string& spaces)=0;
    virtual ~SemanticObject()=default;
};


#endif //CPP_SCHEME_SEMANTICOBJECT_H
