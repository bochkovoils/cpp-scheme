//
// Created by work on 18.09.2024.
//

#ifndef CPP_SCHEME_TREEPAINTER_H
#define CPP_SCHEME_TREEPAINTER_H


#include "../parsing/AbstractNode.h"
#include "../parsing/LispList.h"
#include "../parsing/TreeBuilder.h"

class TreePainter {
public:
    void paint_tree(AbstractNode* node);


    std::list<std::tuple<int, AbstractNode*>> collect(AbstractNode* node);
    virtual std::string make_string(LispList* list);
    virtual std::string make_string(Symbol* list);
    virtual std::string make_string(TokenWrapper* list);
    virtual std::string ms(AbstractNode* list);
    std::string get_spaces(unsigned int spaces);
};


#endif //CPP_SCHEME_TREEPAINTER_H
