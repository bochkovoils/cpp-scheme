//
// Created by work on 26.09.2024.
//

#include <iostream>
#include "ExceptionsLogger.h"

void ExceptionsLogger::on(ExceedClosingBracketException &e) {
    std::cout << "Exceed bracket!" << std::endl;
}
