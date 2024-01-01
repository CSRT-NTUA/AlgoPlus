#ifdef __cplusplus
#include "../../classes/list/doubly_linked_list.cc"
#include <iostream>
#endif

int main() {
  doubly_linked_list<int> l1, l2;
  l1.push_back(1);
  l1.push_back(3);
  l1.push_back(4);
  for (doubly_list_iter<int> it = l1.begin(); it != l1.end(); it++) {
    std::cout << *(it) << '\n';
  }
}