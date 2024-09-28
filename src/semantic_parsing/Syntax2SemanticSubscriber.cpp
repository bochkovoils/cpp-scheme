//
// Created by work on 28.09.2024.
//

#include <iostream>
#include "Syntax2SemanticSubscriber.h"
#include "SemanticLogger.h"

void Syntax2SemanticSubscriber::handle(std::shared_ptr<SyntaxTree> o) {
    auto res = _so->parse(o);
    auto logger = SemanticLogger();
    auto spaces = std::string("");
    std::cout << res->apply_logger(&logger, spaces) << std::endl;
}
