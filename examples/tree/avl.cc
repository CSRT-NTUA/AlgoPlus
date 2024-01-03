#ifdef __cplusplus
#include "../../classes/tree/avl_tree.h"
#include <iostream>
#endif

int main(){
  avl_tree<int> a;
  a.insert(1);
  a.insert(-10);
  a.insert(10);
  std::vector<int> v = a.inorder();
  for(auto & x : v){
    std::cout << x << " ";
  }
  std::cout << '\n';
}
