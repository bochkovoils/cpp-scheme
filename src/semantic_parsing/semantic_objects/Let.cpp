//
// Created by work on 28.09.2024.
//

#include <algorithm>
#include "Let.h"

Let::Let(std::map<std::size_t, std::shared_ptr<SemanticObject>> &id2from,
         std::vector<std::shared_ptr<SemanticObject>> &body): _id2form(id2from), _body(body) {

}

std::vector<std::shared_ptr<SemanticObject>> Let::body() {
    return _body;
}

std::vector<std::size_t> Let::symbols() {
    std::vector<std::size_t> result;
    std::for_each(_id2form.begin(), _id2form.end(), [&result](const std::pair<const std::size_t,
                                                                        std::shared_ptr<SemanticObject>>& o){
        result.push_back(o.first);
    });
    return result;
}

std::vector<std::shared_ptr<SemanticObject>> Let::eval_forms() {
    std::vector<std::shared_ptr<SemanticObject>> result;
    std::for_each(_id2form.begin(), _id2form.end(), [&result](const std::pair<const std::size_t,
            std::shared_ptr<SemanticObject>>& o){
        result.push_back(o.second);
    });
    return result;
}

