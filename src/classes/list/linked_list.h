#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
#include <iostream>
#endif

/*
 *single linked list class
 */

template <typename T> class linked_list {
public:
  /*
   *linked_list class constructor
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

  /*
   *empty function.
   *Returns true if the list is empty.
   */
  bool empty() { return root == nullptr; }

  /*
   *size function.
   *Returns the size of the list.
   */
  size_t size() { return __size; }

  /*
   *push_back function.
   *@param key: the key to be pushed back.
   */
  void push_back(T key) {
    std::shared_ptr<node> p = std::make_shared<node>(key);
    if (root == nullptr) {
      root = p;
    } else {
      tail->next = p;
    }
    tail = p;
    __size++;
  }

  /*
   *push_front function.
   *@param key: the key to be pushed in front.
   */
  void push_front(T key) {
    std::shared_ptr<node> p = std::make_shared<node>(key);
    p->next = root;
    root = p;
    __size++;
  }

  /*
   *erase function.
   *@param key: the key to be erased.
   */
  void erase(T key) {
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

  /*
   *search function.
   *@param key: the key to be searched.
   *Returns true if key exists in the list.
   */
  bool search(T key) {
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

  /*
   *elements function.
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

  /*
   *<< operator for the linked_list class.
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
  struct node {
    T val;
    std::shared_ptr<node> next;
    node(T key = 0) : val(key), next(nullptr) {}
  };
  std::shared_ptr<node> root;
  std::shared_ptr<node> tail;
  size_t __size;
};

#endif