#ifdef __cplusplus
#include "../../src/classes/tree/avl_tree.h"
#include <iostream>
#endif

int main() {
  avl_tree<int> a;
  avl_tree<std::vector<int>> b;
  b.insert({4, 5, 6});
  b.insert({1, 3, 4});
  b.insert({5, 6, 7});
  std::vector<std::vector<int>> r = b.inorder();
  for (auto &x : r) {
    for (auto &y : x) {
      std::cout << y << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
  a.insert(1);
  a.insert(-10);
  a.insert(10);
  std::vector<int> v = a.inorder();
  for (auto &x : v) {
    std::cout << x << " ";
  }
  std::cout << '\n';
}
