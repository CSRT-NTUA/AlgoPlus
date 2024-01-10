#ifdef __cplusplus
#include "list_link.h"
#endif

template <typename T> class list_iter {
public:
  list_iter() noexcept {}
  list_iter(const std::shared_ptr<__link<T>> node) noexcept : curr(node) {}
  list_iter &operator++() {
    if (curr) {
      curr = curr->succ();
    }
    return *this;
  }
  list_iter operator++(int) {
    list_iter it = *this;
    ++*this;
    return it;
  }

  bool operator!=(const list_iter &it) { return curr != it.curr; }
  T operator*() { return curr->val(); }

private:
  std::shared_ptr<__link<T>> curr;
};

template <typename T> class doubly_list_iter {
public:
  doubly_list_iter() noexcept {}
  doubly_list_iter(const std::shared_ptr<doubly_link<T>> node) noexcept
      : curr(node) {}
  doubly_list_iter &operator++() {
    if (curr) {
      curr = curr->succ();
    }
    return *this;
  }
  doubly_list_iter operator++(int) {
    doubly_list_iter it = *this;
    ++*this;
    return it;
  }
  doubly_list_iter &operator--() {
    if (curr) {
      curr = curr->prev();
    }
    return *this;
  }
  doubly_list_iter operator--(int) {
    doubly_list_iter it = *this;
    --*this;
    return it;
  }
  bool operator!=(const doubly_list_iter &it) { return curr != it.curr; }
  T operator*() { return curr->val(); }

private:
  std::shared_ptr<doubly_link<T>> curr;
};