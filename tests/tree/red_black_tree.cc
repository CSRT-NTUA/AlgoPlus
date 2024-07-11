#include "../../src/classes/tree/red_black_tree.h"
#include "../../third_party/catch.hpp"
#include <algorithm>

TEST_CASE("Testing red black tree insertion and traversal") {
  red_black_tree<int> rb;

  rb.insert(1);
  rb.insert(2);
  rb.insert(12);
  rb.insert(14);
  rb.insert(89);
  rb.insert(3);
  rb.insert(0);
  rb.insert(12);
  rb.insert(13);
  std::vector<int> expected_inorder = {0, 1, 2, 3, 12, 12, 13, 14, 89};
  std::vector<int> produced_inorder = rb.inorder();
  std::vector<int> expected_preorder = {12, 2, 1, 0, 3, 14, 12, 13, 89};
  std::vector<int> produced_preorder = rb.preorder();
  REQUIRE(expected_inorder == produced_inorder);
  REQUIRE(expected_preorder == produced_preorder);
}

TEST_CASE("Testing red black tree insertion, remove and traversal") {
  red_black_tree<int> rb;

  rb.insert(1);
  rb.insert(2);
  rb.insert(12);
  rb.insert(14);
  rb.insert(89);
  rb.insert(3);
  rb.insert(0);
  rb.insert(12);
  rb.insert(13);
  rb.remove(12);
  rb.remove(14);
  std::vector<int> expected_inorder = {0, 1, 2, 3, 12, 13, 89};
  std::vector<int> produced_inorder = rb.inorder();
  std::vector<int> expected_preorder = {12, 2, 1, 0, 3, 89, 13};
  std::vector<int> produced_preorder = rb.preorder();
  REQUIRE(expected_inorder == produced_inorder);
  REQUIRE(expected_preorder == produced_preorder);
}

TEST_CASE("Testing search in red black tree") {
  red_black_tree<int> rb;

  rb.insert(1);
  rb.insert(2);
  rb.insert(12);
  rb.insert(14);
  rb.insert(89);
  rb.insert(3);
  rb.insert(0);
  rb.insert(12);
  rb.insert(13);
  rb.remove(12);
  rb.remove(14);
  REQUIRE(rb.search(0) == true);
  REQUIRE(rb.search(14) == false);
}

TEST_CASE("Testing iterators in red black tree") {
  red_black_tree<int> rb({1, 2, 12, 14, 89, 3, 0, 13});
  std::vector<int> produced = rb.inorder();
  std::vector<int> check_1;
  for (auto it = rb.begin(); it != rb.end(); it++) {
    check_1.push_back(*(it));
  }

  

  std::vector<int> check_2;
  auto it = rb.end();
  it--;
  for (; it != rb.begin(); it--) {
    check_2.push_back(*(it));
  }
  check_2.push_back(*(it));
  REQUIRE(produced == check_1);
  std::reverse(produced.begin(), produced.end());
  REQUIRE(produced == check_2);
}

TEST_CASE("Testing clear function in red black tree") {
  red_black_tree<int> rb({1, 2, 3, 4, 5, 6});
  rb.clear();
  std::vector<int> produced = rb.inorder();
  REQUIRE(produced.size() == 0);
  REQUIRE(rb.size() == 0);
}

TEST_CASE("Testing size function in red black tree") {
  red_black_tree<int> rb({1, 2, 3, 4, 5, 6});
  REQUIRE(rb.size() == 6);
}

TEST_CASE("Testing operator= in red black tree") {
  red_black_tree<int> rb({1, 2, 3, 4, 5, 6});
  red_black_tree<int> rb2;
  rb2 = rb;
  REQUIRE(rb.inorder() == rb2.inorder());
  REQUIRE(rb.preorder() == rb2.preorder());
}

TEST_CASE("Testing operator== in red black tree") {
  red_black_tree<int> rb({1, 2, 3, 4, 5, 6});
  red_black_tree<int> rb2;
  rb2 = rb;
  REQUIRE(rb2 == rb);
}

TEST_CASE("Testing level order in red black tree") {
  red_black_tree<int> rb({1, 2, 3, 4, 5, 6});
  std::vector<std::vector<int>> produced = rb.level_order();
  std::vector<std::vector<int>> expected = {{2}, {1,4}, {3,5}, {6}};
  REQUIRE(produced == expected);
}