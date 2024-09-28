//
// Created by work on 28.09.2024.
//

#include "Expression.h"

#include <utility>

Expression::Expression(std::vector<std::shared_ptr<SemanticObject>> &objs,
                       std::shared_ptr<Token> token): _objs(objs), _t(std::move(token)) {}


#include "../SemanticLogger.h"
std::string Expression::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}

std::vector<std::shared_ptr<SemanticObject>> Expression::elements() {
    return _objs;
}

