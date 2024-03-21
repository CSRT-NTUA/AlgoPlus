#include "../../src/classes/tree/interval_tree.h"
#include "../../third_party/catch.hpp"
#include <string>

TEST_CASE("testing insertion in interval tree") {
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

TEST_CASE("testing overlap in interval tree") {
  interval_tree<int> i;
  i.insert({20, 36});
  i.insert({3, 41});
  i.insert({29, 99});
  i.insert({0, 1});
  i.insert({10, 15});
  REQUIRE(i.overlap({20, 36}, {3, 41}) == true);
  REQUIRE(i.overlap({20, 36}, {10, 15}) == false);
}

TEST_CASE("testing remove in interval tree") {
  interval_tree<char> i({{'a', 'b'}, {'c', 'd'}, {'a', 'd'}});
  REQUIRE(i.search({'a', 'b'}) == true);
  i.remove({'a', 'b'});
  REQUIRE(i.search({'a', 'b'}) == false);
  i.remove({'w', 'w'});
  REQUIRE(i.search({'w', 'w'}) == false);
  REQUIRE(i.search({'c', 'd'}));
  REQUIRE(i.search({'a', 'd'}) == true);
}

TEST_CASE("testing iterators in interval tree") {
  interval_tree<int> i({{1, 3}, {5, 6}, {2, 4}, {9, 10}});
  std::vector<std::pair<int, int>> els = i.inorder();
  std::vector<std::pair<int, int>> check;
  for (auto it = i.begin(); it != i.end(); it++) {
    check.push_back(*(it));
  }
  REQUIRE(check == els);
}

TEST_CASE("testing copy constructor for interval_tree class") {
  interval_tree<int> i({{1, 3}, {5, 6}, {2, 4}, {9, 10}});
  interval_tree<int> i2(i);
  REQUIRE(i.inorder() == i2.inorder());
  REQUIRE(i.preorder() == i2.preorder());

  interval_tree<char> i3({{'a', 'b'}, {'c', 'd'}, {'a', 'd'}});
  interval_tree<char> i4(i3);
  REQUIRE(i3.inorder() == i4.inorder());
  REQUIRE(i3.preorder() == i4.preorder());
}

TEST_CASE("testing operator = for interval tree class") {
  interval_tree<int> i({{1, 3}, {5, 6}, {2, 4}, {9, 10}});
  interval_tree<int> i2;
  i2 = i;
  REQUIRE(i.inorder() == i2.inorder());
  REQUIRE(i.preorder() == i2.preorder());
}