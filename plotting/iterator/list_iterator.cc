#ifdef __cplusplus
#endif
#include "list_link.h"

template <typename T> class Iterator {
public:
  Iterator() noexcept {}
  Iterator(const std::shared_ptr<link<T>> node) noexcept : curr(node) {}
  Iterator &operator++() {
    if (curr) {
      curr = curr->succ();
    }
    return *this;
  }
  Iterator operator++(int) {
    Iterator it = *this;
    ++*this;
    return it;
  }

  bool operator!=(const Iterator &it) { return curr != it.curr; }
  int64_t operator*() { return curr->val(); }

private:
  std::shared_ptr<link<T>> curr;
};