#ifdef __cplusplus
#include "../../classes/list/linked_list.cc"
#include <iostream>
#endif

int main() {
  linked_list<int> l1, l2;
  l1.push_back(1);
  l1.push_back(2);
  l1.push_back(-1);
  for (Iterator<int> it = l1.begin(); it != l1.end(); it++) {
    std::cout << *(it) << '\n';
  }
  if (l1.search(0)) {
    std::cout << "Yes" << '\n';
  }
}