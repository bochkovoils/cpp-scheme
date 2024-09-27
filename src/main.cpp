#include <iostream>
#include <vector>
#include <memory>

#include <algorithm>
#include <sstream>
#include <list>
#include <chrono>
#include "parsing/LexicalParser.h"
#include "parsing/SyntaxParser.h"
#include "painters/TreePainter.h"
#include "environment/Environment.h"
#include "evaluation/SumOperation.h"
#include "painters/StructurePainter.h"
#include "parsing/LexemsLogger.h"
#include "parsing/ParsedTreeLogger.h"
#include "erors/ExceedClosingBracketException.h"
#include "erors/ExceptionsLogger.h"
//#include <allegro.h>

int main() {
    LexicalParser lp;
    SyntaxParser sp;
    LexemsLogger logger;
    ParsedTreeLogger ptl;

    lp.subscribe(&logger);
    lp.subscribe(&sp);

    sp.subscribe(&ptl);

    for(std::string s; std::getline(std::cin, s);) {
        try {
            lp << s;
        } catch (ExceedClosingBracketException& e) {
            ExceptionsLogger().on(e);
        }
    }
}
