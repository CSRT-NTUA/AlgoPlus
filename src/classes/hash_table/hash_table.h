#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <functional>
#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

/**
 * @class hash_table
 * @tparam KeyType Type of the keys in the hash table.
 * @tparam ValueType Type of the values in the hash table.
 *
 * @brief A simple implementation of a hash table.
 * @details
 * This is a templated class for a hash table, a data structure that provides
 * fast data retrieval and storage operations based on keys. The template
 * parameters are the type of the keys and the type of the values stored in the
 * hash table. Keys cannot be duplicate and an insertion of an existing key
 * leads to an update of the corresponding value.
 *
 * The following are the class methods
 *
 * @note Use only types that can be hashed as the KeyType.
 */
template <typename KeyType, typename ValueType> class hash_table {
public:
  /**
   * @brief Construct a new hash table object
   *
   * @param v the initializer vector
   */
  hash_table(std::vector<std::pair<KeyType, ValueType>> v = {}) {
    if (!v.empty()) {
      for (auto &x : v) {
        this->insert(x.first, x.second);
      }
    }
  }

  /**
   * @brief Copy constructor of the hash_table
   *
   * @param h the hash table we want to copy
   */
  hash_table(const hash_table &h) {
    bucketList = h.bucketList;
    hash = h.hash;
  }

  /**
   * @brief operator = for the hash_table class
   * @param h the hash table we want to copy
   * @return hash_table&
   */
  hash_table &operator=(const hash_table &h) {
    bucketList = h.bucketList;
    hash = h.hash;
    return *this;
  }

  /**
   * @brief Destroy the hash table object
   */
  ~hash_table() { bucketList.clear(); }

  /**
   * @brief Inserts a key-value pair into the hash table.
   * @details
   * This function inserts a key-value pair into the hash table. If a pair with
   * the same key already exists, it updates the value.
   * @param key The key to insert.
   * @param value The value to insert.
   */
  void insert(const KeyType &key, const ValueType &value) {
    auto &list = bucketList[hash(key)];
    for (auto &pair : list) {
      if (pair.first == key) {
        pair.second = value;
        return;
      }
    }
    list.emplace_back(key, value);
  }

  /**
   * @brief Retrieves the value associated with the given key.
   * @param key The key to retrieve the value for.
   * @return The value associated with the given key, if it exists. Otherwise,
   * returns std::nullopt.
   */
  std::optional<ValueType> retrieve(const KeyType &key) {
    auto &list = bucketList[hash(key)];
    for (auto &pair : list) {
      if (pair.first == key) {
        return pair.second;
      }
    }
    return std::nullopt;
  }

  /**
   * @brief Removes the key-value pair associated with the given key from the
   * hash table.
   * @details
   * This function removes the key-value pair associated with the given key from
   * the hash table.
   * @param key The key to remove.
   */
  void remove(const KeyType &key) {
    auto &list = bucketList[hash(key)];
    list.remove_if([key](const auto &pair) { return pair.first == key; });
  }

  class Iterator;

  Iterator begin() { return Iterator(bucketList, 0); }

  Iterator end() { return Iterator(bucketList, bucketList.size()); }

  /**
   * @brief << operator for hash_table class
   * @return std::ostream&
   */
  friend std::ostream &operator<<(std::ostream &out,
                                  hash_table<KeyType, ValueType> &h) {
    out << '[';
    for (auto &[key, list] : h.bucketList) {
      for (auto &pair : h.bucketList[key]) {
        out << "{" << pair.first << ", " << pair.second << "} ";
      }
      out << '\n';
    }
    out << ']';
  }

private:
  std::hash<KeyType> hash;
  // std::vector<std::list<std::pair<KeyType, ValueType>>> bucketList;
  std::unordered_map<size_t, std::list<std::pair<KeyType, ValueType>>>
      bucketList;
};

/**
 * @brief Iterator class
 */
template <typename KeyType, typename ValueType>
class hash_table<KeyType, ValueType>::Iterator {
private:
  std::unordered_map<size_t, std::list<std::pair<KeyType, ValueType>>>
      bucketList;
  std::vector<size_t> key_values;
  int64_t index;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param bucket the bucket list
   */
  explicit Iterator(
      const std::unordered_map<size_t, std::list<std::pair<KeyType, ValueType>>>
          &bucket,
      int64_t index) noexcept
      : bucketList(bucket), index(index) {
    for (auto &x : bucketList) {
      key_values.push_back(x.first);
    }
  }

  /**
   * @brief operator = for hash table iterator class
   *
   * @param bucket the bucket list
   * @return Iterator&
   */
  Iterator &operator=(
      const std::unordered_map<size_t, std::list<std::pair<KeyType, ValueType>>>
          &bucket) {
    this->bucketList = bucket;
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator&
   */
  Iterator &operator++() {
    if (index < key_values.size()) {
      index++;
    }
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator&
   */
  Iterator operator++(int) {
    Iterator it = *this;
    ++*(this);
    return it;
  }

  /**
   * @brief operator != for Type Iterator
   *
   * @param it the iterator we want to make the check
   * @return true if the current list that exist in the index is not equal to
   * the it.list that exist in the it.index
   * @return false otherwise
   */
  bool operator!=(const Iterator &it) {
    std::list<std::pair<KeyType, ValueType>> l1 = bucketList[key_values[index]];
    std::list<std::pair<KeyType, ValueType>> l2 =
        bucketList[it.key_values[it.index]];
    return index != it.index && l1 != l2;
    return false;
  }

  /**
   * @brief operator * for Type Iterator
   *
   * @return std::list<std::pair<KeyType, ValueType>> the list of the current
   * index
   */
  std::list<std::pair<KeyType, ValueType>> operator*() {
    return bucketList[key_values[index]];
  }
};

#endif // HASH_TABLE_H
