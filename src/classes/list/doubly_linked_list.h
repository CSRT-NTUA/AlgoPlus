#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#ifdef __cplusplus
#include "../../plotting/iterator/list_iterator.h"
#include <iostream>
#endif

template <typename T> class doubly_linked_list {
public:
  explicit doubly_linked_list(std::vector<T> __elements = {})
      : root(std::make_shared<doubly_link<T>>()), tail(nullptr), __size(0) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->push_back(x);
      }
    }
  }

  bool empty() { return tail == nullptr; }

  size_t size() { return __size; }

  doubly_list_iter<T> begin() { return doubly_list_iter<T>(root); }

  doubly_list_iter<T> end() { return doubly_list_iter<T>(nullptr); }

  bool search(T key) {
    if (this->empty()) {
      return false;
    } else {
      std::shared_ptr<doubly_link<T>> t = root;
      while (t != tail && t->succ()->val() != key) {
        t = t->succ();
      }
      if (t == tail || t == nullptr) {
        return false;
      }
      return true;
    }
    return false;
  }

  void push_back(T key) {
    std::shared_ptr<doubly_link<T>> p = std::make_shared<doubly_link<T>>(key);
    if (!root) {
      root = p;
    }
    if (tail != nullptr) {
      tail->succ() = p;
    }
    p->succ() = nullptr;
    p->prev() = tail;
    tail = p;
    __size++;
  }

  void push_front(T key) {
    std::shared_ptr<doubly_link<T>> p = new_node(key);
    p->succ() = root;
    p->prev() = nullptr;
    if (root != nullptr) {
      root->prev() = p;
    }
    root = p;
    __size++;
  }

  std::vector<T> elements() {
    std::vector<T> __elements;
    if (this->empty()) {
      return __elements;
    }
    doubly_list_iter<T> it = this->begin();
    it++;
    for (; it != this->end(); it++) {
      __elements.push_back(*(it));
    }
    return __elements;
  }

  friend std::ostream &operator<<(std::ostream &out, doubly_linked_list<T> &l) {
    doubly_list_iter<T> it = l.begin();
    it++;
    out << '{';
    for (; it != l.end(); it++) {
      out << *(it) << ' ';
    }
    out << '}' << '\n';
    return out;
  }

private:
  std::shared_ptr<doubly_link<T>> root;
  std::shared_ptr<doubly_link<T>> tail;
  size_t __size;

  std::shared_ptr<doubly_link<T>> new_node(T key) {
    std::shared_ptr<doubly_link<T>> p = std::make_shared<doubly_link<T>>(key);
    p->succ() = nullptr;
    p->prev() = nullptr;
    return p;
  }
};

#endif