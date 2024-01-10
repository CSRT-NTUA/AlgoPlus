#define CATCH_CONFIG_MAIN
#include "../../classes/tree/bst.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions and traversals") {
  bst<int> b1;
  bst<char> b2;
  bst<std::string> b3;

  b1.insert(2);
  b1.insert(19);
  b1.insert(5);

  std::vector<int> v = {2, 5, 19};
  std::vector<int> inorder = b1.inorder();
  REQUIRE(v == inorder);

  b2.insert('g');
  b2.insert('k');
  b2.insert('a');

  std::vector<char> _v = {'a', 'g', 'k'};
  std::vector<char> _inorder = b2.inorder();
  REQUIRE(_v == _inorder);

  b3.insert("hello");
  b3.insert("abraham");
  b3.insert("cheers");
  std::vector<std::string> __v = {"abraham", "cheers", "hello"};
  std::vector<std::string> __inorder = b3.inorder();
  REQUIRE(__v == __inorder);
}

TEST_CASE("checking removals") {
  bst<int> b1;
  b1.insert(10);
  b1.insert(2);
  b1.insert(190);
  b1.insert(-20);
  b1.insert(23);

  b1.remove(190);
  std::vector<int> v = {-20, 2, 10, 23};
  std::vector<int> inorder = b1.inorder();
  REQUIRE(v == inorder);
}