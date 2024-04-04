#include "../../third_party/catch.hpp"
#include "../../src/classes/tree/tree.h"

TEST_CASE("testing insertion in tree class [TREECLASS]"){
  tree<int> t;
  t.insert("", 10);
  t.insert("r", 15);
  t.insert("l", 20);

  REQUIRE(t.search(20) == true);
}

TEST_CASE("testing inorder traversal in tree class [TREECLASS]"){
  tree<char> t;
  t.insert("", 'c');
  t.insert("l", 'w');
  t.insert("r", 'd');

  std::vector<char> v = t.inorder();
  std::vector<char> check = {'w','c','d'};
  REQUIRE(check == v);
}

