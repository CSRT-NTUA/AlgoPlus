#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
#include <iostream>
#endif

/**
 *@brief single linked list class
 */

template <typename T> class linked_list {
public:
  /**
   *@brief linked_list class constructor
   *@param __elements: you can provide the constructor with a vector of elements
   *so you dont have to do multiple push backs yourself.
   */
  explicit linked_list(std::vector<T> __elements = {}) noexcept
      : root(nullptr), tail(nullptr), __size(0) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->push_back(x);
      }
    }
  }

  /**
   *@brief empty function.
   *Returns true if the list is empty.
   */
  bool empty() { return root == nullptr; }

  /**
   *@brief size function.
   *Returns the size of the list.
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
   *@brief push_back function.
   *@param key: the key to be pushed back.
   */
  void push_back(T key);

  /**
   *@brief push_front function.
   *@param key: the key to be pushed in front.
   */
  void push_front(T key);

  /**
   *@brief erase function.
   *@param key: the key to be erased.
   */
  void erase(T key);

  /**
   *@brief search function.
   *@param key: the key to be searched.
   *@returns true if key exists in the list.
   */
  bool search(T key);

  /**
   *@brief elements function.
   *@returns vector<T>: the elements of the list.
   */
  std::vector<T> elements();

  /**
   *@brief reverse function.
   */
  void reverse();

  /**
   *@brief << operator for the linked_list class.
   */
  friend std::ostream &operator<<(std::ostream &out, linked_list<T> &l1) {
    out << '{';
    std::shared_ptr<node> head = l1.root;
    while (head) {
      out << head->val << ' ';
      head = head->next;
    }
    out << '}' << '\n';
    return out;
  }

private:
  /**
   * @brief struct for the node
   * @param val: the value of the node
   * @param next: pointer to the next.
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

template <typename T> void linked_list<T>::push_back(T key) {
  std::shared_ptr<node> p = std::make_shared<node>(key);
  if (root == nullptr) {
    root = p;
  } else {
    tail->next = p;
  }
  tail = p;
  __size++;
}

template <typename T> void linked_list<T>::push_front(T key) {
  std::shared_ptr<node> p = std::make_shared<node>(key);
  p->next = root;
  root = p;
  __size++;
}

template <typename T> void linked_list<T>::erase(T key) {
  if (empty()) {
    return;
  }
  std::shared_ptr<node> t = root;
  std::shared_ptr<node> to_be_removed = nullptr;
  while (t != tail && t->next->val != key) {
    t = t->next;
  }
  if (t == tail) {
    return;
  }
  to_be_removed = t->next;
  t->next = t->next->next;
  to_be_removed.reset();
  if (t->next == nullptr) {
    tail = t;
  }
  if (root == tail) {
    tail = nullptr;
  }
  __size--;
}

template <typename T> bool linked_list<T>::search(T key) {
  try {
    if (empty()) {
      return false;
    } else {
      std::shared_ptr<node> t = root;
      while (t != tail && t->val != key) {
        t = t->next;
      }
      if (t == tail || t == nullptr) {
        return false;
      }
      return true;
    }
  } catch (std::invalid_argument &e) {
    std::cerr << e.what() << '\n';
    return false;
  }
}

template <typename T> std::vector<T> linked_list<T>::elements() {
  std::vector<T> __elements;

  if (this->empty()) {
    return __elements;
  }
  std::shared_ptr<node> head = root;
  while (head) {
    __elements.push_back(head->val);
    head = head->next;
  }
  return __elements;
}

template <typename T> void linked_list<T>::reverse() {
  std::shared_ptr<node> current = root;
  std::shared_ptr<node> prev{nullptr}, next{nullptr};

  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  root = prev;
}

/**
 * @brief Iterator class
 */
template <typename T> class linked_list<T>::Iterator {
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
