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
#include "painters/StructurePainter.h"
#include "parsing/LexemsLogger.h"
#include "parsing/ParsedTreeLogger.h"
#include "erors/ExceedClosingBracketException.h"
#include "erors/ExceptionsLogger.h"
#include "semantic_parsing/Syntax2SemanticSubscriber.h"
#include "machine/ByteCode.h"
#include "machine/VirtualMachine.h"
#include "machine/CodePrinter.h"
//#include <allegro.h>

int main() {
//    LexicalParser lp;
//    SyntaxParser sp;
//    LexemsLogger logger;
//    ParsedTreeLogger ptl;
//
//    std::shared_ptr<SemanticParser> semp(new SemanticParser());
//    Syntax2SemanticSubscriber s2ss(semp);
//
//    lp.subscribe(&logger);
//    lp.subscribe(&sp);
//
//    sp.subscribe(&ptl);
//    sp.subscribe(&s2ss);
//
//    for(std::string s; std::getline(std::cin, s);) {
//        try {
//            lp << s;
//        } catch (ExceedClosingBracketException& e) {
//            ExceptionsLogger().on(e);
//        }
//    }
    std::vector<OpcodeObject> data{OpcodeObject(Opcode::LOAD, 1),
                                   OpcodeObject(1),
                                   OpcodeObject(Opcode::PUSH),
                                   OpcodeObject(100),
                                   OpcodeObject(Opcode::PUSH),
                                   OpcodeObject(200),
                                   OpcodeObject(Opcode::RET),
                                   OpcodeObject(NOOP),
                                   OpcodeObject(Opcode::LOAD, 0),
                                   OpcodeObject(200),
                                   OpcodeObject(Opcode::RET)};
    std::shared_ptr<ByteCode> code(new ByteCode(data.begin(), data.end()));

    std::cout << CodePrinter().get(code) << std::endl;
}
