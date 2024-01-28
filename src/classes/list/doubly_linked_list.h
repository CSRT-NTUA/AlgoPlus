#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#ifdef __cplusplus
#include <iostream>
#endif

template <typename T> class doubly_linked_list {
public:
  explicit doubly_linked_list(std::vector<T> __elements = {}) noexcept
      : root(nullptr), tail(nullptr), __size(0) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->push_back(x);
      }
    }
  }

  bool empty() { return root == nullptr; }

  size_t size() { return __size; }

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