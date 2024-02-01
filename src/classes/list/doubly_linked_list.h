#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#ifdef __cplusplus
#include <iostream>
#endif

/**
 *@brief doubly linked list class
 */
template <typename T> class doubly_linked_list {
public:
  /**
   *@brief doubly_linked_list class constructor
   *@param __elements: you can provide the constructor with a vector of elements
   *so you dont have to do multiple push backs yourself.
   */
  explicit doubly_linked_list(std::vector<T> __elements = {}) noexcept
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

  /**
   *@brief search function.
   *@param key: the key to be searched.
   *Returns true if key exists in the list.
   */
  bool search(T key) {
    if (this->empty()) {
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
    return false;
  }

  /**
   *@brief push_back function.
   *@param key: the key to be pushed back.
   */
  void push_back(T key) {
    std::shared_ptr<node> p = std::make_shared<node>(key);
    if (root == nullptr) {
      root = p;
    }
    if (tail != nullptr) {
      tail->next = p;
    }
    p->next = nullptr;
    p->prev = tail;
    tail = p;
    __size++;
  }

  /**
   *@brief push_front function.
   *@param key: the key to be pushed in front.
   */
  void push_front(T key) {
    std::shared_ptr<node> p = std::make_shared<node>(key);
    p->next = root;
    p->prev = nullptr;
    if (root != nullptr) {
      root->prev = p;
    }
    root = p;
    __size++;
  }

  /**
   *@brief erase function.
   *@param key: the key to be erased from the list.
   */
  void erase(T key) {
    if (root == nullptr) {
      return;
    }
    if (root->val == key) {
      root = root->next;
    }
    std::shared_ptr<node> head = root;
    while (head && head->val != key) {
      head = head->next;
    }
    if (head == nullptr) {
      return;
    }
    if (head->next != nullptr) {
      head->next->prev = head->prev;
    }
    if (head->prev != nullptr) {
      head->prev->next = head->next;
    }
  }

  /**
   *@brief elements function.
   *Returns vector<T>: the elements of the list.
   */
  std::vector<T> elements() {
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

  /**
   * @brief reverse function.
   * reverses the linked list.
   */
  void reverse() {
    std::shared_ptr<node> current = root;
    std::shared_ptr<node> temp{nullptr};

    while (current != nullptr) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
    }

    if (temp) {
      root = temp->prev;
    }
  }

  /**
   *@brief << operator for the doubly_linked_list class.
   */
  friend std::ostream &operator<<(std::ostream &out, doubly_linked_list<T> &l) {
    out << '{';
    std::shared_ptr<node> head = l.root;
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
   * @param next: pointer to the next
   * @param prev: pointer to the previous
   */
  struct node {
    T val;
    std::shared_ptr<node> next;
    std::shared_ptr<node> prev;
    node(T key = 0) : val(key), next(nullptr), prev(nullptr) {}
  };
  std::shared_ptr<node> root;
  std::shared_ptr<node> tail;
  size_t __size;
};

#endif
