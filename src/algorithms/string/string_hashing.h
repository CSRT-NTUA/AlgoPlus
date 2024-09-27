#ifndef STRING_HASHING_H
#define STRING_HASHING_H

#ifdef __cplusplus
#include <functional>
#include <string>
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

/**
* @brief is_palindrome function. Checks if the passed string is palindrome or not
* @param str: the passed string
* @return true if str is palindrome
* @return false otherwise
*/
bool is_palindrome(const std::string str) {
    int64_t _size = str.size();
    for(int i = 0; i<_size / 2; i++){
        if(str[i] != str[_size - i - 1]) {
            return false;
        }
    }
    return true;
}

#endif
