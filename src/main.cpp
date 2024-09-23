#include <iostream>
#include <vector>
#include <memory>

#include <algorithm>
#include <sstream>
#include <list>
#include <chrono>
#include "parsing/Parser.h"
#include "parsing/TreeBuilder.h"
#include "painters/TreePainter.h"
#include "environment/Environment.h"
#include "evaluation/SumOperation.h"


int main() {
    std::cout << "Hello! Input your code!" << std::endl;
    auto sum = new SumOperation();
    Evaluator ev = Evaluator();
    Environment::global_root->set(sum->get_symbol(), sum);
    for(std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
        auto parser = Parser(line.c_str());
        auto start = std::chrono::high_resolution_clock::now();
        auto node = TreeBuilder(&parser).parse_all();
        auto stop = std::chrono::high_resolution_clock::now();

        TreePainter().paint_tree(node);

        try {
            auto res = ev.eval(node);
            std::cout << dynamic_cast<LispNumber*>(res)->value() << std::endl;
        }
        catch (...) {
            std::cout << "ERROR!" << std::endl;
        }

        std::cout << "Time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << std::endl;
    }
    std::cout << "Bye!" << std::endl;
}
