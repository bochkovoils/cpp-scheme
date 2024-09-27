//
// Created by work on 26.09.2024.
//

#include <iostream>
#include "ParsedTreeLogger.h"
#include "../painters/TreePainter.h"
#include "../painters/StructurePainter.h"

void ParsedTreeLogger::handle(LispObjectRef r) {
    StructurePainter().paint(r);
}

//void ParsedTreeLogger::show() {
//    std::cout << "Collected objects" << std::endl;
//    std::for_each(_objs.begin(), _objs.end(), [this](auto token) {
//        StructurePainter().paint(token);
//    });
//}
//
//void ParsedTreeLogger::clear() {
//    _objs.clear();
//}
