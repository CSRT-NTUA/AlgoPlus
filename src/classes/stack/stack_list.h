#ifndef STACK_H
#define STACK_H

#ifdef __cplusplus
#include <iostream>
#include <vector>
#endif

template <typename T> class stack_list {
private:
  struct node {
    T val;
    std::shared_ptr<node> next;
    std::shared_ptr<node> prev;
    node(T key) : val(key), next(nullptr), prev(nullptr) {}
  };

  std::shared_ptr<node> root;
  size_t __size;

public:
  explicit stack_list(std::vector<T> v = {}) noexcept
      : root(nullptr), __size(0) {
    if (!v.empty()) {
      for (T &x : v) {
        this->push(x);
      }
    }
  }

  size_t size() { return __size; }

  void push(T key) {
    std::shared_ptr<node> nn = std::make_shared<node>(key);
    if (!root) {
      root = nn;
      __size++;
      return;
    } else {
      root->next = nn;
      nn->prev = root;
      root = nn;
      __size++;
    }
  }

  T top() { return root->val; }

  void pop() {
    root = root->prev;
    __size--;
  }

  class Iterator;

  Iterator begin() { return Iterator(root); }

  Iterator end() { return Iterator(nullptr); }
};

/**
 * @brief Iterator class
 */
template <typename T> class stack_list<T>::Iterator {
private:
  std::shared_ptr<node> curr_root;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param s stack_list pointer
   */
  explicit Iterator(const std::shared_ptr<node> &s) noexcept : curr_root(s) {}

  /**
   * @brief = operator for Iterator type
   *
   * @param current smart pointer of type node
   * @return Iterator&
   */
  Iterator &operator=(std::shared_ptr<node> current) {
    this->curr_root = current;
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator&
   */
  Iterator &operator++() {
    if (curr_root) {
      curr_root = curr_root->prev;
    }
    return *(this);
  }

  /**
   * @brief operator ++ for type Iterator
   *
   * @return Iterator
   */
  Iterator operator++(int) {
    Iterator it = *this;
    ++*(this);
    return it;
  }

  /**
   * @brief operator != for type Iterator
   *
   * @param it const Iterator
   * @return true if curr_root == it.curr_root
   * @return false otherwise
   */
  bool operator!=(const Iterator &it) { return curr_root != it.curr_root; }

  /**
   * @brief operator * for type Iterator
   *
   * @return T the value of the node
   */
  T operator*() { return curr_root->val; }
};

#endif