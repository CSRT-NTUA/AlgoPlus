#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/splay_tree.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing insertion") {
  splay_tree<int> s;
  s.insert(10);
  s.insert(12);
  s.insert(16);
  s.insert(5);
  s.insert(-10);
  s.insert(6);
  std::vector<int> els = s.inorder();
  std::vector<int> check = {-10, 5, 6, 10, 12, 16};
  REQUIRE(els == check);
}
