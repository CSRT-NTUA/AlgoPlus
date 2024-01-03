#ifdef __cplusplus
#include "../../classes/tree/bst.h"
#include <iostream>
#endif

int main(){
  bst<int> b;
  b.insert(1);
  b.insert(10);
  b.insert(-2);
  std::vector<int> v = b.inorder();
  for(auto & x : v){
    std::cout << x << " ";
  }
  std::cout << '\n';
}
