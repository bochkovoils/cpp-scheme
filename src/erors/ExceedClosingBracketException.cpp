//
// Created by work on 26.09.2024.
//

#include "ExceedClosingBracketException.h"

#include <utility>

ExceedClosingBracketException::ExceedClosingBracketException(Token token): _token(std::move(token)) {

}
