#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/interval_tree.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("testing insertion") {
  interval_tree<int> i;
  i.insert({20, 36});
  i.insert({3, 41});
  i.insert({29, 99});
  i.insert({0, 1});
  i.insert({10, 15});
  std::vector<std::pair<int, int>> els = {
      {0, 1}, {3, 41}, {10, 15}, {20, 36}, {29, 99}};
  REQUIRE(i.inorder() == els);
}

TEST_CASE("testing overlap") {
  interval_tree<int> i;
  i.insert({20, 36});
  i.insert({3, 41});
  i.insert({29, 99});
  i.insert({0, 1});
  i.insert({10, 15});
  REQUIRE(i.overlap({20, 36}, {3, 41}) == true);
  REQUIRE(i.overlap({20, 36}, {10, 15}) == false);
}