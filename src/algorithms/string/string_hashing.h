#ifndef STRING_HASHING_H
#define STRING_HASHING_H

#ifdef __cplusplus
#include <functional>
#include <string>
#include <unordered_map>
#endif


/**
* @brief string hasher class
* very useful for fast insert/search for strings as it
* uses the builtin hash function
*/
class string_hasher {
private:
    std::unordered_map<size_t, int> hash_table;

public:
    explicit string_hasher () noexcept { }

    void insert(const std::string str) noexcept {
        size_t hashed = std::hash<std::string>{}(str);
        hash_table[hashed] = 1;
    }

    bool search(const std::string str) noexcept {
        size_t hashed = std::hash<std::string>{}(str);
        return hash_table[hashed] != 0;
    }

    unsigned long long size() { return hash_table.size(); }
};



#endif
