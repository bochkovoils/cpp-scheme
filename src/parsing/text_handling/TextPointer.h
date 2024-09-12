//
// Created by giantdad on 12.09.24.
//

#ifndef CPP_SCHEME_TEXTPOINTER_H
#define CPP_SCHEME_TEXTPOINTER_H

#include <memory>
#include <optional>

class TextPointer {
private:
    const char*     _position_ptr;
    unsigned int    _file_position_index;
    unsigned int    _line_index;
    unsigned int    _line_position_index;

public:
    explicit TextPointer(const char* start_ptr,
                         unsigned int const& start_file_pos=0,
                         unsigned int const& start_line_pos=0,
                         unsigned int const& start_line=0);

    [[nodiscard]] const char* c_ptr() const;
    [[nodiscard]] unsigned int line_position() const;
    [[nodiscard]] unsigned int file_position() const;
    [[nodiscard]] unsigned int line() const;

    std::unique_ptr<TextPointer> clone();
    TextPointer& shift_to(TextPointer const& pointer);
    [[nodiscard]] std::string data() const;

    std::string dif(TextPointer const&);

    TextPointer operator+(int const& ) const;
    TextPointer operator-(int const& ) const;

    bool operator==(TextPointer const&) const;
    bool operator!=(TextPointer const&) const;

    char const& operator*() const;
    TextPointer& operator++();
    TextPointer& operator--();
    const TextPointer operator++(int);
    const TextPointer operator--(int);
    [[nodiscard]] bool is_eof() const;
};


#endif //CPP_SCHEME_TEXTPOINTER_H
