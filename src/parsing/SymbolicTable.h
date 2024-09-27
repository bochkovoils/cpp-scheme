//
// Created by work on 27.09.2024.
//

#ifndef CPP_SCHEME_SYMBOLICTABLE_H
#define CPP_SCHEME_SYMBOLICTABLE_H


#include <map>
#include <string_view>

class SymbolicTable {
public:
    static SymbolicTable& get();
private:
    std::size_t _maxid = 0;
    std::map<std::string, std::size_t> _str2id;
    std::map<std::size_t, std::string> _id2str;
    SymbolicTable() = default;
    static SymbolicTable _instance;
public:
    bool contains(std::string_view const& s);
    std::size_t get_id(std::string_view const& s);
    std::size_t insert(std::string_view const& s);
    std::string get_symbol(const size_t &id);
    std::size_t size() const;
};


#endif //CPP_SCHEME_SYMBOLICTABLE_H
