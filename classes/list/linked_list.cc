#ifdef __cplusplus
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#endif

template <typename T> class link {
private:
  T pvalue;
  std::shared_ptr<link> psucc;

public:
  int val() { return pvalue; }

  std::shared_ptr<link> &succ() { return psucc; }

  explicit link(T value = 0) : pvalue(value), psucc(nullptr) {}
};

template <typename T> class linked_list {
public:
  explicit linked_list() : root(std::make_shared<link<T>>()), tail(nullptr) {}

  bool empty() { return tail == nullptr; }

  void push_back(T key) {
    if (empty()) {
      root->succ() = std::make_shared<link<T>>(key);
      tail = root->succ();
    } else {
      tail->succ() = std::make_shared<link<T>>(key);
      tail = tail->succ();
    }
  }

  void push_front(T key) {
    if (empty()) {
      root->succ() = std::make_shared<link<T>>(key);
      tail = root->succ();
    } else {
      std::shared_ptr<link<T>> p = std::make_shared<link<T>>(key);
      p->succ() = root->succ();
      root->succ() = p;
    }
  }

  void erase(T key) {
    if (empty()) {
      std::cout << "List is Empty!";
      return;
    }
    std::shared_ptr<link<T>> t = root;
    std::shared_ptr<link<T>> to_be_removed = nullptr;
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

  std::shared_ptr<link<T>> search(T key) {
    try {
      if (empty()) {
        throw std::invalid_argument("List is empty");
      } else {
        std::shared_ptr<link<T>> t = root;
        while (t != tail && t->succ()->val() != key) {
          t = t->succ();
        }
        if (t == tail) {
          std::cout << "Element not found\n";
          return nullptr;
        }
        std::cout << "Element was found\n";
        return t->succ();
      }
    } catch (std::invalid_argument &e) {
      std::cerr << e.what() << '\n';
      return;
    }
  }

  friend constexpr std::ostream &operator<<(std::ostream &out,
                                            linked_list<T> &l1);
  friend constexpr linked_list &operator+(const linked_list<link<T>> &l1,
                                          const linked_list<link<T>> &l2);

private:
  std::shared_ptr<link<T>> root;
  std::shared_ptr<link<T>> tail;
};

int main() {
  linked_list<int> l1;
  l1.push_back(2);
  l1.push_back(3);
}