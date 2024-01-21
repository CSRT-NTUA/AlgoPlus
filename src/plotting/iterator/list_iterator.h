#ifdef __cplusplus
#include "list_link.h"
#endif

/*
 *Iterator class for list<T>
 */
template <typename T> class list_iter {
public:
  list_iter() noexcept {}
  /*
   *copy constructor for list_iter class.
   *@param node: the other list root.
   */
  list_iter(const std::shared_ptr<__link<T>> node) noexcept : curr(node) {}

  /*
   *operator ++ for list_iter class.
   */
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

  /*
   *operator != for list_iter class.
   */
  bool operator!=(const list_iter &it) { return curr != it.curr; }

  /*
   *operator * for list_iter class.
   * i.e. list_iter<int> it = l.begin();
   * *(it) -> gives the value of the first element.
   */
  T operator*() { return curr->val(); }

private:
  std::shared_ptr<__link<T>> curr;
};

/*
 *Iterator for the class doubly_linked_list<T>
 */
template <typename T> class doubly_list_iter {
public:
  doubly_list_iter() noexcept {}
  /*
   *copy constructor for doubly_list_iter class.
   *@param node: the other list root.
   */
  doubly_list_iter(const std::shared_ptr<doubly_link<T>> node) noexcept
      : curr(node) {}
  doubly_list_iter &operator++() {
    if (curr) {
      curr = curr->succ();
    }
    return *this;
  }

  /*
   *operator ++ for doubly_list_iter class.
   */
  doubly_list_iter operator++(int) {
    doubly_list_iter it = *this;
    ++*this;
    return it;
  }

  /*
   *operator -- for doubly_list_iter class.
   */
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

  /*
   *operator != for list_iter class.
   */
  bool operator!=(const doubly_list_iter &it) { return curr != it.curr; }

  /*
   *operator * for list_iter class.
   * i.e. list_iter<int> it = l.begin();
   * *(it) -> gives the value of the first element.
   */
  T operator*() { return curr->val(); }

private:
  std::shared_ptr<doubly_link<T>> curr;
};