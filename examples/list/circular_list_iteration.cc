#ifdef __cplusplus
#include "../../src/classes/list/circular_linked_list.h"
#include <iostream>
#endif

int main() {
  circular_linked_list<char> l({'a', 'b', 'c', 'd'});
  l.push_back('a');
  l.push_back('b');
  l.push_back('c');
  l.push_back('d');
  l.push_back('e');
  l.push_back('f');
  for (auto it = l.begin(); it != l.end(); it++) {
    std::cout << *(it) << " ";
  }
  std::cout << '\n';
  l.visualize();
}