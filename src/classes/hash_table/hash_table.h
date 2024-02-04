#ifndef ALGOPLUS_HASH_TABLE_H
#define ALGOPLUS_HASH_TABLE_H

#include <list>
#include <vector>
#include <optional>
#include <functional>
#include <iostream>

/**
 * @class hash_table
 * @tparam KeyType Type of the keys in the hash table.
 * @tparam ValueType Type of the values in the hash table.
 *
 * @brief A simple implementation of a hash table.
 * @details
 * This is a templated class for a hash table, a data structure that provides fast data
 * retrieval and storage operations based on keys. The template parameters are the type of
 * the keys and the type of the values stored in the hash table. Keys cannot be duplicate
 * and an insertion of an existing key leads to an update of the corresponding value.
 *
 * The following are the class methods
 *
 * @note Use only types that can be hashed as the KeyType.
 */
template<typename KeyType, typename ValueType> class hash_table {
public:
    /**
    * @brief Construct a hash_table object
    * @param int64_t defaultSize The initial size of the hash table (default = 101)
    */
    hash_table(int64_t defaultSize = 101) : bucketList(defaultSize) {}

    /**
    * @brief Inserts a key-value pair into the hash table.
    * @details
    * This function inserts a key-value pair into the hash table. If a pair with the same key already exists, it updates the value.
    * @param key The key to insert.
    * @param value The value to insert.
    */
    void insert(const KeyType &key, const ValueType &value) {
        auto& list = bucketList[hash(key)];
        for(auto& pair : list) {
            if(pair.first == key) {
                pair.second = value;
                return;
            }
        }
        list.emplace_back(key, value);
    }


    /**
    * @brief Retrieves the value associated with the given key.
    * @param key The key to retrieve the value for.
    * @return The value associated with the given key, if it exists. Otherwise, returns std::nullopt.
    */
    std::optional<ValueType> retrieve(const KeyType& key) {
        auto& list = bucketList[hash(key)];
        for(auto& pair : list) {
            if(pair.first == key) {
                return pair.second;
            }
        }
        return std::nullopt;
    }

    /**
    * @brief Removes the key-value pair associated with the given key from the hash table.
    * @details
    * This function removes the key-value pair associated with the given key from the hash table.
    * @param key The key to remove.
    */
    void remove(const KeyType& key) {
        auto& list = bucketList[hash(key)];
        list.remove_if([key](const auto& pair){ return pair.first == key; });
    }

    /**
    * @brief Prints the contents of the hash table.
    * @details
    * This function iterates through each bucket in the hash table and prints the key-value pairs in each bucket.
    * @note An empty bucket is denoted as an empty line.
    */
    void printList() {
        for(int i = 0; i < bucketList.size(); i++) {
            std::cout << "Bucket " << i << " : ";
            for(auto& pair : bucketList[i]) {
                std::cout << "{" << pair.first << ", " << pair.second << "} ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::hash<KeyType> hash;
    std::vector<std::list<std::pair<KeyType, ValueType>>> bucketList;
};

#endif //ALGOPLUS_HASH_TABLE_H
