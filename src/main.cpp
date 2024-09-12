#include <iostream>
#include <vector>
#include <memory>

#include "tokens/Word.h"
#include "parsing/DefaultParsingState.h"
#include "parsing/EofState.h"
#include "parsing/ParsingInfo.h"
#include "parsing/text_handling/TextPointer.h"
#include "parsing/rules/ExceptSymbolsParsingRule.h"
#include "parsing/rules/SpanParsingRule.h"
#include "parsing/rules/StringEqParsingRule.h"
#include "parsing/rules/RuleRepeatingParsingRule.h"
#include "parsing/rules/SequentialParsingRule.h"
#include "parsing/rules/OrParsingRule.h"
#include "parsing/states/StringParser.h"
#include <algorithm>
#include <sstream>
#include <list>
#include <chrono>

std::vector<std::shared_ptr<Word>> parse_object(std::string& line) {
    ParsingInfo parsing;
    parsing.parse(line);
    return parsing.words();
}

int main() {
    std::cout << "Hello! Input your code!" << std::endl;
    for(std::string line; std::getline(std::cin, line);) {
        std::cout << "You wrote: " << line << std::endl;
        auto ptr = TextPointer(line.c_str());

        auto prule = StringParser(ptr);
        auto start = std::chrono::system_clock::now();
        std::list<Word*> words = prule.words();

        auto end = std::chrono::system_clock::now();

        std::chrono::duration<double> elapsed_seconds = end-start;

        std::cout << "handling time: " << elapsed_seconds.count() << "s"
                  << std::endl;

        std::for_each(words.begin(), words.end(), [](auto word) {
            std::cout << word->to_string() << std::endl;
        });

//        auto result = parse_object(line);
//        auto resline = std::ostringstream();
//        std::for_each(result.begin(), result.end(), [&resline](auto word) {
//            resline << " " << word->to_string() << "\n";
//        });
//        std::cout << "Tokens: " << resline.str() << std::endl;
    }
    std::cout << "Bye!" << std::endl;
}
