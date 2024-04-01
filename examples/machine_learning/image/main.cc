#include "../../../src/machine_learning/image/huffman_encoding.h"

int main(){
  std::vector<std::string> text = {"aaaaa", "bbbbbbbbb", "cccccccccccc", "ddddddddddddd", "eeeeeeeeeeeeeeee", "fffffffffffffffffffffffffffffffffffffffffffff"};
  huffman h(text);
  h.create_tree();
  std::unordered_map<std::string, std::string> decoded = h.decode();
  for(auto & x : decoded){
    std::cout << x.first << ": ";
    for(auto & y : x.second){
      std::cout << y;
    }
    std::cout << '\n';
  }
}
