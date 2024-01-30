#ifndef TRIE_H
#define TRIE_H

#ifdef __cplusplus
#include <iostream>
#endif

/*
 *trie class
 */
template <typename T> class trie {
private:
  struct node {
    std::shared_ptr<node> characters[26]{nullptr};
    bool end_word;
  };

public:
  explicit trie(std::vector<std::string> v = {}) noexcept {}

  /*
   *empty function.
   *returns true if the trie is empty.
   */
  bool empty();
  /*
   *insert function.
   *@param key: the key to be inserted.
   */
  void insert(std::string key);

  /*
   *remove function.
   *@param key: the key to be removed.
   */
  void remove(std::string key);
  /*
   *search function.
   *@param key: the key to be searched.
   *returns true if the word exist in the tree.
   */
  bool search(std::string key);

private:
};

#endif