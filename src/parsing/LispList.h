//
// Created by work on 17.09.2024.
//

#ifndef CPP_SCHEME_LISPLIST_H
#define CPP_SCHEME_LISPLIST_H


#include <list>
#include "AbstractNode.h"

class LispList: public AbstractNode {
    typedef std::list<AbstractNode*>::iterator       iterator;
    typedef std::list<AbstractNode*>::const_iterator const_iterator;
private:
    std::list<AbstractNode*> _nodes;
public:
    AbstractNodeType get_type() override {return AbstractNodeType::LIST;}

    void push_back(AbstractNode* node);
    void push_front(AbstractNode* node);
    [[nodiscard]] std::size_t size() const {return _nodes.size();}

    iterator begin() {return _nodes.begin(); }
    iterator end()   {return _nodes.end();   }
    [[nodiscard]] const_iterator begin() const  { return _nodes.begin(); }
    [[nodiscard]] const_iterator end() const    { return _nodes.end(); }
};


#endif //CPP_SCHEME_LISPLIST_H
