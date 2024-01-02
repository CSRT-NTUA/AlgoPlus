#ifdef __cplusplus
#include "../../plotting/iterator/list_iterator.cc"
#include <iostream>
#endif

template <typename T> class doubly_linked_list {
public:
  explicit doubly_linked_list()
      : root(std::make_shared<doubly_link<T>>()), tail(nullptr) {}

  bool empty() { return tail == nullptr; }

  doubly_list_iter<T> begin() { return doubly_list_iter<T>(root); }

  doubly_list_iter<T> end() { return doubly_list_iter<T>(nullptr); }

  void push_back(T key) {
    std::shared_ptr<doubly_link<T>> curr = root;
    if (curr == nullptr) {
      std::shared_ptr<doubly_link<T>> p = new_node(key);
      root = p;
    } else {
      while (curr->succ() != nullptr) {
        curr = curr->succ();
      }
      std::shared_ptr<doubly_link<T>> p = new_node(key);
      curr->succ() = p;
      p->prev() = curr;
    }
  }

private:
  std::shared_ptr<doubly_link<T>> root;
  std::shared_ptr<doubly_link<T>> tail;

  std::shared_ptr<doubly_link<T>> new_node(T key) {
    std::shared_ptr<doubly_link<T>> p = std::make_shared<doubly_link<T>>(key);
    p->succ() = nullptr;
    p->prev() = nullptr;
    return p;
  }
};