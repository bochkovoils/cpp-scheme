//
// Created by work on 28.09.2024.
//

#include "SemanticObject.h"

unsigned int SemanticObject::_counter = 0;

SemanticObject::SemanticObject(): _id(_counter++) {}

unsigned int SemanticObject::get_id() const {
    return _id;
}
