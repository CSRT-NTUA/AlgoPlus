#ifdef __cplusplus
#include "../../src/classes/list/doubly_linked_list.h"
#include <iostream>
#endif

int main() {
  doubly_linked_list<int> l1({5, 6}), l2;
  l1.push_back(1);
  l1.push_back(3);
  l1.push_back(4);
  std::cout << l1.size() << '\n';
  std:: cout << l1 << '\n';
  if(l1.search(3)){
    std::cout << "YAY" << '\n';
  }
  for (doubly_list_iter<int> it = l1.begin(); it != l1.end(); it++) {
    std::cout << *(it) << '\n';
  }
}
