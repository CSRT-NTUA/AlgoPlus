#ifdef __cplusplus
#include "../../src/classes/list/skip_list.h"
#include <iostream>
#endif

int main() {
  skip_list<int> s(2, 0.3);
  s.insert(1);
  s.insert(4);
  s.insert(13);
  s.insert(5);
  s.insert(6);
  std::cout << s << '\n';
}