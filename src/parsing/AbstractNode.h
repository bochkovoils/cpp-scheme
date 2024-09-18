//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_ABSTRACTNODE_H
#define CPP_SCHEME_ABSTRACTNODE_H

enum AbstractNodeType {
    A_SYMBOL,
    A_NUMBER,
    A_STRING,
    LIST,
    TOKEN_WRAPPER
};

class AbstractNode {
public:
    virtual AbstractNodeType get_type()=0;
    virtual ~AbstractNode();
};


#endif //CPP_SCHEME_ABSTRACTNODE_H
