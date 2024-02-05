#pragma once
#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#ifdef __cplusplus
#include <iostream>
#include <memory>
#include <vector>
#endif

/**
 * @brief circular linked list class
 */
template <typename T> class circular_linked_list {
public:
  /**
   * @brief Construct a new circular linked list object
   *
   * @param __elements vector<T> so you dont have to do multiple insertions
   */
  explicit circular_linked_list(std::vector<T> __elements = {}) noexcept
      : root(nullptr), tail(nullptr), __size(0) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->push_back(x);
      }
    }
  }

  /**
   * @brief empty function
   *
   * @return true if the list is empty
   * @return false otherwise
   */
  bool empty() { return root == nullptr; }

  /**
   * @brief size function
   *
   * @return size_t the size of the list
   */
  size_t size() { return __size; }

  class Iterator;

  /**
   * @brief pointer that points to begin
   *
   * @return Iterator
   */
  Iterator begin() { return Iterator(root); }

  /**
   * @brief pointer that points to end
   *
   * @return Iterator
   */
  Iterator end() { return Iterator(nullptr); }

  /**
   * @brief push_back function
   *
   * @param key the key to be inserted
   */
  void push_back(T key);

  /**
   * @brief push_front function
   *
   * @param key the key to be inserted
   */
  void push_front(T key);

  /**
   * @brief erase function
   *
   * @param key the key to be erased
   */
  void erase(T key);

  /**
   * @brief search function
   *
   * @param key the key to be searched
   * @return true if the key exist in the list
   * @return false otherwise
   */
  bool search(T key);

  /**
   * @brief elements function
   *
   * @return std::vector<T> the elements of the list
   */
  std::vector<T> elements();

  /**
   * @brief << operator for the circular list class
   */
  friend std::ostream &operator<<(std::ostream &out,
                                  circular_linked_list<T> &l1) {
    out << '{';
    std::shared_ptr<node> head = l1.root;
    do {
      out << head->val << ' ';
      head = head->next;
    } while (head != l1.root);
    out << '}' << '\n';
    return out;
  }

private:
  /**
   * @brief struct for the node
   * @param val the value of the node
   * @param next smart pointer to the next node
   */
  struct node {
    T val;
    std::shared_ptr<node> next;
    node(T key = 0) : val(key), next(nullptr) {}
  };

  std::shared_ptr<node> root;
  std::shared_ptr<node> tail;
  size_t __size;
};

template <typename T> void circular_linked_list<T>::push_back(T key) {
  std::shared_ptr<node> p = std::make_shared<node>(key);
  if (root == nullptr) {
    root = p;
    tail = p;
  } else {
    tail->next = p;
    tail = p;
  }
  tail->next = root;
  __size++;
}

template <typename T> void circular_linked_list<T>::push_front(T key) {
  std::shared_ptr<node> p = std::make_shared<node>(key);
  if (root == nullptr) {
    root = p;
    tail = p;
  } else {
    p->next = root;
    root = p;
    tail->next = root;
  }
  __size++;
}

template <typename T> void circular_linked_list<T>::erase(T key) {
  if (empty()) {
    return;
  }

  std::shared_ptr<node> t = root;
  std::shared_ptr<node> to_be_removed = nullptr;

  do {
    if (t->next->val == key) {
      to_be_removed = t->next;
      t->next = t->next->next;
      to_be_removed.reset();
      __size--;

      if (t->next == root) {
        tail = t;
      }

      if (root == tail) {
        tail = nullptr;
      }

      return;
    }

    t = t->next;
  } while (t != root);
}

template <typename T> bool circular_linked_list<T>::search(T key) {
  try {
    if (empty()) {
      return false;
    } else {
      std::shared_ptr<node> t = root;
      do {
        if (t->val == key) {
          return true;
        }
        t = t->next;
      } while (t != root);

      return false;
    }
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
    return false;
  }
}

template <typename T> std::vector<T> circular_linked_list<T>::elements() {
  std::vector<T> __elements;

  if (this->empty()) {
    return __elements;
  }

  std::shared_ptr<node> head = root;
  do {
    __elements.push_back(head->val);
    head = head->next;
  } while (head != root);

  return __elements;
}
/**
 * @brief Iterator class
 */
template <typename T> class circular_linked_list<T>::Iterator {
private:
  std::shared_ptr<node> curr_root;

public:
  /**
   * @brief Construct a new Iterator object
   *
   * @param l linked list type
   */
  explicit Iterator(const std::shared_ptr<node> &l) noexcept : curr_root(l) {}

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
      curr_root = curr_root->next;
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