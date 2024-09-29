//
// Created by work on 27.09.2024.
//

#include "Quote.h"

#include "../SemanticLogger.h"
//std::string Quote::apply_logger(SemanticLogger *logger) {
//    return logger->get(this);
//}
std::string Quote::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}
