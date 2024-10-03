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
#include "machine/TreeCompiler.h"
#include "machine/EvalsCollector.h"
#include "painters/InlinePainter.h"
//#include <allegro.h>

int main() {
    LexicalParser lp;
    SyntaxParser sp;
    LexemsLogger logger;
    ParsedTreeLogger ptl;
    InlinePainter painter;

    std::shared_ptr<SemanticParser> semp(new SemanticParser());
    Syntax2SemanticSubscriber s2ss(semp);

    TreeCompiler compiler;
    EvalsCollector ec;

    lp.subscribe(&logger);
    lp.subscribe(&sp);

    sp.subscribe(&ptl);
    sp.subscribe(&s2ss);

    s2ss.subscribe(&compiler);
    compiler.subscribe(&ec);


    for(std::string s; std::getline(std::cin, s);) {
        try {
            lp << s;
            std::shared_ptr<VarTable> vt = std::make_shared<VarTable>();
            VirtualMachine vm(ec.get_agenda().back(), vt);
            vm.eval();
            std::cout << vm.result()->to_string(&painter) << std::endl;
        } catch (ExceedClosingBracketException& e) {
            ExceptionsLogger().on(e);
        } catch (int e) {
            std::cout << "Ti idesh nahui po prichine konchenniy dolbaeb " << e << " raz" << std::endl;
        }
    }
//    std::vector<OpcodeObject> data{OpcodeObject(Opcode::LOAD, 1),
//                                   OpcodeObject(1),
//                                   OpcodeObject(Opcode::PUSH_NUMBER),
//                                   OpcodeObject(100),
//                                   OpcodeObject(Opcode::PUSH_NUMBER),
//                                   OpcodeObject(200),
//                                   OpcodeObject(Opcode::RET),
//                                   OpcodeObject(NOOP),
//                                   OpcodeObject(Opcode::LOAD, 0),
//                                   OpcodeObject(200),
//                                   OpcodeObject(Opcode::RET)};
//    std::shared_ptr<ByteCode> code(new ByteCode(data.begin(), data.end()));
//    std::cout << CodePrinter().get(code) << std::endl;
}
