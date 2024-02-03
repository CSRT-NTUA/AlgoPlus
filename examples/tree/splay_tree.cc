#ifdef __cplusplus
#include "../../src/classes/tree/splay_tree.h"
#include <iostream>
#endif

int main() {
  splay_tree<int> s;
  s.insert(10);
  s.insert(5);
  s.insert(14);
  s.insert(3);
  s.insert(20);
  s.visualize();
}