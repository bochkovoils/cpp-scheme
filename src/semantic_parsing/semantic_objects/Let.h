//
// Created by work on 28.09.2024.
//

#ifndef CPP_SCHEME_LET_H
#define CPP_SCHEME_LET_H


#include <map>
#include <memory>
#include <vector>
#include "SemanticObject.h"

class Let: public SemanticObject {
private:
    std::map<std::size_t, std::shared_ptr<SemanticObject>> _id2form;
    std::vector<std::shared_ptr<SemanticObject>> _body;
public:
    Let(std::map<std::size_t, std::shared_ptr<SemanticObject>>& id2from,
        std::vector<std::shared_ptr<SemanticObject>>& body);

    std::vector<std::shared_ptr<SemanticObject>> body();
    std::vector<std::size_t> symbols();
    std::vector<std::shared_ptr<SemanticObject>> eval_forms();
};


#endif //CPP_SCHEME_LET_H
