//
// Created by work on 27.09.2024.
//

#include "Procedure.h"

#include "../SemanticLogger.h"
std::string Procedure::apply_logger(SemanticLogger *logger, std::string &spaces) {
    return logger->get(this, spaces);
}
