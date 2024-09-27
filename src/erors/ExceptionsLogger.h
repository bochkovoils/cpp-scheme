//
// Created by work on 26.09.2024.
//

#ifndef CPP_SCHEME_EXCEPTIONSLOGGER_H
#define CPP_SCHEME_EXCEPTIONSLOGGER_H


#include "ExceedClosingBracketException.h"

class ExceptionsLogger {
public:
    void on(ExceedClosingBracketException& e);
};


#endif //CPP_SCHEME_EXCEPTIONSLOGGER_H
