#ifdef __cplusplus
#include "../../plotting/iterator/list_iterator.h"
#include <iostream>
#endif

template <typename T> class linked_list {
public:
  explicit linked_list(std::vector<T> __elements = {})
      : root(std::make_shared<__link<T>>()), tail(nullptr) {
    if (!__elements.empty()) {
      for (T &x : __elements) {
        this->push_back(x);
      }
    }
  }

  bool empty() { return tail == nullptr; }

  list_iter<T> begin() { return list_iter<T>(root); }

  list_iter<T> end() { return list_iter<T>(nullptr); }

  void push_back(T key) {
    if (empty()) {
      root->succ() = std::make_shared<__link<T>>(key);
      tail = root->succ();
    } else {
      tail->succ() = std::make_shared<__link<T>>(key);
      tail = tail->succ();
    }
  }

  void push_front(T key) {
    if (empty()) {
      root->succ() = std::make_shared<__link<T>>(key);
      tail = root->succ();
    } else {
      std::shared_ptr<__link<T>> p = std::make_shared<__link<T>>(key);
      p->succ() = root->succ();
      root->succ() = p;
    }
  }

  void erase(T key) {
    if (empty()) {
      std::cout << "List is Empty!";
      return;
    }
    std::shared_ptr<__link<T>> t = root;
    std::shared_ptr<__link<T>> to_be_removed = nullptr;
    while (t != tail && t->succ()->val() != key) {
      t = t->succ();
    }
    if (t == tail) {
      std::cout << "Element not found\n";
      return;
    }
    to_be_removed = t->succ();
    t->succ() = t->succ()->succ();
    to_be_removed.reset();
    if (t->succ() == nullptr) {
      tail = t;
    }
    if (root == tail) {
      tail = nullptr;
    }
  }

  bool search(T key) {
    try {
      if (empty()) {
        throw std::invalid_argument("List is empty");
      } else {
        std::shared_ptr<__link<T>> t = root;
        while (t != tail && t->succ()->val() != key) {
          t = t->succ();
        }
        if (t == tail) {
          return false;
        }
        return true;
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return false;
    }
  }

  friend std::ostream &operator<<(std::ostream &out, linked_list<T> &l1) {
    out << '{';
    for (list_iter<T> it = l1.begin(); it != l1.end(); it++) {
      out << *it << ' ';
    }
    out << '}' << '\n';
    return out;
  }
  friend constexpr linked_list &operator+(const linked_list<__link<T>> &l1,
                                          const linked_list<__link<T>> &l2);

private:
  std::shared_ptr<__link<T>> root;
  std::shared_ptr<__link<T>> tail;
};
