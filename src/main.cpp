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


int main() {
    std::cout << "Hello! Input your code!" << std::endl;
    for(std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
        auto parser = Parser(line.c_str());
        auto start = std::chrono::high_resolution_clock::now();
        auto node = TreeBuilder(&parser).parse_all();
        auto stop = std::chrono::high_resolution_clock::now();

        TreePainter().paint_tree(node);

        std::cout << "Time in microseconds: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << std::endl;
    }
    std::cout << "Bye!" << std::endl;
}
