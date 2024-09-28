//
// Created by work on 27.09.2024.
//

#include "If.h"

#include <utility>

If::If(std::shared_ptr<SemanticObject> cond,
       std::shared_ptr<SemanticObject> on_true,
       std::shared_ptr<SemanticObject> on_false) : _condition(std::move(cond)),
                                                   _on_true(std::move(on_true)),
                                                   _on_false(std::move(on_false)) {

}

If::If(std::shared_ptr<SemanticObject> cond, std::shared_ptr<SemanticObject> on_true): _condition(std::move(cond)),
                                                                                       _on_true(std::move(on_true)),
                                                                                       _on_false(nullptr)
                                                                                       {}

std::shared_ptr<SemanticObject> If::condition() {return _condition;}
std::shared_ptr<SemanticObject> If::on_true() {return _on_true;}
std::shared_ptr<SemanticObject> If::on_false() {return _on_false;}

#include "../SemanticLogger.h"
std::string If::apply_logger(SemanticLogger *logger, std::string& spaces) {
    return logger->get(this, spaces);
}
