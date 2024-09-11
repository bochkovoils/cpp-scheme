#include <iostream>
#include <vector>
#include <memory>

#include "tokens/Word.h"
#include "parsing/DefaultParsingState.h"
#include "parsing/EofState.h"
#include "parsing/ParsingControl.h"
#include <algorithm>
#include <sstream>

std::vector<std::shared_ptr<Word>> parse_object(std::string& line) {
    ParsingControl parsing;
    parsing.parse(line);
    return parsing.words();
}

int main() {
    std::cout << "Hello! Input your code!" << std::endl;
    for(std::string line; std::getline(std::cin, line);) {
        std::cout << "You wrote: " << line << std::endl;
        auto result = parse_object(line);
        auto resline = std::ostringstream();
        std::for_each(result.begin(), result.end(), [&resline](auto word) {
            resline << " " << word->to_string() << "\n";
        });
        std::cout << "Tokens: " << resline.str() << std::endl;
    }
    std::cout << "Bye!" << std::endl;
}
