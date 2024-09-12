//
// Created by giantdad on 12.09.24.
//

#include "TextPointer.h"

#include <memory>
#include <sstream>

TextPointer::TextPointer(const char *start_ptr,
                         const unsigned int &start_file_pos,
                         const unsigned int &start_line_pos,
                         const unsigned int &start_line) :

                         _position_ptr(start_ptr),
                         _file_position_index(start_file_pos),
                         _line_index(start_line),
                         _line_position_index(start_line_pos) {

}

const char*  TextPointer::c_ptr() const { return this->_position_ptr; }
unsigned int TextPointer::file_position() const { return this->_file_position_index; }
unsigned int TextPointer::line() const {return this->_line_index; }
unsigned int TextPointer::line_position() const {return this->_line_position_index; }

std::string TextPointer::data() const {
    std::string result;
    result.append("Line: ").append(std::to_string(_line_index)).append("\n");
    result.append("Position: ").append(std::to_string(_line_position_index)).append("\n");
    return result;
}

const char& TextPointer::operator*() const {
    return *this->_position_ptr;
}


std::unique_ptr<TextPointer> TextPointer::clone() {
    return std::move(std::make_unique<TextPointer>(
            _position_ptr,
                            _file_position_index,
                            _line_position_index,
                            _line_index
                            ));
}

bool TextPointer::is_eof() const {
    return *_position_ptr == '\0';
}

TextPointer& TextPointer::operator++() {
    if(*_position_ptr == '\0') throw 1;
    if(*_position_ptr == '\n') { _line_index++; _line_position_index=-1; }
    _position_ptr++;
    _file_position_index++;
    _line_position_index++;
    return *this;
}

const TextPointer TextPointer::operator++(int) {
    if(*_position_ptr == '\0') throw 1;
    if(*_position_ptr == '\n') { _line_index++; _line_position_index=-1; }
    _position_ptr++;
    _file_position_index++;
    _line_position_index++;
    return TextPointer(*this);
}

TextPointer& TextPointer::operator--() {

    _position_ptr--;
    _file_position_index--;
    _line_position_index--;
    _line_index--;
    return *this;
}

const TextPointer TextPointer::operator--(int) {

    return TextPointer(_position_ptr--,
                       _file_position_index--,
                       _line_position_index--,
                       _line_index--);
}

TextPointer& TextPointer::shift_to(const TextPointer &pointer) {
    _position_ptr = pointer._position_ptr;
    _file_position_index = pointer._file_position_index;
    _line_position_index = pointer._line_position_index;
    _line_index = pointer._line_index;

    return *this;
}

std::string TextPointer::dif(const TextPointer &right) {
    std::stringstream ss;
    const char* left_c_ptr;
    const char* right_c_ptr;

    if(this->_file_position_index > right._file_position_index) {
        right_c_ptr = _position_ptr;
        left_c_ptr = right._position_ptr;
    }
    else {
        left_c_ptr = _position_ptr;
        right_c_ptr = right._position_ptr;
    }
    while(left_c_ptr != right_c_ptr) {
        ss << *left_c_ptr;
        left_c_ptr++;
    }
    return ss.str();
}

TextPointer TextPointer::operator-(const int& value) const {
    return TextPointer(
            _position_ptr - value,
            _file_position_index - value,
            _line_position_index - value,
            _line_index
            );
}

TextPointer TextPointer::operator+(const int& value) const {
    return TextPointer(
            _position_ptr + value,
            _file_position_index + value,
            _line_position_index + value,
            _line_index
    );
}

bool TextPointer::operator==(const TextPointer &a) const {
    return _position_ptr == a._position_ptr;
}

bool TextPointer::operator!=(const TextPointer &a) const {
    return _position_ptr != a._position_ptr;
}