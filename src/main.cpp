#include <iostream>
#include <vector>
#include <memory>

#include <algorithm>
#include <sstream>
#include <list>
#include <chrono>
#include "parsing/Parser.h"


int main() {
    std::cout << "Hello! Input your code!" << std::endl;
    for(std::string line; std::getline(std::cin, line);) {
        std::cout << line << std::endl;
        auto parser = Parser(line.c_str());
        auto res = std::list<Token>();
        while(!parser.is_end() || parser.has_tokens()) {
            res.emplace_back(parser.next_token());
        };

        std::for_each(res.begin(), res.end(), [](auto cell) {
            std::cout << "TOKEN: " << cell.get_id() << " STR: " << cell.get_value() << std::endl;
        });

    }
    std::cout << "Bye!" << std::endl;
}
